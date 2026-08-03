#ifndef TASK3_2_NETWORK_UTILS_H
#define TASK3_2_NETWORK_UTILS_H
#include <stdint.h>

typedef struct {
    uint32_t ip;
    uint32_t mask;
    uint32_t network;
} Network;

int parse_ip(const char *str, uint32_t *ip);

int validate_mask(uint32_t mask);

int parse_mask(const char *str, uint32_t *mask);

uint32_t cal_network(uint32_t ip, uint32_t mask);

#endif //TASK3_2_NETWORK_UTILS_H
