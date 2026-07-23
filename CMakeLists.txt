cmake_minimum_required(VERSION 4.2)
project(task2_2 C)

set(CMAKE_C_STANDARD 23)

add_executable(task2_2 src/main.c
        src/math_ops.c
        src/io_utils.c)
