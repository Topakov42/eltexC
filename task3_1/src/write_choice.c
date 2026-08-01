#include "../include/write_choice.h"
#include <stdio.h>
#include <stdlib.h>

int write_choice() {
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
