#include "../include/network_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include "../include/generate_ip.h"


int main(int argc, char *argv[]) {
    if (argc != 4) {
        // проверка  кол-во аргументов
        printf("Usage: %s <IP> <MASK> <N-pakets>\n", argv[0]);
        return 1;
    }

    uint32_t ip;
    uint32_t mask;
    char *end;

    int n = strtol(argv[3], &end, 10); // получаем кол-во пакетов которые надо создать

    if (*end != '\0') {
        // проверяем число N
        printf("Ошибка ввода кол-во пакетов\n");
        return 1;
    }

    if (n < 1) {
        printf("Ошибка. кол-во пакетов должно быть больше 0\n");
        return 1;
    }

    if (!parse_ip(argv[1], &ip)) {
        // парсим ип
        printf("Invalid IP address\n");
        return 1;
    }

    if (!parse_mask(argv[2], &mask)) {
        // парсим маску
        printf("Invalid mask\n");
        return 1;
    }


    Network my_network; // создаем структуру. ип , маска, сеть

    my_network.ip = ip;
    my_network.mask = mask;
    my_network.network = cal_network(my_network.ip, my_network.mask);


    int own_packets = 0;

    for (long i = 0; i < n; i++) {
        uint32_t destination_ip = generate_ip(); // генерируем ип пакета
        uint32_t destination_network = cal_network(destination_ip, my_network.mask); // узнаем сеть у пакета

        if (destination_network == my_network.network) {
            own_packets++; // добавляем  пакет если в нешй сети
        }
    }
    int foreign_packets = n - own_packets;


    // высчитываем проценты
    double own_percent = (double) own_packets * 100.0 / n;
    double foreign_percent = (double) foreign_packets * 100.0 / n;

    printf("Кол-во попаданий в нашу сеть: %d пакетов (%.2f%%)\n", own_packets, own_percent);

    printf("Кол-во не в нашей сети : %d пакетов  (%.2f%%)\n", foreign_packets, foreign_percent);

    return 0;
}
