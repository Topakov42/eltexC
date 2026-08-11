#include "../include/change_rights.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "../include/print_binary.h"
#include "../include/print_letters.h"
#include "../include/read_file_rights.h"
#include "../include/write_console.h"

int apply_chmod(int current_rights, const char *cmd) {
    if (!cmd || strlen(cmd) == 0) return -1;

    // Валидация символов
    char validChar[10] = {'r', 'w', 'x', 'a', '-', '+', '=', 'u', 'g', 'o'};
    for (size_t k = 0; k < strlen(cmd); ++k) {
        int found = 0;
        for (int j = 0; j < 10; ++j) {
            if (cmd[k] == validChar[j]) {
                found = 1;
                break;
            }
        }
        if (!found) return -1;
    }

    int i = 0;
    int targetMask = 0;

    // Определяем субъектов (u, g, o, a)
    while (cmd[i] == 'u' || cmd[i] == 'g' || cmd[i] == 'o' || cmd[i] == 'a') {
        if (cmd[i] == 'u') targetMask |= 0700;
        if (cmd[i] == 'g') targetMask |= 0070;
        if (cmd[i] == 'o') targetMask |= 0007;
        if (cmd[i] == 'a') targetMask |= 0777;
        i++;
    }

    if (targetMask == 0) {
        targetMask = 0777;
    }

    char operation = cmd[i];
    if (operation != '+' && operation != '-' && operation != '=') {
        return -1;
    }
    i++;

    // Вычисляем маску прав (r, w, x)
    int perm_bits = 0;
    while (cmd[i] == 'r' || cmd[i] == 'w' || cmd[i] == 'x') {
        if (cmd[i] == 'r') perm_bits |= 4;
        if (cmd[i] == 'w') perm_bits |= 2;
        if (cmd[i] == 'x') perm_bits |= 1;
        i++;
    }

    // Если в строке остались нераспознанные символы
    if (cmd[i] != '\0') return -1;

    int full_perm = (perm_bits << 6) | (perm_bits << 3) | perm_bits;
    int final_bits = full_perm & targetMask;
    int rwx = current_rights;

    if (operation == '+') {
        rwx |= final_bits;
    } else if (operation == '-') {
        rwx &= ~final_bits;
    } else if (operation == '=') {
        rwx = (rwx & ~targetMask) | final_bits;
    }

    return rwx;
}

void change_rights(void) {
    int rwx;
    struct stat fileInfo;

    printf("Введите название файла, у которого хотите поменять права :\n");

    char *nameFile = write_letters();
    if (stat(nameFile, &fileInfo) == 0) {
        rwx = fileInfo.st_mode & 0777;
    } else {
        perror("Error:");
        free(nameFile);
        return;
    }

    printf("Текущие права файла : \n");
    read_file_rights(nameFile);
    free(nameFile);

    printf("Введите новые права (например: 'u+x', 'go-rx', 'ug=wx')\n");
    char *commands = write_letters();

    int updated_rwx = apply_chmod(rwx, commands);
    if (updated_rwx == -1) {
        printf("Ошибка, неверный ввод аргументов\n");
        free(commands);
        return;
    }

    rwx = updated_rwx;

    printf("Новые права файла :\n");
    print_letters(rwx);
    printf("Представление в виде числа : %o\n", rwx);
    printf("Представление в бинарном виде : ");
    print_binary(rwx);
    free(commands);
}