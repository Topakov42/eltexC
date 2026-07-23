#include "../include/math_ops.h"
#include <stdio.h>

void sum(int a, int b) {
    int result = a + b;
    printf("Sum: %d\n", result);
}

void sub(int a, int b) {
    int result = a - b;
    printf("Subtract: %d\n", result);
}

void mul(int a, int b) {
    int result = a * b;
    printf("Multiply: %d\n", result);
}

void divv(int a, int b) {
    if (b == 0) {
        printf("Nylzua del na nol\n");
        return;
    }
    int result = a / b;
    printf("Division: %d\n", result);
}