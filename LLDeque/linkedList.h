#ifndef LINKED_LIST_H
#define LINKED_LIST_H 1

#ifndef TYPE
#define TYPE int
#endif

#ifndef LT
#define LT(A, B) ((A) < (B))
#endif

#ifndef EQ
#define EQ(A, B) ((A) == (B))
#endif

typedef struct LinkedList LinkedList, Deque, Bag;		// Creates the alliases LinkedList, Deque and Bag for the struct LinkedList
typedef struct Link Link;								// Creates the allias Link the struct Link

/* ************************************************************************
	Linked List Interface
************************************************************************ */

LinkedList* linkedListCreate();											// Allocates and initializes a linked list
void deletelinkedList(LinkedList* list);								// Deallocates every link in the list including the sentinels and deletes the list itself
int sizelinkedList(LinkedList* myList);									// Returns the size of the list
int isEmptyLinkedList(LinkedList* myList);								// Returns 1 if the list is empty and 0 otherwise
void addLinkBefore(LinkedList* list, TYPE value);	// Adds a new link with the given value before the given link and increments the list's size
void removeLink(LinkedList* list, TYPE value);					// Removes the given link from the list and decrements the list's size
void printLinkedList(LinkedList* list);									// Prints the values of the links in the list from front to back


/* ************************************************************************
	Deque Interface
************************************************************************ */

Deque* dequeCreate();							// Allocates and initializes the deque
void deleteDeque(Deque* myDeque);				// Deallocates the data and deletes the deque
int sizeDeque(Deque* myDeque);					// Returns the size of the deque
int isEmptyDeque(Deque* myDeque);				// Returns 1 if the deque is empty and 0 otherwise
void addFrontDeque(Deque* myDeque, TYPE value);	// Adds a new link with the given value to the front of the deque
void addBackDeque(Deque* myDeque, TYPE value);	// Adds a new link with the given value to the back of the deque
TYPE frontDeque(Deque* myDeque);				// Returns the value of the link at the front of the deque
TYPE backDeque(Deque* myDeque);					// Returns the value of the link at the back of the deque
void removeFrontDeque(Deque* myDeque);			// Removes the link at the front of the deque
void removeBackDeque(Deque* myDeque);			// Removes the link at the back of the deque
void printDeque(Deque* myDeque);				// Prints the values of the links in the deque from front to back


/* ************************************************************************
	Bag Interface
************************************************************************ */

Bag* bagCreate();							// Allocates and initializes the bag.
void deleteBag(Bag* myBag);					// Deallocates the data and deletes the bag
int sizeBag(Bag* myBag);					// Returns the size of the bag
int isBagEmpty(Bag* myBag);					// Returns "1" if the bag is empty or "0" if not 
void addBag(Bag* myBag, TYPE value);		// Adds an element into the bag
int containsBag(Bag* myBag, TYPE value);	// Returns "1" if the bag contains the specified element or "0" if not 
void removeBag(Bag* myBag, TYPE value);		// Removes the specific element from the bag
void printBag(Bag* myBag);					// Prints the values of the links in the bag from front to back

#endif
