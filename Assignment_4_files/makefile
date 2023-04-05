CC=gcc
CFLAGS=-Wall -std=c99

all: bst 

bst: bst.o tests.o
	gcc -g -Wall -std=c99 -o bst bst.o compare.o mainTest.o 
bst.o: bst.c bst.h structs.h
	gcc -g -Wall -std=c99 -c bst.c
compare.o: bst.h structs.h
	gcc -g -Wall -std=c99 -c compare.c
tests.o: tests.c bst.h structs.h
	gcc -g -Wall -std=c99 -c mainTest.c

clean:
	-rm *.o

cleanall: clean
	-rm bst
