CC = gcc
CFLAGS = -g -Wall
OBJECTS = nqueens.o mem.o backtrack.o
run:	$(OBJECTS)
	$(CC) $(CFLAGS) -o nqueens $(OBJECTS)