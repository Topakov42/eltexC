#include <stdio.h>

void print_binary(int mode) {

    for (int i = 8; i >= 0; i--) {

        if (mode & (1 << i)) {
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






int main(void) {

int mode = 0146;
    print_binary(mode);
    return 0;
}