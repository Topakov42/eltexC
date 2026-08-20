CC = gcc
CFLAGS = -Wall -Wextra -std=c2x -Iinclude

TARGET = build/task6_2
TEST = build/test_runner
LIB = build/liblist.so

all: $(TARGET) $(TEST)

build:
	mkdir -p build

build/list.o: src/list.c include/list.h | build
	$(CC) $(CFLAGS) -fPIC -c src/list.c -o build/list.o

$(LIB): build/list.o
	$(CC) -shared build/list.o -o $(LIB)

$(TARGET): src/main.c src/ui.c src/file_loader.c $(LIB)
	$(CC) $(CFLAGS) src/main.c src/ui.c src/file_loader.c -Lbuild -llist -Wl,-rpath,'$$ORIGIN' -o $(TARGET)

$(TEST): test/test.c $(LIB)
	$(CC) $(CFLAGS) test/test.c -Lbuild -llist -Wl,-rpath,'$$ORIGIN' -o $(TEST)

clean:
	rm -rf build

.PHONY: all clean