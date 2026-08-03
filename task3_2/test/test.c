#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>

#include "../include/generate_ip.h"
#include "../include/network_utils.h"

void test_build_ip() {
    // тест сборки ип
    uint32_t ip = build_ip(192, 168, 1, 1);

    struct in_addr addr;
    addr.s_addr = htonl(ip);
    char str_buf[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &addr, str_buf, INET_ADDRSTRLEN);

    assert(strcmp(str_buf, "192.168.1.1") == 0);
    printf("test build_ip прошел успешно!\n");
    printf("_____________________\n");
}

void test_cal_network() {
    uint32_t ip, mask;
    parse_ip("192.168.1.50", &ip);
    parse_mask("255.255.255.0", &mask);

    uint32_t network = cal_network(ip, mask);
    uint32_t expected_network;
    parse_ip("192.168.1.0", &expected_network);

    assert(network == expected_network); // проверка корректности сборки сети
    printf("test cal_network прошел успешно!\n");
    printf("_____________________\n");
}

void test_validate_mask() {
    uint32_t valid_mask1, valid_mask2, invalid_mask1, invalid_mask2;
    parse_mask("255.255.255.0", &valid_mask1);
    parse_mask("255.255.0.0", &valid_mask2);
    assert(validate_mask(valid_mask1) == 1);
    assert(validate_mask(valid_mask2) == 1);
    printf("Проверка некорерктности маски :\n");
    parse_mask("255.255.254.1", &invalid_mask1); // проверка корректности маски
    parse_mask("255.255.255.255", &invalid_mask2);

    assert(validate_mask(invalid_mask1) == 0);
    assert(validate_mask(invalid_mask2) == 0);

    printf(" test validate_mask прошел успешно!\n");
    printf("_____________________\n");
}

void test_parse_ip_and_mask() {
    uint32_t ip;
    assert(parse_ip("10.0.0.1", &ip) == 1); // парсинг ип
    printf("Парспинг некорректного ип :\n");
    assert(parse_ip("999.999.999.999", &ip) == 0); // парсинг некорректного ип
    assert(parse_ip("abc.def.ghi.jkl", &ip) == 0);


    printf(" test parse_ip_and_mask прошел успешно!\n");
    printf("_____________________\n");
}

int main(void) {
    printf("Запуск тестов\n");

    test_build_ip();
    test_cal_network();
    test_validate_mask();
    test_parse_ip_and_mask();
    printf("_____________________\n");
    printf("Test - ok");
    return 0;
}
