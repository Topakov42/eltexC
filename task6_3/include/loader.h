#ifndef LOADER_H
#define LOADER_H

#include <stddef.h>

typedef double (*math_func)(double, double);

typedef struct {
    char operation;
    math_func function;
    void *handle;
} LoadedFunction;

int load_functions(const char *directory,
LoadedFunction *functions,
size_t max_functions);

void unload_functions(LoadedFunction *functions, size_t count);

#endif