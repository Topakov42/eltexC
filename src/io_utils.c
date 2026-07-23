#include "../include/io_utils.h"
#include <stdio.h>
#include <stdlib.h>


char readChar() {
    char buf[100];
    fgets(buf, sizeof(buf), stdin);
    return buf[0];
}

double readDouble() {
    char buf[100];
    char *endptr;
    double value;
    while (1) {
        fgets(buf, sizeof(buf), stdin);
        value = strtod(buf, &endptr);

        // 1. Если strtod вообще не нашла цифр (ввели пустой Enter или "abc")
        if (endptr == buf) {
            printf("Ошибка: введите число\n");
            continue;
        }

        // 2. ТВОЯ ФИШКА: пропускаем пробелы и табы после числа
        while (*endptr == ' ' || *endptr == '\t') {
            endptr++;
        }

        // 3. НОВАЯ ЗАПЛАТКА: после пробелов маячок должен быть на конце строки!
        // Если он на букве (мусор) - отбиваем!
        if (*endptr != '\n' && *endptr != '\0') {
            printf("Некорректный ввод числа, введите число!\n");
            continue;
        }

        // 4. Если прошли все 3 проверки - чисто!
        return value;
    }
}