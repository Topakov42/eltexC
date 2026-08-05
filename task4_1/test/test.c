#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../include/list.h"


void add_test_contact(ContactList *list, char *last, char *first, char *mid, char *work, char *num, char *mail) {
    insert_sorted(list, last, first, mid, work, num, mail);
}



// Тест 2: Вставка одного контакта
void test_insert_single() {
    printf(" Проверка вставки контакта : ");
    ContactList *list = create_list();
    
    add_test_contact(list, "Путин", "Владимир", "Владимирович", "Президент", "+79991234567", "putin@mail.ru");
    
    assert(list->size == 1);
    assert(list->head != NULL);
    assert(list->head == list->tail); // один элемент - голова и хвост одно и то же
    assert(strcmp(list->head->lastName, "Путин") == 0);
    assert(strcmp(list->head->work, "Президент") == 0);
    
    free_list(list);
    printf("OK\n");
}

//  Удаление из середины списка
void test_remove_middle() {
    printf(" Проверка удаления среднего элемента... ");
    ContactList *list = create_list();
    
    add_test_contact(list, "Андропов", "Юрий", "Владимирович", "Генсек", "+70000000003", "andropov@mail.ru");
    add_test_contact(list, "Берия", "Лаврентий", "Павлович", "Нарком", "+70000000002", "beria@mail.ru");
    add_test_contact(list, "Ягода", "Генрих", "Григорьевич", "Нарком", "+70000000001", "yagoda@mail.ru");
    

    Node *middle = list->head->next;  // Удаляем 2 контакт
    remove_node(list, middle);
    
    assert(list->size == 2);
    assert(strcmp(list->head->lastName, "Андропов") == 0);
    assert(strcmp(list->tail->lastName, "Ягода") == 0);
    assert(strcmp(list->head->next->lastName, "Ягода") == 0);
    assert(strcmp(list->tail->prev->lastName, "Андропов") == 0);
    
    free_list(list);
    printf("OK\n");
}

//  Удаление головы
void test_remove_head() {
    printf(" Проверка удаления головы списка... ");
    ContactList *list = create_list();
    
    add_test_contact(list, "Брежнев", "Леонид", "Ильич", "Генсек", "+70000000004", "brezhnev@mail.ru");
    add_test_contact(list, "Хрущёв", "Никита", "Сергеевич", "Генсек", "+70000000005", "hrushchev@mail.ru");
    

    remove_node(list, list->head);
    
    assert(list->size == 1);
    assert(strcmp(list->head->lastName, "Хрущёв") == 0);
    assert(list->head->prev == NULL);
    assert(list->head == list->tail);
    
    free_list(list);
    printf("OK\n");
}

void test_get_by_index() {  // Проверка на получение индекса
    printf("Проверка поиска по индексу... ");
    ContactList *list = create_list();
    
    add_test_contact(list, "Сталин", "Иосиф", "Виссарионович", "Генсек", "+70000000006", "stalin@mail.ru");
    add_test_contact(list, "Ленин", "Владимир", "Ильич", "Предсовнаркома", "+70000000007", "lenin@mail.ru");
    add_test_contact(list, "Медведев", "Дмитрий", "Анатольевич", "Президент", "+70000000008", "medvedev@mail.ru");
    
    Node *node = get_node_by_index(list, 2);
    assert(node != NULL);
    assert(strcmp(node->lastName, "Медведев") == 0);
    
    node = get_node_by_index(list, 1);
    assert(strcmp(node->lastName, "Ленин") == 0);
    
    // Проверка невалидного индекса
    assert(get_node_by_index(list, 0) == NULL);
    assert(get_node_by_index(list, 999) == NULL);
    
    free_list(list);
    printf("OK\n");
}

int main() {
    printf("Запуск юнит-тестов списка\n");
    printf("______________________________\n");
    
    test_insert_single();
    test_remove_middle();
    test_remove_head();
    test_get_by_index();
    
    printf("_______________________\n");
    printf("Все тесты пройдены успешно!\n");
    return 0;
}