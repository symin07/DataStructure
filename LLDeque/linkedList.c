/***********************************************************
* Author: MIN HO KIM,  Gunnar Egge
* Email: kimminh@oregonstate.edu, eggeg@oregonstate.edu
* Date Created: 2022. 10. 19.
* Filename: linkedList.c
*
* Overview:
*	This program is a linked list implementation of the deque and bag ADTs. 
*	Note that both implementations utilize a linked list with
*	both a front and back sentinel and double links (links with
*	next and prev pointers).
************************************************************/

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"

#ifndef FORMAT_SPECIFIER
#define FORMAT_SPECIFIER "%d"
#endif


/* ************************************************************************
	Structs Link and LinkedList
************************************************************************ */
struct Link{
	TYPE value;
	Link *prev, *next;
};

struct LinkedList{
	Link *frontSentinel;
	Link *backSentinel;
	int size;
};

/* ************************************************************************
	Linked List Functions
************************************************************************ */

// Allocates and initializes a linked list
LinkedList* linkedListCreate()
{
	LinkedList* lst  = (LinkedList*)malloc(sizeof(LinkedList));
	assert(lst != NULL);	
	Link* frontSentinel = (Link*)malloc(sizeof(Link));
	Link* backSentinel = (Link*)malloc(sizeof(Link));
	
	lst->frontSentinel = frontSentinel;
	lst->backSentinel = backSentinel;
	lst->size = 0;
	
	lst->frontSentinel->prev = lst->frontSentinel;
	lst->frontSentinel->next = lst->backSentinel;
	lst->backSentinel->prev = lst->frontSentinel;
	lst->backSentinel->next = lst->backSentinel;

	return lst;

}

// Returns 1 if the list is empty and 0 otherwise
int isEmptyLinkedList(LinkedList* myList)
{
	int empty = 0;
	if(myList->frontSentinel->next == myList->backSentinel)
		empty = 1;
	if(myList->size == 0)
		empty = 1;
	
	return empty;
}
//Dellocates every link in the list including the sentinels and deletes the list itself
void deletelinkedList(LinkedList* myList)
{
	// twice freea
	assert(myList != NULL);
	Link* iterator = myList->frontSentinel->next;
	Link* freeList;
	
	while( iterator != myList->backSentinel)
	{
		freeList = iterator;
		iterator = iterator->next;
		free(freeList);
		freeList = NULL;	
	}
//	myList = NULL;
	free(myList);
}
// Adds a new link with the given value before the given link and increment the list's size
int sizelinkedList(LinkedList* myList)
{
	assert(myList->size >= 0);
	return myList->size;
}
//Adds a new link with the give value before the given link and increments the list's size
void addLinkBefore(LinkedList* list, TYPE value)
{
	assert(list != NULL);
	Link* newLink = (Link*)malloc(sizeof(Link));
	assert(newLink != NULL);
	newLink->value = value;
	
	Link* iterator = list->frontSentinel;

	newLink->prev = iterator;
	newLink->next = iterator->next;
	iterator->next->prev = newLink;
	iterator->next = newLink;
	
	list->size = list->size + 1;	
}

//Removes the given link from the list and decrements the list's size
//(void) (*fn_ptr) () = &removeLink;
void removeLink(LinkedList* list, TYPE value)
{
	assert(list != NULL);
//	Link* removedLink = (Link*)malloc(sizeof(Link));
//	removedLink->value = value;
	Link* iterator = list->frontSentinel->next;
	while(iterator != list->backSentinel && iterator->value != value)
		iterator = iterator->next;		

	if(iterator != list->backSentinel)
	{
		iterator->prev->next = iterator->next;
		iterator->next->prev = iterator->prev;
		free(iterator);
	}else{
		printf("No data to remove, Enter another data! \n");
	}
	
} 
//void (*func)()=&removeLink;


