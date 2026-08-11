#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "../include/change_rights.h"
#include "../include/parse_rwx.h"

void test_parse_rwx(void) {
    assert(parse_rwx("rwx") == 7);
    assert(parse_rwx("rw-") == 6);
    assert(parse_rwx("r-x") == 5);
    assert(parse_rwx("r--") == 4);
    assert(parse_rwx("-wx") == 3);
    assert(parse_rwx("-w-") == 2);
    assert(parse_rwx("--x") == 1);
    assert(parse_rwx("---") == 0);
    printf("test parse_rwx прошел успешно!\n");
}

void test_parse_string_rights(void) {
    assert(parse_string_rights("rwxr-xr-x") == 0755);
    assert(parse_string_rights("rwxrwxrwx") == 0777);
    assert(parse_string_rights("---------") == 0000);
    assert(parse_string_rights("r--r--r--") == 0444);
    printf("Тесты с введенными некорректными данными :\n");
    assert(parse_string_rights("rwx") == -1);
    assert(parse_string_rights("rwxrwxrwxrwx") == -1);
    assert(parse_string_rights("") == -1);
    assert(parse_string_rights("rwxrzx4x-") == -1);
    assert(parse_string_rights("rwxrwjrw-") == -1);

    printf("test parse_string_rights прошел успешно!\n");
}

void test_apply_chmod(void) {
    // 1. Тесты на сброс прав с нескольких категорий (go-rx)
    // Исходные: 0777 (rwxrwxrwx) -> go-rx -> 0722 (rwx-w--w-)
    assert(apply_chmod(0777, "go-rx") == 0722);

    // 2. Тесты на точную установку прав для двух категорий (ug=wx)
    // Исходные: 0777 (rwxrwxrwx) -> ug=wx -> 0337 (-wx-wxrwx)
    assert(apply_chmod(0777, "ug=wx") == 0337);

    // 3. Тесты с одиночными флагами и всеми категориями (a)
    // Исходные: 0644 (rw-r--r--) -> u+x -> 0744 (rwxr--r--)
    assert(apply_chmod(0644, "u+x") == 0744);

    // Исходные: 0777 (rwxrwxrwx) -> a-w -> 0555 (r-xr-xr-x)
    assert(apply_chmod(0777, "a-w") == 0555);

    // Исходные: 0000 (---------) -> go+r -> 0044 (---r--r--)
    assert(apply_chmod(0000, "go+r") == 0044);

    // Исходные: 0755 (rwxr-xr-x) -> u=rw -> 0655 (rw-r-xr-x)
    assert(apply_chmod(0755, "u=rw") == 0655);

    // 4. Тесты с некорректным вводом
    assert(apply_chmod(0777, "go--rx") == -1);
    assert(apply_chmod(0777, "invalid") == -1);
    assert(apply_chmod(0777, "") == -1);

    printf("test apply_chmod (go-rx, ug=wx и др.) прошел успешно!\n");
}

int main(void) {
    printf(" Запуск тестов \n");
    test_parse_rwx();
    test_parse_string_rights();
    test_apply_chmod();

    printf("Все тесты успешно завершены!\n");
    return 0;
}