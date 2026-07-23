#include "../include/io_utils.h"
#include "../include/math_ops.h"
#include <stdio.h>


int main(void) {
    while (1) {
        printf("Vedite chislo 1:\n");
        double x = readDouble();

        printf("Vedite chislo 2:\n");
        double y = readDouble();

        printf("Vibirite oper (+, -, *, /). Exit - q:\n");
        char z = readChar();

        switch (z) {
            case '+': sum(x, y);
                break;
            case '-': sub(x, y);
                break;
            case '*': mul(x, y);
                break;
            case '/': divv(x, y);
                break;
            case 'q':
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Nekooret znak vveden\n");
        }
    }
}
