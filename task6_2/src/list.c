#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/list.h"

// Создание пустого списка
ContactList* create_list() {
    ContactList *list = (ContactList*)malloc(sizeof(ContactList));
    if (list != NULL) {
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;
    }
    return list;
}

// Вставка с сохранением порядка (сортировка по фамилии)
void insert_sorted(ContactList *list, char *lastName, char *firstName, char *midName, char *work, char *number, char *mail) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return;

    newNode->lastName = strdup(lastName);
    newNode->firstName = strdup(firstName);
    newNode->midName = strdup(midName);
    newNode->work = strdup(work);
    newNode->number = strdup(number);
    newNode->mail = strdup(mail);
    newNode->prev = NULL;
    newNode->next = NULL;

    // Если список пустой
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    }
    // Вставка в начало (если новый элемент меньше головы)
    else if (strcmp(newNode->lastName, list->head->lastName) < 0) {  // вставка контакта в начало списка , по сортировке фамилии
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
    // Вставка в середину или конец
    else {
        Node *current = list->head;
        while (current->next != NULL && strcmp(current->next->lastName, newNode->lastName) < 0) {  // перебираем список и ищем куда можно вставить контак ( так же сортировка по фамилии)
            current = current->next;
        }

        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL) {
            current->next->prev = newNode;
        } else {
            list->tail = newNode;
        }
        current->next = newNode;
    }
    list->size++;  // увеличиваем размер списка 
}

// Получение узла по индексу
Node* get_node_by_index(ContactList *list, int index) {
    if (index < 1 || list->head == NULL) return NULL;

    Node *current = list->head;
    int current_index = 1;
    while (current != NULL && current_index < index) {
        current = current->next;
        current_index++;
    }
    return current;
}

// Удаление узла из списка
void remove_node(ContactList *list, Node *person) {
    if (person == NULL || list == NULL) return;

    if (person == list->head) {   // проверяем, что контакт первый в списке
        list->head = person->next;
    } else {
        person->prev->next = person->next;  // меняем указатели на след элемент
    }

    if (person == list->tail) {  // если контакт последний в спике
        list->tail = person->prev;
    } else {
        person->next->prev = person->prev;  // меняем уазатеть на пред элемент
    }

    free(person->lastName);
    free(person->firstName);
    free(person->midName);
    free(person->work);
    free(person->number);
    free(person->mail);
    free(person);

    list->size--;

}

// Очистка памяти всего списка
void free_list(ContactList *list) {
    if (list == NULL) return;

    Node *current = list->head;
    while (current != NULL) {
        Node *next = current->next;
        free(current->lastName);
        free(current->firstName);
        free(current->midName);
        free(current->work);
        free(current->number);
        free(current->mail);
        free(current);
        current = next;
    }
    free(list);
}


void sort_list(ContactList *list) {  // функция сортировки списка по фамилии. исп при удалении/ изменении \ добавлении контакта
    if (list == NULL || list->head == NULL || list->head->next == NULL) return;

    int swapped;
    Node *ptr1;
    Node *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = list->head;

        while (ptr1->next != lptr) {
            // Сравниваем фамилии двух соседних контактов
            if (strcmp(ptr1->lastName, ptr1->next->lastName) > 0) {
                // Меняем местами указатели на строки
                char *tempLast  = ptr1->lastName;
                char *tempFirst = ptr1->firstName;
                char *tempMid   = ptr1->midName;
                char *tempWork  = ptr1->work;
                char *tempNum   = ptr1->number;
                char *tempMail  = ptr1->mail;

                ptr1->lastName  = ptr1->next->lastName;
                ptr1->firstName = ptr1->next->firstName;
                ptr1->midName   = ptr1->next->midName;
                ptr1->work      = ptr1->next->work;
                ptr1->number    = ptr1->next->number;
                ptr1->mail      = ptr1->next->mail;

                ptr1->next->lastName  = tempLast;
                ptr1->next->firstName = tempFirst;
                ptr1->next->midName   = tempMid;
                ptr1->next->work      = tempWork;
                ptr1->next->number    = tempNum;
                ptr1->next->mail      = tempMail;

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}