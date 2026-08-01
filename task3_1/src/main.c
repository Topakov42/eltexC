#include <stdio.h>
#include "../include/print_binary.h"
#include "../include/parse_rwx.h"
#include "../include/read_file_rights.h"
#include "../include/print_letters.h"
#include "../include/write_choice.h"


int main(void) {


    printf("Выбирите операцию : \n");
    printf("1) Ввести права доступа, для вывода его в бинарном виде : \n");
    printf("2) Указать имя файла, для вывода его прав доступа\nв буквенном, цифровом и битовом виде : \n");
    int choice = write_choice();

    switch (choice) {
        case 1:
            printf("первый варик");
            break;
        case 2:
            printf("Второй варик");
            break;
            default:
            printf("Что то не понятное");
            break;
    }





    return 0;
}