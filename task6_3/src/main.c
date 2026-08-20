#include "../include/io_utils.h"
#include "../include/loader.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_FUNCTIONS 10

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Использование: %s <каталог с библиотеками>\n", argv[0]);
        return 1;
    }

    LoadedFunction functions[MAX_FUNCTIONS];

    int count = load_functions(
        argv[1],
        functions,
        MAX_FUNCTIONS
    );

    if (count == 0) {
        printf("Не удалось загрузить функции.\n");
        return 1;
    }

    printf("Загружено функций: %d\n", count);

    while (1) {
        printf("Введите число 1:\n");
        double x = readDouble();

        printf("Введите число 2:\n");
        double y = readDouble();

        printf("Выберите операцию (+, -, *, /). Выход - q:\n");
        char operation = readChar();

        if (operation == 'q') {
            printf("Пока пока!\n");
            break;
        }

        int found = 0;

        for (int i = 0; i < count; i++) {
            if (operation == functions[i].operation) {
                double result = functions[i].function(x, y);

                if (operation == '/' && isnan(result)) {
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

    unload_functions(functions, count);

    return 0;

    }
