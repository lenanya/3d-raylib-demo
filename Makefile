all: build/demo

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99 -Iinclude
LDFLAGS = -Llib -lm -lraylib
OBJS = build/demo.o

build/demo: $(OBJS)
	$(CC) $(CFLAGS) -o build/demo $(OBJS) $(LDFLAGS)

build/demo.o: src/main.c include/demo.h
	$(CC) $(CFLAGS) -c src/main.c -o build/demo.o

run: build/demo
	./build/demo

clean:
	rm -f build/*