CC=gcc --std=c99 -g

all: todo_main

todo_main: todo_main.c pq.o dynarray.o
	$(CC) todo_main.c pq.o dynarray.o -o todo_main

dynarray.o: dynarray.c dynarray.h
	$(CC) -c dynarray.c

pq.o: pq.c pq.h
	$(CC) -c pq.c

clean:
	rm -f *.o todo_main