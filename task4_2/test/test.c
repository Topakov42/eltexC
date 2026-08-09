//
// Created by Topa on 07.08.2026.
//

#include "test.h"

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "extract.h"
#include "insert.h"


int main(int argc, char *argv[]) {
    //  создаём очередь
    PriorityQueue *pq = pq_create();
    if (pq == NULL) {
        printf("Ошибка создания очереди\n");
        return 1;
    }

    //  генерируем 50 сообщений
    for (int i = 1; i <= 50; i++) {
        char msg[64];
        snprintf(msg, sizeof(msg), "Message #%d", i);
        uint8_t priority = rand() % 256;
        insert(pq, msg, priority);
    }

    //  показываем очередь
    printf("Очередь: \n");
    print_queue(pq);

    // тестируем извлечение первого
    printf("Вытягивание первого элемента \n");
    extract_first(pq);

    //  тестируем извлечение по точному приоритету
    printf("Извлечение по приоритету 10 \n");
    extract_priority(pq, 10);


    //  тестируем извлечение с приоритетом не выше порога
    printf("Тест с извлечением не ниже 50 \n");
    extract_priority_low(pq, 50);

    //  показываем остаток
    printf("Текущая очередь : \n");
    print_queue(pq);

    //  чистим память
    pq_destroy(pq);
    return 0;
}
