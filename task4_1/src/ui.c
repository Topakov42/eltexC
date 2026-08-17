#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ui.h"


char *writeConsole(char *prompt) {
    // ввод с консоли
    char buf[100];
    printf("%s", prompt);
    if (fgets(buf, sizeof(buf), stdin) == NULL) {
        // если в консоль ничего не ввели
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
    if (list->head == NULL) {
        printf("Телефонная книга пуста.\n");
        return;
    }

    Node *current = list->head;
    int index = 1;
    while (current != NULL) {
        printf("%d - %s %s %s , %s , %s , %s\n",
               index, current->lastName, current->firstName, current->midName,
               current->work, current->number, current->mail);
        current = current->next;
        index++;
    }
    printf("\n");
}

// Выбор контакта пользователем
Node *pickPerson(ContactList *list) {
    if (list->head == NULL) {
        printf("Телефонная книга пуста.\n");
        return NULL;
    }

    print_list(list); // выводим список пользователей
    int option = atoi(writeConsole("Выберите номер персоны: "));

    Node *selected = get_node_by_index(list, option); // выбираем нужного нам контакта по индексу
    if (selected == NULL) {
        printf("Ошибка. Такой записи нет\n");
    }

    return selected;
}

// редактирование контакта
void editPerson(Node *person) {
    if (person == NULL) {
        return;
    }


    printf("1) Поменять Фамилию\n");
    printf("2) Поменять Имя\n");
    printf("3) Поменять Отчество\n");
    printf("4) Поменять Место работы\n");
    printf("5) Поменять номер телефона\n");
    printf("6) Поменять почту\n");

    char *choices = writeConsole("Введите цифры полей для изменения (например, 123 или 45): ");
    for (int i = 0; choices[i] != '\0'; i++) {
        switch (choices[i]) {
            case '1': {
                printf("Текущая фамилия: %s. Введите новую: ", person->lastName);
                char *str = writeConsole("");
                if (str[0] == '\0') {
                    printf("Введен пустой параметр\n");
                    free(str);
                    break;
                }
                free(person->lastName);
                person->lastName = str;
                break;
            }
            case '2': {
                printf("Текущее имя: %s. Введите новое: ", person->firstName);
                char *str = writeConsole("");
                if (str[0] == '\0') {
                    printf("Введен пустой параметр\n");
                    free(str);
                    break;
                }
                free(person->firstName);
                person->firstName = str;
                break;
            }
            case '3': {
                printf("Текущее отчество: %s. Введите новое: ", person->midName);
                char *str = writeConsole("");
                if (str[0] == '\0') {
                    printf("Введен пустой параметр\n");
                    free(str);
                    break;
                }
                free(person->midName);
                person->midName = str;
                break;
            }
            case '4': {
                printf("Текущее место работы: %s. Введите новое: ", person->work);
                char *str = writeConsole("");
                if (str[0] == '\0') {
                    printf("Введен пустой параметр\n");
                    free(str);
                    break;
                }
                free(person->work);
                person->work = str;
                break;
            }
            case '5': {
                printf("Текущий номер: %s. Введите новый: ", person->number);
                char *str = writeConsole("");
                if (str[0] == '\0') {
                    printf("Введен пустой параметр\n");
                    free(str);
                    break;
                }
                free(person->number);
                person->number = str;
                break;
            }
            case '6': {
                printf("Текущая почта: %s. Введите новую: ", person->mail);
                char *str = writeConsole("");
                if (str[0] == '\0') {
                    printf("Введен пустой параметр\n");
                    free(str);
                    break;
                }
                free(person->mail);
                person->mail = str;
                break;
            }
            default:
                printf("Пункт '%c' не существует, пропускаем.\n", choices[i]);
                break;
        }
    }

    free(choices);
}

// Добавление нового контакта через интерфейс
void addNewContact(ContactList *list) {
    char *lastName = writeConsole("Введите Фамилию - ");
    char *firstName = writeConsole("Введите Имя - ");
    char *midName = writeConsole("Введите Отчество - ");
    char *work = writeConsole("Введите место работы - ");
    char *number = writeConsole("Введите Телефон - ");
    char *mail = writeConsole("Введите Email - ");

    insert_sorted(list, lastName, firstName, midName, work, number, mail); // сортировка списка

    free(lastName);
    free(firstName);
    free(midName);
    free(work);
    free(number);
    free(mail);

    sort_list(list);


    printf("Новый контакт успешно добавлен и отсортирован!\n");
}
