CFLAGS = -O2 -Wall -fPIC
CC = gcc

all: arcfour example

example.o: example.c arcfour.h
	$(CC) -c $(CFLAGS) example.c

arcfour.o: arcfour.c arcfour.h
	$(CC) -c $(CFLAGS) arcfour.c

arcfour: arcfour.o
	$(CC) arcfour.o -o arcfour.so $(CFLAGS) -shared -ldl -D_GNU_SOURCE

example: example.o arcfour.o
	$(CC) example.o arcfour.o -o example -O2 -Wall 

clean:
	rm -f *.o *.so example
