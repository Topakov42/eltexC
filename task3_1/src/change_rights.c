#include "../include/change_rights.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "../include/print_binary.h"
#include "../include/print_letters.h"
#include "../include/read_file_rights.h"
#include "../include/write_console.h"

void change_rights() {
    int rwx;
    struct stat fileInfo;

    printf("Введите название файла, у которого хотите поменять права :\n");

    char *nameFile = write_letters();
    if (stat(nameFile, &fileInfo) == 0) {  // закидывает данные о файле
        rwx = fileInfo.st_mode &
              0777;  // вытаскиваем данные о праве доступа файла и присваиваем к rwx переменой
    } else {
        perror("Error:");  // ошибка если файл не нашли
    }

    printf("Текущие права файла : \n");
    read_file_rights(nameFile);
    free(nameFile);

    printf("Введите новые права в формате 'u+x, g=rwx'\n");
    char *commands = write_letters();

    char validChar[10] = {'r', 'w', 'x', 'a', '-',
                          '+', '=', 'u', 'g', 'o'};  // валидация новых прав
    for (int i = 0; i < strlen(commands); ++i) {
        int found = 0;
        for (int j = 0; j < 10; ++j) {
            if (commands[i] == validChar[j]) {
                found = 1;
                break;
            }
        }
        if (!found || strlen(commands) == 0) {
            printf("Ошибка, неверный аргументов ввод\n");
            break;
        }
    }

    int i = 0;
    int targetMask = 0;

    while (commands[i] == 'u' || commands[i] == 'g' || commands[i] == 'o' ||
           commands[i] == 'a') {  // определяем какие права меняем
        if (commands[i] == 'u') targetMask |= 0700;
        if (commands[i] == 'g') targetMask |= 0070;
        if (commands[i] == 'o') targetMask |= 0007;
        if (commands[i] == 'a') targetMask |= 0777;
        i++;
    }

    if (targetMask == 0) {
        targetMask = 0777;
    }

    char operation = commands[i];

    if (operation != '+' && operation != '-' && operation != '=') {  // валидация знака
        printf("Неверный оператор\n");
        return;
    }
    i++;

    int perm_bits = 0;
    while (commands[i] == 'r' || commands[i] == 'w' || commands[i] == 'x') {  // закидываем вес
        if (commands[i] == 'r') perm_bits |= 4;
        if (commands[i] == 'w') perm_bits |= 2;
        if (commands[i] == 'x') perm_bits |= 1;
        i++;
    }

    int full_perm =
        (perm_bits << 6) | (perm_bits << 3) | perm_bits;  // складываем все в одну переменую
    int final_bits = full_perm & targetMask;  //  накидываем нужную нам маску
    if (operation == '+') {
        rwx |= final_bits;
    } else if (operation == '-') {
        rwx &= ~final_bits;
    } else if (operation == '=') {
        rwx = (rwx & ~targetMask) | final_bits;
    }

    printf("Новые права файла :\n");
    print_letters(rwx);
    printf("Представление в виде числа : %o\n", rwx);
    printf("Представление в бинарном виде : ");
    print_binary(rwx);
    free(commands);
}
