#include <stdio.h>
#include "../include/print_binary.h"
#include "../include/parse_rwx.h"
#include "../include/read_file_rights.h"
int main(void) {

    char *name = "/home/topa/token_git.txt";

    read_file_rights(name);



    return 0;
}