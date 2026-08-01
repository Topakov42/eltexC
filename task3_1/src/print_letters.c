#include "../include/print_letters.h"

#include <stdio.h>

void print_letters (int rights) {
    char rwx[10];

    rwx[0] = (rights & (1 << 8)) ? 'r' : '-';
    rwx[1] = (rights & (1 << 7)) ? 'w' : '-';
    rwx[2] = (rights & (1 << 6)) ? 'x' : '-';

    // Group (биты 5, 4, 3)
    rwx[3] = (rights & (1 << 5)) ? 'r' : '-';
    rwx[4] = (rights & (1 << 4)) ? 'w' : '-';
    rwx[5] = (rights & (1 << 3)) ? 'x' : '-';

    // Others (биты 2, 1, 0)
    rwx[6] = (rights & (1 << 2)) ? 'r' : '-';
    rwx[7] = (rights & (1 << 1)) ? 'w' : '-';
    rwx[8] = (rights & (1 << 0)) ? 'x' : '-';

    // Обязательно закрываем строку в Си
    rwx[9] = '\0';

    printf("Представление в буквенном виде :  %s\n", rwx);



}



