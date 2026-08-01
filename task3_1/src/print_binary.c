#include "../include/print_binary.h"
#include <stdio.h>

void print_binary(int number) {
    for (int i = 8; i >= 0; i--) {
        if (number & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
        if (i == 6 || i == 3) {
            printf(" ");
        }
    }
    printf("\n");
}
