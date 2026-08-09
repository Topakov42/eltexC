//
// Created by Topa on 07.08.2026.
//

#ifndef TASK4_2_QUEUE_H
#define TASK4_2_QUEUE_H
#include <stddef.h>
#include <stdint.h>

typedef struct Node {
    char *data; // данные
    uint8_t priority; // приоритет
    struct Node *next; // указатель на след элемент
} Node;


typedef struct {
    // управление очередью
    Node *head; // первый элемент очереди
    size_t size; // сколько всего элементов
} PriorityQueue;

void print_queue(const PriorityQueue *pq);  // печать очереди
void pq_destroy(PriorityQueue *pq); // отчистка очереди
PriorityQueue *pq_create(void); // создания очереди


#endif //TASK4_2_QUEUE_H
