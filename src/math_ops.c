#include "../include/math_ops.h"
#include <stdio.h>
#include <math.h>

double sum(double a, double b) {
    return a + b;
}

double sub(double a, double b) {
    return a - b;
}

double mul(double a, double b) {
    return a * b;
}

double divv(double a, double b) {
    if (b == 0.0) {
        return NAN;  // проверка делятеля на 0
    }
    return a / b;
}
