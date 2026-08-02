#include "../include/change_rights.h"
#include "../include/write_console.h"
#include <stdio.h>
#include <stdlib.h>
#include "../include/print_letters.h"
#include "../include/read_file_rights.h"
#include <sys/stat.h>
#include  "../include/print_binary.h"

void change_rights() {
    printf("Введите название файла, у которого хотите поменять права :\n");
    char *nameFile = write_letters();
    printf("Текущие права файла : \n");
    read_file_rights(nameFile);
    struct stat fileInfo;
    int rwx;

    if (stat(nameFile, &fileInfo) == 0) {
        rwx = fileInfo.st_mode & 0777;
    }

    free(nameFile);

    printf("Введите новые права в формате 'u+x, g=rwx'\n");

    char *commands = write_letters();

    int i = 0;
    int targetMask = 0;

    while (commands[i] == 'u' || commands[i] == 'g' || commands[i] == 'o' || commands[i] == 'a') {
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

    if (operation != '+' && operation != '-' && operation != '=') {
        printf("Неверный оператор\n");
        return;
    }
    i++;


    int perm_bits = 0;
    while (commands[i] == 'r' || commands[i] == 'w' || commands[i] == 'x') {
        if (commands[i] == 'r') perm_bits |= 4;
        if (commands[i] == 'w') perm_bits |= 2;
        if (commands[i] == 'x') perm_bits |= 1;
        i++;
    }


    int full_perm = (perm_bits << 6) | (perm_bits << 3) | perm_bits;
    int final_bits = full_perm & targetMask;

    if (operation == '+') {
        rwx |= final_bits;
    } else if (operation == '-') {
        rwx &= ~final_bits;
    } else if (operation == '=') {
        rwx = (rwx & ~targetMask) | final_bits;
    }

    printf("Новый права файла :\n");
    print_letters(rwx);
    printf("Представление в виде числа : %o\n", rwx);
    printf("Предсатвление в бинарном виде : ");
    print_binary(rwx);
    free(commands);
}
