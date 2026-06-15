CC = gcc

CFLAGS = -Wall -Wextra -std=c11

OBJ = main.o cube.o moves.o search.o

magiccube: $(OBJ)
	$(CC) $(OBJ) -o magiccube

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

cube.o: cube.c
	$(CC) $(CFLAGS) -c cube.c

moves.o: moves.c
	$(CC) $(CFLAGS) -c moves.c

search.o: search.c
	$(CC) $(CFLAGS) -c search.c

clean:
	rm -f *.o magiccube