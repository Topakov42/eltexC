#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/file_loader.h"

int load_contacts_from_file(ContactList *list, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Не удалось открыть файл с контактами: %s\n", filename);
        return 0;
    }

    char line[512];
    int count = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        // Убираем символ переноса строки в конце
        line[strcspn(line, "\r\n")] = 0;
        if (strlen(line) == 0) continue;

        // Парсим строку формата: ФИО ; Должность ; Телефон ; Email
        char *fio = strtok(line, ";");
        char *work = strtok(NULL, ";");
        char *number = strtok(NULL, ";");
        char *mail = strtok(NULL, ";");

        if (fio && work && number && mail) {
            // Убираем лишние пробелы по краям, если они есть
            // Для примера разделим ФИО на Фамилию, Имя, Отчество (если они через пробел)
            char *lastName = strtok(fio, " ");
            char *firstName = strtok(NULL, " ");
            char *midName = strtok(NULL, " ");

            // Если отчества нет в строке, подставим пустую строку или заглушку
            if (!lastName) lastName = "";
            if (!firstName) firstName = "";
            if (!midName) midName = "";

            // Очищаем работу, номер, почту от ведущих пробелов
            while (*work == ' ') work++;
            while (*number == ' ') number++;
            while (*mail == ' ') mail++;

            insert_sorted(list, lastName, firstName, midName, work, number, mail);
            count++;
        }
    }

    fclose(file);
    printf("Успешно загружено контактов из файла: %d\n", count);
    return count;
}