void printLinkedList(LinkedList* list)
{
	
	assert(list != NULL);
	Link* iterator = list->frontSentinel->next;
	printf("The list printed:   ");
	while(iterator != list->backSentinel)
	{
		printf("  %d", iterator->value);
		iterator = iterator->next;
	}
	printf("\n");
}

/* ************************************************************************
	Deque Functions
************************************************************************ */

//Allocates and initializes the deque
Deque* dequeCreate()
{
	LinkedList* myDeque  = (LinkedList*)malloc(sizeof(LinkedList));
	assert(myDeque != NULL);	
	Link* frontSentinel = (Link*)malloc(sizeof(Link));
	Link* backSentinel = (Link*)malloc(sizeof(Link));
	
	myDeque->frontSentinel = frontSentinel;
	myDeque->backSentinel = backSentinel;
	myDeque->size = 0;
	
	myDeque->frontSentinel->prev = myDeque->frontSentinel;
	myDeque->frontSentinel->next = myDeque->backSentinel;
	myDeque->backSentinel->prev = myDeque->frontSentinel;
	myDeque->backSentinel->next = myDeque->backSentinel;

	return myDeque;	
}
//Deallocates the data and deletes the deque
void deleteDeque(Deque* myDeque)
{
	assert(myDeque != NULL);
	Link* iterator = myDeque->frontSentinel->next;

	Link* freeList;

	while(iterator != myDeque->backSentinel)
	{
		freeList = iterator;
		iterator = iterator->next;
		free(freeList);
		freeList = NULL;
	}
	
//	myDeque = NULL; 
	free(myDeque);
}

int sizeDeque(Deque* myDeque)
{
	assert(myDeque != NULL);
	return myDeque->size;
}


int isEmptyDeque(Deque* myDeque)
{
	int empty = 0;
	if(myDeque->frontSentinel->next == myDeque->backSentinel)
		empty = 1;
	if(myDeque->size == 0)
		empty = 1;
	
	return empty;
}
// Adds a new link with the given value to the front of the deque
void addFrontDeque(Deque* myDeque, TYPE value)
{
	assert(myDeque != NULL);
	Link* newLink = (Link*)malloc(sizeof(Link));
	assert(newLink != NULL);
	newLink->value = value;

	Link* tempFront = myDeque->frontSentinel;
	
	newLink->prev = tempFront;
	newLink->next = tempFront->next;
	tempFront->next->prev = newLink;
	tempFront->next = newLink;
	
	myDeque->size = myDeque->size + 1; 
}	
//adds a new link with the given value to the back of the Deque
void addBackDeque(Deque* myDeque, TYPE value)
{
	assert(myDeque!= NULL);
	Link* newLink = (Link*)malloc(sizeof(Link));
	assert(newLink != NULL);
	newLink->value = value;

	Link* tempBack = myDeque->backSentinel;	
	newLink->prev = tempBack->prev;
	newLink->next = tempBack;
	tempBack->prev->next = newLink;
	tempBack->prev = newLink;
	
	myDeque->size = myDeque->size + 1;	
}
//Returns the value of the link at the front of the deque
TYPE frontDeque(Deque* myDeque)
{
	assert(myDeque != NULL);
	return myDeque->frontSentinel->next->value;
}
//Returns the value of the link at back of the deque
TYPE backDeque(Deque* myDeque)
{
	
	assert(myDeque != NULL);
	return myDeque->backSentinel->next->value;
}
// Remove the link at the front of the deque
void removeFrontDeque(Deque* myDeque)
{
	assert(myDeque != NULL);
	
	Link* rmvedLink = myDeque->frontSentinel->next; 

	myDeque->frontSentinel->next = rmvedLink->next;
	rmvedLink->next->prev = rmvedLink->prev;	
	free(rmvedLink);
	
	myDeque->size = myDeque->size - 1;
}
// remove the link at the bakc of the deque
void removeBackDeque(Deque* myDeque)
{
	assert(myDeque != NULL);

	Link* rmvedLink = myDeque->backSentinel->prev;

	myDeque->backSentinel->prev = rmvedLink->prev;
	rmvedLink->prev->next = rmvedLink->next;
	free(rmvedLink);

	myDeque->size = myDeque->size - 1;
	
} 
void printDeque(Deque* myDeque)
{
	assert(myDeque != NULL);
	
	Link* iterator = myDeque->frontSentinel->next;
	
	printf("The Deque  printed:   ");
	while(iterator != myDeque->backSentinel)
	{
		printf("  %d", iterator->value);
		iterator = iterator->next;
	}
	printf("\n");	
}
/* ********************************************************************
	Bag Functions
************************************************************************ */

