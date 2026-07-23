#include <stdio.h>
int result;

void sum(int a, int b) {
    result = a + b;
    printf("Sum: %d\n", result);
}

void sub(int a, int b) {
    result = a - b;
    printf("Subtract: %d\n", result);
}

void mul(int a, int b) {
    result = a * b;
    printf("Multiply: %d\n", result);
}

void div(int a, int b) {
    if (b == 0) {
        printf("Нельзя делить на ноль\n");
        return;
    }
    result = a / b;
    printf("Division: %d\n", result);
}

int main(void) {

    while (1) {
        printf("Введите число 1: \n");
        int x, y;
        scanf("%d", &x);

        printf("Введите число 2 :\n");
        scanf("%d", &y);

        printf("Выберите операциюю. ");
        printf("Для выхода нажмите q :\n");
        char z;
        scanf(" %c", &z);

        switch (z) {
            case '+':
                sum(x, y);
                break;
            case '-':
                sub(x, y);
                break;
            case '*':
                mul(x, y);
                break;
            case '/':
                div(x, y);
                break;
            case 'q':
                return 0;
            default:
                printf("Введен некоректный знак\n");

        }
    }

    return 0;
}
