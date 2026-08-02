#include "../include/write_console.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int write_number() {
    int choice;
    char *endptr;
    char buf[100];
    while (1) {
        fgets(buf, sizeof(buf), stdin);
        choice = strtol(buf, &endptr, 10);
        if (endptr == buf) {
            //   проверяем что в массиве вообще есть числа
            printf("Ошибка: введите число\n");
            continue;
        }
        while (*endptr == ' ' || *endptr == '\t') {
            // пропускаем знаки табуляции
            endptr++;
        }
        if (*endptr != '\n' && *endptr != '\0') {
            // првоеряем что после числа, нет букв
            printf("Некорректный ввод числа, введите число!\n");
            continue;
        }
        return choice;
    }
}

char *write_letters() {
    char *str = malloc(100); // выделяем память в куче
    fgets(str, 100, stdin);
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
    //используем free в месте, где вызвали write_letters
    return str;
}
