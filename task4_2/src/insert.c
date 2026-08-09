#include <stdio.h>
#include "../include/insert.h"
#include <stdlib.h>
#include <string.h>


int insert(PriorityQueue *pq, const char *data, uint8_t priority) {
    if (pq == NULL || data == NULL) {
        // проверка на пустые данные \ существование очереди
        printf("Ошибка. Строка / данные пустые \n");
        return 0; // ошибка
    }

    Node *node = (Node *) malloc(sizeof(Node)); // выделяем память
    if (node == NULL) {
        printf("Ошибка создания элемента очереди \n");
        free(node);
        return 0;
    }
    

    node->data = strdup(data); // копируем данные
    if (node->data == NULL) {
        free(node);
        printf("Ошибка копирования данных \n");
        return 0;
    }
    node->priority = priority;

    if (pq->head == NULL) {  // если очередь пустая
        pq->head = node;
        node->next = NULL;
        pq -> size++;
        return 1;
    } else if (priority < pq->head->priority) {  // если наш вставляемый элемент имеет приоритет выше чем глова
        node->next = pq->head;
        pq->head = node;
        pq -> size++;
        return 1;
    } else {
        Node *current = pq->head;
        while (current->next != NULL && current->next->priority <= priority) {
            // перебираем нашу очередь для поиска места для вставки
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
        pq -> size++;
        return 1;
    }
}
