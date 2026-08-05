#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ui.h"


char *writeConsole(char* prompt) { // ввод с консоли
    char buf[100];
    printf("%s", prompt);
    if (fgets(buf, sizeof(buf), stdin) == NULL) { // если в консоль ничего не ввели
        buf[0] = '\0';
        return strdup(buf);
    }

    size_t len = strlen(buf);
    if (len > 0 && buf[len - 1] == '\n') {
        buf[len - 1] = '\0';
    }

    return strdup(buf);
}

// Вывод списка контактов
void print_list(ContactList *list) {
    if (list->head == NULL) {  // проверка на пустой список
        printf("Телефонная книга пуста.\n");
        return;
    }

    Node *current = list->head;
    int index = 1;
    while (current != NULL) {  // проходим по всему списку
        printf("%d - %s %s %s , %s , %s , %s\n", 
               index, current->firstName, current->lastName, current->midName, 
               current->work, current->number, current->mail);
        current = current->next;
        index++;
    }
    printf("\n");
}

// Выбор контакта пользователем
Node* pickPerson(ContactList *list) {
    if (list->head == NULL) {
        printf("Телефонная книга пуста.\n");
        return NULL;
    }
    
    print_list(list);  // выводим список пользователей
    int option = atoi(writeConsole("Выберите номер персоны: "));
    
    Node *selected = get_node_by_index(list, option);  // выбираем нужного нам контакта по индексу
    if (selected == NULL) {
        printf("Ошибка. Такой записи нет\n");
    }
    return selected;
}

// редактирование контакта
void editPerson(Node *person) {
    if (person == NULL) return;  // проверка

    printf("1) Поменять Фамилию\n");
    printf("2) Поменять Имя\n");
    printf("3) Поменять Отчество\n");
    printf("4) Поменять Место работы\n");
    printf("5) Поменять номер телефона\n");
    printf("6) Поменять почту\n");
    
    int option = atoi(writeConsole("Ваш выбор: "));
    switch (option) {
        case 1:
            printf("Текущая фамилия: %s. Введите новую: ", person->lastName);
            free(person->lastName);
            person->lastName = writeConsole("");
            break;
        case 2:
            printf("Текущее имя: %s. Введите новое: ", person->firstName);
            free(person->firstName);
            person->firstName = writeConsole("");
            break;
        case 3:
            printf("Текущее отчество: %s. Введите новое: ", person->midName);
            free(person->midName);
            person->midName = writeConsole("");
            break;
        case 4:
            printf("Текущая работа: %s. Введите новую: ", person->work);
            free(person->work);
            person->work = writeConsole("");
            break;
        case 5:
            printf("Текущий номер: %s. Введите новый: ", person->number);
            free(person->number);
            person->number = writeConsole("");
            break;
        case 6:
            printf("Текущая почта: %s. Введите новую: ", person->mail);
            free(person->mail);
            person->mail = writeConsole("");
            break;
        default:
            printf("Такого пункта нет\n");
            return;
    }
    printf("Контакт успешно изменен!\n");

}

// Добавление нового контакта через интерфейс
void addNewContact(ContactList *list) {
    char *lastName = writeConsole("Введите Фамилию - ");
    char *firstName = writeConsole("Введите Имя - ");
    char *midName = writeConsole("Введите Отчество - ");
    char *work = writeConsole("Введите место работы - ");
    char *number = writeConsole("Введите Телефон - ");
    char *mail = writeConsole("Введите Email - ");

    insert_sorted(list, lastName, firstName, midName, work, number, mail);  // сортировка списка

    free(lastName);
    free(firstName);
    free(midName);
    free(work);
    free(number);
    free(mail);

    printf("Новый контакт успешно добавлен и отсортирован!\n");
}