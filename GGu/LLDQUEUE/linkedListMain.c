#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "linkedList.h"
extern void (*func)();

int main()
{
	LinkedList* myList = linkedListCreate();
	
	addLinkBefore(myList, 1);
	addLinkBefore(myList, 9);
	addLinkBefore(myList, 7);
	addLinkBefore(myList, 5);
	addLinkBefore(myList, 6);
	addLinkBefore(myList, 8);
	addLinkBefore(myList, 4);
	
	printLinkedList(myList);
	removeLink(myList, 6);
//	(func)(myList, 6);
	printLinkedList(myList);
	removeLink(myList, 9);
	removeLink(myList, 5);
//	(func)(myList, 9);
//	(func)(myList, 5);
	printLinkedList(myList);
	removeLink(myList, 9);
//	(func)(myList, 9);
	printLinkedList(myList);
/*	removeLink(myList, 4);
	removeLink(myList, 1);
	removeLink(myList, 1);*/
	
	deletelinkedList(myList);	
	if(isEmptyLinkedList(myList)) printf("After deletion List is empty \n");
//	printLinkedList(myList);
	
/********** deque Test******************/

	Deque* myDeque = dequeCreate();

	addFrontDeque(myDeque, 9);
	addFrontDeque(myDeque, 8);
	addFrontDeque(myDeque, 7);
	addFrontDeque(myDeque, 5);
	addFrontDeque(myDeque, 3);
	addFrontDeque(myDeque, 1);

	printDeque(myDeque);
	printf("deque size: %d\n", sizeDeque(myDeque));
	printf("frontDque may be 1: %d\n", frontDeque(myDeque));	
	addBackDeque(myDeque, 10);
	addBackDeque(myDeque, 70);
	addBackDeque(myDeque, 80);
	addBackDeque(myDeque, 90);
 
	printDeque(myDeque);
	printf("deque size: %d\n", sizeDeque(myDeque));
	printf("back Deque may be 90: %d\n", backDeque(myDeque));
	
	removeFrontDeque(myDeque);
	removeFrontDeque(myDeque);
	removeFrontDeque(myDeque);
	printDeque(myDeque);
	printf("deque size maybe 7:  %d\n", sizeDeque(myDeque));
	printf("front Deque may be 7: %d\n", frontDeque(myDeque));

	removeBackDeque(myDeque);
	removeBackDeque(myDeque);
	removeBackDeque(myDeque);
	
	printDeque(myDeque);
	printf("deque size maybe 4:  %d\n", sizeDeque(myDeque));
	printf("back Deque may be 10: %d\n", backDeque(myDeque));

	deleteDeque(myDeque);
	if(isEmptyDeque(myDeque)) printf("After deletion Deque is empty \n");
//	printDeque(myDeque);
/*********************myBag Test************************/

	Bag* myBag = bagCreate();

	addBag(myBag, 9);
	addBag(myBag, 8);
	addBag(myBag, 6);
	addBag(myBag, 5);
	addBag(myBag, 2);

	printBag(myBag);
	printf("Bag size 5: %d\n", sizeDeque(myBag));
 
	for (int i; i < sizeBag(myBag); i++)
		if(containsBag(myBag, i))
			printf("my Bag contains %d", i);

	removeBag(myBag, 2);
	removeBag(myBag, 9);
	removeBag(myBag, 6);
	printf("erase 2, 9, 6 \n");
	printf("my bag still has 8, 5:    ");
	printBag(myBag);

	deleteBag(myBag);
		
	if(isBagEmpty(myBag)) printf("After deletion myBag is empty \n");
//	printBag(myBag);
	

	return 0;	
}
