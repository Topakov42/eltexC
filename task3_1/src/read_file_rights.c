#include "../include/read_file_rights.h"
#include <stdio.h>
#include <sys/stat.h>
#include "../include/print_binary.h"
#include "../include/print_letters.h"


void read_file_rights(char *fileName) {  // 
    struct stat fileInfo;
    if (stat(fileName, &fileInfo) == 0) {
        int rwx = fileInfo.st_mode & 0777;
        print_letters(rwx);
        printf("Цифровые права файла: %o\n", rwx);
        printf("Битовый права : ");
        print_binary(rwx);
    } else {
        perror("Error:");
    }
}
