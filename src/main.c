#include "../include/io_utils.h"
#include "../include/math_ops.h"
#include <stdio.h>
#include <math.h>


int main(void) {
    Operations operations[] = {
        {'+', sum},
        {'-', sub},
        {'*', mul},
        {'/', divv}
    };

    int sizeArray = sizeof(operations) / sizeof(operations[0]);

    while (1) {
        printf("Введите число 1:\n");
        double x = readDouble();

        printf("Введите число 2:\n");
        double y = readDouble();


        printf("Выберите операцию (+, -, *, /). Выход - q:\n");
        char z = readChar();
        if (z == 'q') {
            printf("Пока пока!\n");
            return 0;
        }
        int found = 0;
        for (int i = 0; i < sizeArray; i++) {
            if (z == operations[i].name) {
                double result = operations[i].op(x, y);
                if (z == '/' && isnan(result)) {
                    printf("На ноль делить нельзя\n");
                } else {
                    printf("Результат: %lf\n", result);
                }
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Некорректная операция!\n");
        }
    }
}
