CC=gcc
FLAGS= -Wall -g

all: main.o
	$(CC) $(FLAGS) -o graph main.o

main.o: main.c
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm -f *.o *.a