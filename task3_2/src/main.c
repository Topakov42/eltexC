#include <stdint.h>
#include <stdio.h>
#include <arpa/inet.h>
#include "../include/network_utils.h"

int main(int argc, char *argv[]) {

    int x = cal_broadcast(12,12);

    uint32_t gateway_ip;
    uint32_t mask;
    int packets;


    int result = inet_pton(AF_INET, argv[1], &gateway_ip);

    if (result != 1) {
        printf("Ошибка: Введена некорректная строка\n");
        return 0;
    }


    return 0;
}
