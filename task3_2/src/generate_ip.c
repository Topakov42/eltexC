#include "../include/generate_ip.h"

#include <stdlib.h>
#include <stdint.h>

uint32_t generate_ip() {
    uint8_t a = rand() % 256;
    uint8_t b = rand() % 256;
    uint8_t c = rand() % 256;
    uint8_t d = rand() % 256;
    return build_ip(a, b, c, d);
}


uint32_t build_ip(uint8_t a, uint8_t b, uint8_t c, uint8_t d) {
    return ((uint32_t) a << 24) | ((uint32_t) b << 16) | ((uint32_t) c << 8) | (uint32_t) d;
}
