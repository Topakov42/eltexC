#ifndef MATH_OPS_H
#define MATH_OPS_H




typedef double (*math_func)(double, double);

typedef struct {
    char name;
    math_func op;
} Operations;


double sum(double a, double b);
double sub(double a, double b);
double mul(double a, double b);
double divv(double a, double b);

#endif