#include "../include/io_utils.h"
#include "../include/math_ops.h"
#include <stdio.h>
#include <math.h>


int main(void) {
    while (1) {
        printf("Введите число 1:\n");
        double x = readDouble();

        printf("Введите число 2:\n");
        double y = readDouble();

        printf("Выберите операцию (+, -, *, /). Выход - q:\n");
        char z = readChar();

        switch (z) {
            case '+':
                printf("Сумма: %lf\n", sum(x, y));
                break;
            case '-':
                printf("Разность: %lf\n", sub(x, y));
                break;
            case '*':
                printf("Умножение : %lf\n", mul(x, y));
                break;
            case '/':
                double res = divv(x, y);
                if (isnan(res)) {
                    printf("Нельзя делить на ноль\n");
                } else {
                    printf("Частное: %lf\n", res);
                }
                break;
            case 'q':
                printf("Пока, пока !\n");
                return 0;
            default:
                printf("Некорректный знак введен\n");
        }
    }
}
