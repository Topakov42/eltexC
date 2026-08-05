cmake_minimum_required(VERSION 3.28.3)
project(task4_1 C)

set(CMAKE_C_STANDARD 23)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(task4_1
        src/main.c
        src/list.c
        src/ui.c
        src/file_loader.c
)

add_executable(test_runner
        test/test.c
        src/list.c
)