cmake_minimum_required(VERSION 4.2)
project(task3_1 C)

set(CMAKE_C_STANDARD 23)

add_executable(task3_1 src/main.c
        src/print_binary.c
        include/print_binary.h
        src/parse_rwx.c
        include/parse_rwx.h
)
