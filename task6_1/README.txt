Работа со списком контактов (двухсвязный список)
================================================

Структура проекта:
- include/     - заголовочные файлы (list.h, ui.h, file_loader.h)
- src/         - исходники (main.c, list.c, ui.c, file_loader.c)
- test/        - тесты (test.c)
- contaks.conf - файл с данными

Сборка через CMake:
mkdir build && cd build
cmake ..
make
./task4_1

Функционал:
1) Просмотр всех контактов
2) Добавление нового (автосортировка по фамилии)
3) Редактирование полей
4) Удаление контакта
5) Загрузка из contaks.conf при старте

Тесты:
cd test
gcc -o test test.c ../src/list.c -I../include
./test