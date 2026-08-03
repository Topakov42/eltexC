cmake_minimum_required(VERSION 4.2)
project(task3_2 C)

set(CMAKE_C_STANDARD 23)

add_executable(task3_2 src/main.c
        src/network_utils.c)
