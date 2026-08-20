Практическая работа 6.2

Тема: динамическая библиотека

В работе доработан список контактов из задания 6.1.
Функции и структуры для работы с двухсвязным списком
вынесены в динамическую библиотеку liblist.so.

Структура проекта:

include/
    list.h
    ui.h
    file_loader.h

src/
    main.c
    list.c
    ui.c
    file_loader.c

test/
    test.c

build/
    liblist.so
    task6_2
    test_runner


Сборка:

make


Запуск программы:

./build/task6_2


Запуск тестов:

./build/test_runner


Очистка файлов сборки:

make clean

Для проверки динамической библиотеки можно использовать:

ldd build/task6_2

В выводе должна присутствовать liblist.so.