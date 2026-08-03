#include "../include/network_utils.h"
#include <stdio.h>
#include <arpa/inet.h>


int parse_ip(const char *str, uint32_t *ip) {
    // проверяем что ип корректный и парсим его
    struct in_addr addr;
    if (inet_pton(AF_INET, str, &addr) != 1) {
        printf("Ошибка IP\n");
        return 0;
    }
    *ip = ntohl(addr.s_addr);
    return 1;
}


int parse_mask(const char *str, uint32_t *mask) {
    // парсим маску + валидация {
    struct in_addr addr;
    int result = inet_pton(AF_INET, str, &addr);


    if (result != 1) {
        printf("Ошибка в преобразовании mask\n");
        return 0;
    }

    *mask = ntohl(addr.s_addr);
    if (validate_mask(*mask) != 1) {
        printf("Ошибка в написании mask\n");
        return 0;
    }
    return 1;
}


int validate_mask(uint32_t mask) {
    // Валидация маски на корректность. + проверяем что есть хотя бы 1 свободный бит под устройства
    int found_zero = 0;
    int count = 0;
    for (int i = 31; i >= 0; i--) {
        if (mask & (1u << i)) {
            count++;
        }
        if ((mask & (1u << i)) == 0) {
            found_zero = 1;
        } else if (found_zero) {
            return 0;
        }
    }
    if (count >= 31 ) {
        return 0;
    }
    return 1;
}

uint32_t cal_network(uint32_t ip, uint32_t mask) {
    // адрес нашей подсети
    return ip & mask;
}

