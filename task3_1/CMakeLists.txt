cmake_minimum_required(VERSION 3.28.3)
project(task3_1 C)

set(CMAKE_C_STANDARD 23)

add_executable(task3_1 src/main.c
        src/print_binary.c
        include/print_binary.h
        src/parse_rwx.c
        include/parse_rwx.h
        src/read_file_rights.c
        include/read_file_rights.h
        include/print_letters.h
        src/print_letters.c
        src/write_console.c
        src/change_rights.c
        include/change_rights.h
)

add_executable(unit_tests
        tests/tests.c
        src/parse_rwx.c
        src/change_rights.c
        src/write_console.c
        src/read_file_rights.c
        src/print_letters.c
        src/print_binary.c
)