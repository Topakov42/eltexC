cmake_minimum_required(VERSION 4.2)
project(task2_2 C)

set(CMAKE_C_STANDARD 23)

add_executable(task2_2 src/main.c
        src/math_ops.c
        src/io_utils.c
        include/io_utils.h
        include/math_ops.h)


find_package(PkgConfig REQUIRED)
pkg_check_modules(CHECK REQUIRED check)

add_executable(my_test tests/test_cal.c src/math_ops.c)
target_link_libraries(my_test ${CHECK_LIBRARIES})