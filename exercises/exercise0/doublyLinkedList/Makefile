.PHONY: all

CC = gcc
CFLAGS = -std=c99 -Wall -pedantic

all: main

main: main.o list.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o main