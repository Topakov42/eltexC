#include "../include/queue.h"
#include <stdio.h>
#include <stdlib.h>

void print_queue(const PriorityQueue *pq) {
    // печать очереди

    if (pq == NULL) {
        printf("Очередь не существует\n");
        return;
    }

    if (pq->head == NULL) {
        printf("Очередь пуста\n");
        return;
    }

    Node *current = pq->head;
    int index = 1;
    while (current != NULL) {
        printf("%d. [Приоритет: %3u] %s\n", index, current->priority, current->data);
        current = current->next;
        index++;
    }
}


void pq_destroy(PriorityQueue *pq) {
    // отчистка очереди
    if (pq == NULL) return;

    Node *current = pq->head;

    while (current != NULL) {
        Node *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    free(pq);
}

PriorityQueue *pq_create(void) { // создания очереди

    PriorityQueue *pq = (PriorityQueue *) malloc(sizeof(PriorityQueue));

    if (pq == NULL) {
        printf("Ошибка создания очереди \n");
        return NULL;
    }

    pq->head = NULL;
    pq->size = 0;

    return pq;
}
