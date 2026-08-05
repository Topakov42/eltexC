#include <stdio.h>
#include <stdlib.h>
#include "../include/list.h"
#include "../include/ui.h"
#include "../include/file_loader.h"

int main(void) {
    ContactList *list = create_list();
    load_contacts_from_file(list, "../contaks.conf");  // чиатем конфиг с данными

    while (1) {
        printf("\nВыберите действие:\n");
        printf("1) Изменить поля контакта\n");
        printf("2) Удалить контакт\n");
        printf("3) Добавить контакт\n");
        printf("4) Вывести список телефонной книги\n");
        printf("5) Вывести количество записей\n");
        printf("6) Завершение программы\n");

        int option;                                           //
        if (scanf("%d", &option) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {
            }
            printf("Некорректный ввод\n");
            continue;
        }

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
        }

        Node *target = NULL;
        switch (option) {
            case 1:
                target = pickPerson(list);
                if (target != NULL) editPerson(target);
                break;
            case 2:
                target = pickPerson(list);
                if (target != NULL) {
                    remove_node(list, target);
                    printf("Контакт успешно удален.\n");
                }
                break;
            case 3:
                addNewContact(list);
                break;
            case 4:
                print_list(list);
                break;
            case 5:
                printf("Количество записей в справочнике - %d\n", list->size);
                break;
            case 6:
                free_list(list);
                return 0;
            default:
                printf("Нет такого варианта\n");
                break;
        }
    }
    return 0;
}
