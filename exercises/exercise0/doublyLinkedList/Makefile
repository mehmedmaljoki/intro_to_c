.PHONY: all

all: main

CC = gcc
CFLAGS = -std=c99 -Wall -pedantic

main: main.o list.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c list.h
	$(CC) $(CFLAGS) -c -o $@ $<

list.o: list.c list.h

clean:
	rm -f main *.o
