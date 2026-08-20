CC = gcc
CFLAGS = -Wall -Wextra -std=c2x -Iinclude

TARGET = build/task6_1
LIB = build/liblist.a

all: $(TARGET)

build:
	mkdir -p build

build/list.o: src/list.c include/list.h | build
	$(CC) $(CFLAGS) -c src/list.c -o build/list.o

$(LIB): build/list.o
	ar rcs $(LIB) build/list.o

$(TARGET): src/main.c src/ui.c src/file_loader.c $(LIB)
	$(CC) $(CFLAGS) \
		src/main.c \
		src/ui.c \
		src/file_loader.c \
		$(LIB) \
		-o $(TARGET)

clean:
	rm -rf build/*

.PHONY: all clean