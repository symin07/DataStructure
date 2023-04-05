// DA_Stack_Bag.h : Dynamic Array, Stack and Bag interfaces

#ifndef DYNAMIC_ARRAY_INCLUDED		// Makes sure that the header file is included only once
#define DYNAMIC_ARRAY_INCLUDED 1

#ifndef TYPE						// Defines the type and the size of the elements in the dynamic array, stack and bag
# define TYPE      int				
# define TYPE_SIZE sizeof(TYPE)
#endif

#ifndef LT							// Defines the lower than (LT) function for the dynamic array
# define LT(A, B) ((A) < (B))
#endif

#ifndef EQ							// Defines the equality (EQ) (or else compare) function for the dynamic array
# define EQ(A, B) ((A) == (B))
#endif

typedef struct DynArr DynArr, Stack, Bag;		// Creates the alliases DynArr, Stack and Bag for the struct DynArr

typedef struct deque deque;

/* ************************************************************************
	Dynamic Array Interface
************************************************************************ */

DynArr* newDynArr(int capacity);						// Allocates and initializes dynamic array.
void deleteDynArr(DynArr *myDA);						// Deallocates the data and deletes the dynamic array
int sizeDynArr(DynArr *myDA);							// Returns the size of the dynamic array
void addDynArr(DynArr *myDA, TYPE value);				// Adds an element to the end of the dynamic array
void orderedArrayAdd(DynArr *myDA, TYPE newElement);
void dyArrayAddAt(DynArr *myDA, int index, TYPE newElement);
TYPE getDynArr(DynArr *myDA, int position);				// Gets an element from the dynamic array from a specified position
void putDynArr(DynArr *myDA, int position, TYPE value);	// Puts an element into the dynamic array at the specified location overwriting the element that was there.
void swapDynArr(DynArr *myDA, int idx_i, int  idx_j);	// Swaps two specified elements in the dynamic array
void removeAtDynArr(DynArr *myDA, int idx_i);			// Removes the element at the specified location from the array and shifts all the following elements back one spot to fill the gap


 // 10. 17 Dynamic Array Test
deque* newDeque(int capacity);   
void _dynArrQSetCapacity(deque* myDeque, int newCap);
void addFrontDeque(deque* myDeque, TYPE val);
void removeFrontDeque(deque* myDeque);
TYPE getDynArrUsingQ(deque *myDeque, int position);

/* ************************************************************************
	Stack Interface
************************************************************************ */

Stack *newStack(int capacity);							// Allocates and initializes the stack.
void deleteStack(Stack *myStack);						// Deallocate the data and deletes the stack
int sizeStack(Stack *myStack);							// Returns the size of the stack
int isStackEmpty(Stack *myStack);						// Returns "1" if the stack is empty or "0" if not 
void pushStack(Stack *myStack, TYPE value);				// Push an element onto the top of the stack
TYPE topStack(Stack *myStack);							// Returns the element at the top of the stack 
void popStack(Stack *myStack);							// Removes the element on top of the stack


/* ************************************************************************
	Bag Interface
************************************************************************ */

Bag *newBag(int capacity);								// Allocates and initializes the bag.
void deleteBag(Bag *myBag);								// Deallocate the data and deletes the bag
int sizeBag(Bag *myBag);								// Returns the size of the bag
int isBagEmpty(Bag *myBag);								// Returns "1" if the bag is empty or "0" if not 
void addBag(Bag *myBag, TYPE value);					// Adds an element into the bag
void addOrderedBag(Bag *myBag, TYPE value);
TYPE getBag(Bag *myBag, int position);
int orderedArrayContains (Bag *myBag, TYPE testElement);
int containsBag(Bag *myBag, TYPE value);				// Returns "1" if the bag contains the specified element or "0" if not 
void removeBag(Bag *myBag, TYPE value);					// Remove the specific element from the bag and shifts all the following elements back one spot to fill the gap
void orderedArrayRemove (Bag* myBag, TYPE testElement);
int binarySearch(TYPE* data, int size, TYPE testValue);

#endif