// Allocates and initializes the bag.
Bag* bagCreate()
{
	LinkedList* bag  = (LinkedList*)malloc(sizeof(LinkedList));
	assert(bag != NULL);	
	Link* frontSentinel = (Link*)malloc(sizeof(Link));
	Link* backSentinel = (Link*)malloc(sizeof(Link));
	
	bag->frontSentinel = frontSentinel;
	bag->backSentinel = backSentinel;
	bag->size = 0;
	
	bag->frontSentinel->prev = bag->frontSentinel;
	bag->frontSentinel->next = bag->backSentinel;
	bag->backSentinel->prev = bag->frontSentinel;
	bag->backSentinel->next = bag->backSentinel;

	return bag;	
}
//Dellocates the data and deletes the bag
void deleteBag(Bag* myBag)
{
	assert(myBag != NULL);
	Link* iterator = myBag->frontSentinel->next;

	Link* freeList;

	while(iterator != myBag->backSentinel)
	{
		freeList = iterator;
		iterator = iterator->next;
		free(freeList);
		freeList = NULL;
	}
	
//	myBag = NULL; 
	free(myBag);
}
	
//Returns the size of the bag
int sizeBag(Bag* myBag)
{
	assert(myBag != NULL);
	return myBag->size;
}


int isBagEmpty(Bag* myBag)
{
	int empty = 0;
	if(myBag->frontSentinel->next == myBag->backSentinel)
		empty = 1;
	if(myBag->size == 0)
		empty = 1;
	
	return empty;
}
// Adds an element into bag
void addBag(Bag* myBag, TYPE value)
{
	assert(myBag != NULL);
	Link* newLink = (Link*)malloc(sizeof(Link));
	assert(newLink != NULL);
	newLink->value = value;

	Link* tempFront = myBag->frontSentinel;
	
	newLink->prev = tempFront;
	newLink->next = tempFront->next;
	tempFront->next->prev = newLink;
	tempFront->next = newLink;
	
	myBag->size = myBag->size + 1; 
}
// Returns "1" if the bag contains the specified element or 0 if not
int containsBag(Bag* myBag, TYPE value)
{
	assert(myBag != NULL);
	Link* iterator = myBag->frontSentinel->next;
	while(iterator != myBag->backSentinel && iterator->value != value)
		iterator = iterator->next;

	if(iterator != myBag->backSentinel)
		return 1;
	else return 0;	 
}

void removeBag(Bag *myBag, TYPE value)
{
	assert(myBag != NULL);
	Link* removerLink = (Link*)malloc(sizeof(Link));
	removerLink->value = value;
	Link* iterator = myBag->frontSentinel->next;

	while(iterator != myBag->backSentinel && iterator->value != value)
		iterator = iterator->next;

	if(iterator != myBag->backSentinel)
	{
		removerLink = iterator;
		iterator->prev->next = iterator->next;
		iterator->next->prev = iterator->prev;
		free(removerLink);
		myBag->size = myBag->size - 1;	
	}else printf("There is no link to remove. \n");	
	
}	

void printBag(Bag* myBag)
{
	assert(myBag != NULL);
	
	Link* iterator = myBag->frontSentinel->next;
	
	printf("The Bag  printed:   ");
	while(iterator != myBag->backSentinel)
	{
		printf("  %d", iterator->value);
		iterator = iterator->next;
	}
	printf("\n");	
}
