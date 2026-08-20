#include "../include/loader.h"

#include <dirent.h>
#include <dlfcn.h>
#include <stdio.h>
#include <string.h>

static char get_operation(const char *filename) {
    if (strcmp(filename, "libsum.so") == 0)
        return '+';


    if (strcmp(filename, "libsub.so") == 0)
        return '-';

    if (strcmp(filename, "libmul.so") == 0)
        return '*';

    if (strcmp(filename, "libdiv.so") == 0)
        return '/';

    return '\0';
}

static const char *get_function_name(char operation) {
    switch (operation) {
        case '+':
            return "sum";


        case '-':
            return "sub";

        case '*':
            return "mul";

        case '/':
            return "divv";

        default:
            return NULL;
    }
}

int load_functions(const char *directory,
                   LoadedFunction *functions,
                   size_t max_functions) {
    DIR *dir = opendir(directory);


    if (dir == NULL) {
        perror("Не удалось открыть каталог с библиотеками");
        return 0;
    }

    struct dirent *entry;
    size_t count = 0;

    while ((entry = readdir(dir)) != NULL && count < max_functions) {
        char operation = get_operation(entry->d_name);

        if (operation == '\0')
            continue;

        char path[512];

        snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);

        void *handle = dlopen(path, RTLD_LAZY);

        if (handle == NULL) {
            fprintf(stderr, "Ошибка загрузки %s: %s\n",
                    entry->d_name, dlerror());
            continue;
        }

        const char *function_name = get_function_name(operation);

        dlerror();

        math_func function =
                (math_func) dlsym(handle, function_name);

        const char *error = dlerror();

        if (error != NULL) {
            fprintf(stderr, "Ошибка поиска функции %s: %s\n",
                    function_name, error);
            dlclose(handle);
            continue;
        }

        functions[count].operation = operation;
        functions[count].function = function;
        functions[count].handle = handle;

        count++;

    }

    closedir(dir);

    return count;
}

void unload_functions(LoadedFunction *functions, size_t count) {
    for (size_t i = 0; i < count; i++) {
        if (functions[i].handle != NULL) {
            dlclose(functions[i].handle);
        }
    }
}
