all: tests

tests: DA_Stack_Bag.o tests.o
	gcc -g -Wall -std=c99 -o tests DA_Stack_Bag.o tests.o

tests.o: tests.c DA_Stack_Bag.h
	gcc -g -Wall -std=c99 -c tests.c

DA_Stack_Bag.o: DA_Stack_Bag.c DA_Stack_Bag.h 
	gcc -g -Wall -std=c99 -c DA_Stack_Bag.c	
		
clean:
	-rm -f *.o core