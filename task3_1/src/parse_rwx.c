#include "../include/parse_rwx.h"
#include <stdio.h>
#include <string.h>

int parse_rwx(const char *rwx) {
    // // парсим rwx

    int value = 0;
    if (rwx[0] == 'r') {
        // закидываем вес если нашли r
        value |= (1 << 2);
    }
    if (rwx[1] == 'w') {
        // закидываем вес
        value |= (1 << 1);
    }
    if (rwx[2] == 'x') {
        // закидываем вес
        value |= (1 << 0);
    }
    return value;
}


int parse_string_rights(const char *str) {   //  получает строку типа wwwrrrxxx и превращает ее в число

    if (strlen(str) != 9) {
        printf("Ошибка, строка должна иметь 9 символов\n");
        return -1;
    }

    int user = parse_rwx(&str[0]); //берем первые три символа
    int group = parse_rwx(&str[3]); // следующие 3
    int others = parse_rwx(&str[6]); // последние 3

    int total_mode = (user << 6) | (group << 3) | others; // группируем числа

    return total_mode;   // возвращает число типа 462
}






