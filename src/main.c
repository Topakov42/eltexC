#include "../include/io_utils.h"
#include "../include/math_ops.h"
#include <stdio.h>
#include <math.h>


int main(void) {
    while (1) {
        printf("Vedite chislo 1:\n");
        double x = readDouble();

        printf("Vedite chislo 2:\n");
        double y = readDouble();

        printf("Vibirite oper (+, -, *, /). Exit - q:\n");
        char z = readChar();

        switch (z) {
            case '+':
                printf("Sum: %lf\n", sum(x, y));
                break;
            case '-':
                printf("Sub: %lf\n", sub(x, y));
                break;
            case '*':
                printf("Mul: %lf\n", mul(x, y));
                break;
            case '/':
                double res = divv(x, y);
                if (isnan(res)) {
                    printf("Nylzua del na nol\n");
                } else {
                    printf("Division: %lf\n", res);
                }
                break;
            case 'q':
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Nekooret znak vveden\n");
        }
    }
}
