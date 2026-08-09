#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "extract.h"
#include "insert.h"
#include "write_console.h"


int main(int argc, char *argv[]) {
    //  создаём очередь
    PriorityQueue *pq = pq_create();

    for (int i = 0; i < 100; i++) {
        char msg[256];
        uint8_t priority = rand() % 256;
        snprintf(msg, sizeof(msg), "Этот элемент имеет приоритет %d", priority);
        insert(pq, msg, priority);
    }


    printf("В очередь помещено 100 элементов  \n");



    while (1) {
        printf("Выберите действие  \n");
        printf("1) Добавить элемент   \n");
        printf("2) Взять первый элемент   \n");
        printf("3) Взять элемент с приоритетом    \n");
        printf("4) Взять элемент с приоритетом не ниже заданного   \n");
        printf("5) Показать очередь    \n");
        printf("6) Выйти из программы    \n");

        int choice = write_number();

switch (choice) {
            case 1: {
                // Добавить элемент
                char msg[256];
                uint8_t priority;
                printf("Введите приоритет (0-255): ");
                priority = write_number();
                if (priority > 255) {
                    printf("Ошибка: приоритет должен быть 0-255\n");
                    break;
                }
                snprintf(msg, sizeof(msg), "Этот элемент имеет приоритет %d", priority);
                if (insert(pq, msg, priority)) {
                    printf("Элемент добавлен\n");
                } else {
                    printf("Ошибка добавления\n");
                }
                break;
            }
            case 2: {
                // Взять первый элемент
                if (extract_first(pq)) {
                    printf("Первый элемент извлечён\n");
                } else {
                    printf("Очередь пуста\n");
                }
                break;
            }
            case 3: {
                // Взять элемент с точным приоритетом
                uint8_t priority;
                printf("Введите приоритет для поиска (0-255): ");
                priority = write_number();
                if (priority > 255) {
                    printf("Ошибка: приоритет должен быть 0-255\n");
                    break;
                }
                if (!extract_priority(pq, priority)) {
                    printf("Элемент с приоритетом %d не найден\n", priority);
                }
                break;
            }
            case 4: {
                // Взять элемент с приоритетом не выше порога
                uint8_t threshold;
                printf("Введите порог (0-255): ");
                threshold = write_number();
                if (threshold > 255) {
                    printf("Ошибка: порог должен быть 0-255\n");
                    break;
                }
                if (!extract_priority_low(pq, threshold)) {
                    printf("Элемент с приоритетом <= %d не найден\n", threshold);
                }
                break;
            }
            case 5: {
                // Показать очередь
                print_queue(pq);
                break;
            }
            case 6: {
                // Выйти
                printf("Выход из программы...\n");
                pq_destroy(pq);
                return 0;
            }
            default: {
                printf("Неверный выбор. Попробуйте снова.\n");
                break;
            }
        }
    }

    return 0;
}