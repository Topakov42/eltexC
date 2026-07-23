#include "../include/io_utils.h"  // Нам нужен ввод
#include "../include/math_ops.h"  // Нам нужна математика
#include <stdio.h>                // Нам нужен printf

int main(void) {
    while (1) {
        printf("Vedite chislo 1:\n");
        int x = readInt(); // Как работает readInt? main.c не знает! Это скрыто в io_utils.c

        printf("Vedite chislo 2:\n");
        int y = readInt();

        printf("Vibirite oper (+, -, *, /). Exit - q:\n");
        char z = readChar();

        switch (z) {
            case '+': sum(x, y); break;
            case '-': sub(x, y); break;
            case '*': mul(x, y); break;
            case '/': divv(x, y); break;
            case 'q':
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Nekooret znak vveden\n");
        }
    }
}