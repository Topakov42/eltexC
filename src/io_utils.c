#include "../include/io_utils.h"
#include <stdio.h>
#include <stdlib.h>


char readChar() {
    char buf[100];
    fgets(buf, sizeof(buf), stdin);
    return buf[0];
}

double readDouble() {
    char buf[100];
    char *endptr;
    double value;
    while (1) {
        fgets(buf, sizeof(buf), stdin);
        value = strtod(buf, &endptr);
        if (endptr == buf && *endptr != '\n' && *endptr != '\0') {
            printf("Ошибка: введите число\n");
            continue;
        }
        if (*endptr != '\n' && *endptr != '\0') {
            while (*endptr == ' ' || *endptr == '\t') {
                endptr++;
            }
        }
        return value;
    }
}
