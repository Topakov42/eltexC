CC = gcc
CFLAGS = -Wall -Wextra -std=c2x -Iinclude
LDFLAGS = -Wl,-rpath,'$$ORIGIN'

TARGET = build/task6_2
LIB = build/liblist.so

all: $(TARGET)

build:
	mkdir -p build

build/list.o: src/list.c include/list.h | build
	$(CC) $(CFLAGS) -fPIC -c src/list.c -o build/list.o

$(LIB): build/list.o
	$(CC) -shared build/list.o -o $(LIB)

$(TARGET): src/main.c src/ui.c src/file_loader.c $(LIB)
	$(CC) $(CFLAGS) src/main.c src/ui.c src/file_loader.c -Lbuild -llist $(LDFLAGS) -o $(TARGET)

clean:
	rm -rf build/*

.PHONY: all clean
