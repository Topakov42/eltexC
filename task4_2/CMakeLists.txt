cmake_minimum_required(VERSION 3.28.3)
project(task4_2 C)

set(CMAKE_C_STANDARD 23)
include_directories(include)
add_executable(task4_2
        src/main.c
        src/insert.c
        src/extract.c
        include/extract.h
        include/insert.h
        src/queue.c
        include/queue.h

        src/write_console.c
        include/write_console.h

)
