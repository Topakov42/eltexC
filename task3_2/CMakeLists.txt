cmake_minimum_required(VERSION 3.28.3)
project(task3_2 C)

set(CMAKE_C_STANDARD 23)

add_executable(task3_2 src/main.c
        src/network_utils.c
        include/generate_ip.h
        src/generate_ip.c
)

add_executable(unittest
        test/test.c
        src/generate_ip.c
        src/network_utils.c
)
