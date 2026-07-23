#include "../include/math_ops.h"
#include <stdio.h>

void sum(double a, double b) {
    double result = a + b;
    printf("Sum: %lf\n", result);
}

void sub(double a, double b) {
    double result = a - b;
    printf("Subtract: %lf\n", result);
}

void mul(double a, double b) {
    double result = a * b;
    printf("Multiply: %.5lf\n", result);
}

void divv(double a, double b) {
    if (b == 0.0) {
        printf("Nylzua del na nol\n");
        return;
    }
    double result = a / b;
    printf("Division: %.5lf\n", result);
}
