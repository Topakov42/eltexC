cmake_minimum_required(VERSION 3.28.3)
project(task4_1 C)

set(CMAKE_C_STANDARD 23)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(list STATIC src/list.c)

add_executable(task4_1
        src/main.c
        src/ui.c
        src/file_loader.c
)

target_link_libraries(task4_1 list)

add_executable(test_runner
        test/test.c
)

target_link_libraries(test_runner list)