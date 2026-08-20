CC = gcc
CFLAGS = -Wall -Wextra -std=c2x -Iinclude

TARGET = build/task6_3
TEST = run_tests

LIBS = libs/libsum.so libs/libsub.so libs/libmul.so libs/libdiv.so

all: $(TARGET) $(TEST)

build:
	mkdir -p build

libs/libsum.so: src/sum.c
	$(CC) $(CFLAGS) -fPIC -shared src/sum.c -o libs/libsum.so

libs/libsub.so: src/sub.c
	$(CC) $(CFLAGS) -fPIC -shared src/sub.c -o libs/libsub.so

libs/libmul.so: src/mul.c
	$(CC) $(CFLAGS) -fPIC -shared src/mul.c -o libs/libmul.so

libs/libdiv.so: src/div.c
	$(CC) $(CFLAGS) -fPIC -shared src/div.c -o libs/libdiv.so

$(TARGET): src/main.c src/io_utils.c src/loader.c $(LIBS) | build
	$(CC) $(CFLAGS) src/main.c src/io_utils.c src/loader.c -ldl -o $(TARGET)

$(TEST): tests/test_cal.c src/loader.c $(LIBS)
	$(CC) $(CFLAGS) tests/test_cal.c src/loader.c -lcheck -lsubunit -ldl -lm -o $(TEST)

clean:
	rm -rf build
	rm -f libs/*.so
	rm -f $(TEST)

.PHONY: all clean