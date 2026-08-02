#include <stdio.h>
#include <stdlib.h>
#include "../include/change_rights.h"
#include "../include/print_binary.h"
#include "../include/parse_rwx.h"
#include "../include/read_file_rights.h"
#include "../include/print_letters.h"
#include "../include/write_console.h"


void print_menu() {
    printf("Выбирите операцию : \n");
    printf("1) Ввести права доступа, для вывода его в бинарном виде : \n");
    printf("2) Указать имя файла, для вывода его прав доступа\nв буквенном, цифровом и битовом виде : \n");
    printf("3) Изменить права доступа у файла : \n");
    printf("4) выход из программы \n");
}


void print_rights() {
    printf("Выберите какой ввод нужен:\n");
    printf("1) Цифровой \n");
    printf("2) Буквенный \n");
    int choice = write_number();
    switch (choice) {
        case 1:
            printf("Введите число в виде '762' \n");
            print_binary(write_number());
            break;
        case 2:
            printf("Введите буквы в виде 'rwxrwxrwx' \n");
            char *rwx = write_letters();
            int numRights = parse_string_rights(rwx);
            if (numRights == -1) {
                break;
            }
            free(rwx);
            print_binary(numRights);
            break;
        default:
            printf("Неверная операция \n");
            break;
    }
}

void print_rights_file () {
    printf("Введите полное название файла :\n");
    char *nameFile = write_letters();
    read_file_rights(nameFile);
    free(nameFile);
}





int main(void) {
    while (1) {
        print_menu();
        int choice = write_number();
        switch (choice) {
            case 1:
                print_rights();
                break;
            case 2:
                print_rights_file();
                break;
            case 3:
                change_rights();
                break;
            case 4:
                printf("Пока пока ");
                return 0;
            default:
                printf("Ошибка, такого пункта нет\n");
                break;
        }
    }
}
