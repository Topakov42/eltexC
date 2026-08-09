#include "../include/extract.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int extract_first(PriorityQueue *pq) {
    // извлечение первого элемента

    if (pq == NULL) {
        return 0; // ошибка: очередь пуста
    }
    Node *node = pq->head;
    pq->head = node->next;

    printf("Извлечено: [Prio: %u] %s\n", node->priority, node->data);

    free(node->data);
    free(node);
    pq->size--;

    return 1;
}


int extract_priority(PriorityQueue *pq, uint8_t priority) {
    if (pq == NULL || pq->head == NULL) {
        printf("Очередь пуста\n");
        return 0;
    }

    if (priority < 0 || priority > 255) {
        printf("Некорректный приоритет\n");
        return 0;
    }

    Node *current = pq->head;

    if (current->priority == priority) {
        // если приоритет в голове

        printf("Извлечено: [Prio: %u] %s\n", current->priority, current->data);
        pq->head = current->next;
        free(current->data);
        free(current);
        pq->size--;
        return 1;
    }


    while (current->next != NULL) {
        // переираем очередь и ищем подходящий приоритет
        if (current->next->priority == priority) {
            Node *target = current->next;
            printf("Извлечено: [Prio: %u] %s\n", target->priority, target->data);

            current->next = target->next;

            free(target->data);
            free(target);
            pq->size--;
            return 1;
        }
        current = current->next;
    }

    printf("Ошибка. элемента с приоритетом %d нету\n", priority);
    return 0;
}

int extract_priority_low(PriorityQueue *pq, uint8_t priority) {
    if (pq == NULL || pq->head == NULL) {
        printf("Очередь пуста\n");
        return 0;
    }


    Node *current = pq->head;

    if (current->priority <= priority) {
        // если приоритет в голове

        printf("Извлечено: [Prio: %u] %s\n", current->priority, current->data);
        pq->head = current->next;
        free(current->data);
        free(current);
        pq->size--;
        return 1;
    }

    // Ищем в остальной части

    while (current->next != NULL) {

        if (current->next->priority <= priority) {

            Node *target = current->next;

            printf("Извлечено: [Prio: %u] %s\n", target->priority, target->data);
            current->next = target->next;

            free(target->data);
            free(target);

            pq->size--;
            return 1;
        }
        current = current->next;
    }

    printf("Ошибка. элемента с приоритетом не ниже %d  \n", priority);

    return 0;
}
