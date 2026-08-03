#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "../include/parse_rwx.h"

void test_parse_rwx() {
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

void test_parse_string_rights() {
    assert(parse_string_rights("rwxr-xr-x") == 0755);
    assert(parse_string_rights("rwxrwxrwx") == 0777);
    assert(parse_string_rights("---------") == 0000);
    assert(parse_string_rights("r--r--r--") == 0444);
    printf("Тесты с введенными некоррктными данными :\n");
    assert(parse_string_rights("rwx") == -1 );
    assert(parse_string_rights("rwxrwxrwxrwx") == -1);
    assert(parse_string_rights("") == -1);
    assert(parse_string_rights("rwxrzx4x-") == -1);
    assert(parse_string_rights("rwxrwjrw-") == -1);

    printf("test parse_string_rights прошел успешно!\n");
}

int main(void) {
    printf(" Запуск тестов \n");
    test_parse_rwx();
    test_parse_string_rights();

    printf("Тест завершен\n");
    return 0;
}
