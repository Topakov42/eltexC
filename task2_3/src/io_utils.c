#include "../include/io_utils.h"
#include <stdio.h>
#include <stdlib.h>


char readChar() {
    char buf[10];
    fgets(buf, sizeof(buf), stdin);
    return buf[0];
}



double readDouble() {
    char buf[100]; //создаем буфер для нашего будущего числа
    char *endptr; // создамем маячок
    double value; // объявляем переменую которую потом вернем
    while (1) {
        // запускаем цикл для ввода переменной \ проверки этой пер
        fgets(buf, sizeof(buf), stdin); // с помощью функции fgets
        value = strtod(buf, &endptr); // записываем данные с массива  в переменую


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

        return value;
    }
}
