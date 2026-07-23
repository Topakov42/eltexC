#include "../include/io_utils.h"
#include <stdio.h>
#include <stdlib.h> f

int readInt() {
    char buf[100];
    fgets(buf, sizeof(buf), stdin);
    return atoi(buf);
}

char readChar() {
    char buf[100];
    fgets(buf, sizeof(buf), stdin);
    return buf[0];
}

double readDouble() {
    char buf[100];
    fgets(buf, sizeof(buf), stdin);
    return atof(buf);
}