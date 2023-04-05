/**********************************************************************************
 * Author:						MIN HO KIM, Baoxia Zhu
 * Date Created:				Oct. 10. 2022
 * Last Modificatio Date:
 * Filename:					DA_Stack_Bag,c
 *
 * Overview: Dynamic Array, Stack and Bag impementations
 *
 * Input, Output:
 *      1) Dynamic Arr: Input and Output for
 *						newDynArr Create, delete, size, add, get put swap, remove
 *      2) Stack:		Input and Output for
 *						newStackcreate, delete, sizem isEmpty, push, top, pop
 *		3) Bag:			Inpu and Output for
 *						newBag create, delete, size, isEmpty, add, contains, remove
 ***********************************************************************************/						

// DA_Stack_Bag.c: Dynamic Array, Stack and Bag implementations
#include <assert.h>
#include <stdlib.h>
#include "DA_Stack_Bag.h"


/* ************************************************************************
	Struct DynArr, Stack, Bag
************************************************************************ */
struct DynArr{
	TYPE* data;   // data array
	int size;
	int capacity;
	int startIndex; // This is for extra Credit, 10.17. hw
	DynArr* stackArray;  // stack and bag are all DynArr type. So, can recursively define
	DynArr* bagArray;
};


typedef struct deque{
	DynArr* dequeArray;
}deque;

/* ************************************************************************
	Dynamic Array Functions
************************************************************************ */




/**
 *  DynArr* newDynArr(int capacity)
 *	Entry: Array capacity
 *
 *  Output: memory allocation for dynamic memory
 *			initializing capacity from the inpu
 *			initializing size = 0
 *
 *  Ref:	capacity is the total size of array, size is the number of data
 */

DynArr* newDynArr(int capacity)
{
	assert(capacity >= 0);	
	DynArr* myDA = (DynArr*)malloc(sizeof(DynArr));  // Allocate for dynamic Array
													 // DynArr myDA = (DynArr*)m...
													 // modify DynArr* myDA = (DynArr*)m..,
	assert(myDA != NULL);							 // assert(Dynarr != .. modi assert(myDA
	myDA->size = 0;
	myDA->capacity = capacity;
	myDA->startIndex = 0;
	myDA->data = (TYPE*)malloc(sizeof(TYPE)*capacity);
	assert(myDA->data != NULL);
	return myDA;
}

deque* newDeque(int cap){
	deque* myDeque = (deque*)malloc(sizeof(deque));
	assert(myDeque != NULL);
	myDeque->dequeArray = newDynArr(cap);
	return myDeque;
}
//ntDeque(deque* myDeque, TYPE val)
TYPE getDynArrUsingQ(deque *myDeque, int position)
{
	assert(myDeque->dequeArray != NULL); // && sizeDynArr(myDA) != 0);
	assert(position >= 0);
	return myDeque->dequeArray->data[position];
}


/**
 * _dynArrSetCapacity(DynArr *myDA, int newCap)
 *	Entry: myDA, new capcity
 *
 *	Output: increase capacity of Dynamic Array.
 */

void _dynArrSetCapacity(DynArr *myDA, int newCap)
{
	assert(myDA != NULL && myDA->data != NULL);
	TYPE *newBuffer = (TYPE*)malloc(sizeof(TYPE)*newCap);// new data Array for dynamic array
														//TYPE* newBuffer = not (*TYPE) but (TYPE*)
	assert(newBuffer != NULL);							// Check Buffer allocation
	for(int i = 0; i < myDA->size; i++)					// chaeck sizeDynArr(myDA) instead of myDA->size
		newBuffer[i] = myDA->data[i];
	
	free(myDA->data);									// free memory for myDA
	myDA->data = newBuffer;
	myDA->capacity = newCap;	
}


void _dynArrQSetCapacity(deque* myDeque, int newCap)
{
	assert(myDeque->dequeArray != NULL && myDeque->dequeArray->data != NULL);
	TYPE *newBuffer = (TYPE*)malloc(sizeof(TYPE)*newCap);// new data Array for dynamic array
														//TYPE* newBuffer = not (*TYPE) but (TYPE*)
	assert(newBuffer != NULL);							// Check Buffer allocation
	for(int i = 0; i < myDeque->dequeArray->size; i++)					// chaeck sizeDynArr(myDA) instead of myDA->size
		newBuffer[i] = myDeque->dequeArray->data[i];
	
	free(myDeque->dequeArray);									// free memory for myDA
	myDeque->dequeArray->data = newBuffer;
	myDeque->dequeArray->capacity = newCap;	
}




void addFrontDeque(deque* myDeque, TYPE val){
	if(myDeque->dequeArray->size == myDeque->dequeArray->capacity)
		_dynArrQSetCapacity(myDeque, myDeque->dequeArray->capacity * 2);
	
	myDeque->dequeArray->startIndex--;

	if(myDeque->dequeArray->startIndex < 0)
		myDeque->dequeArray->startIndex  = myDeque->dequeArray->startIndex + myDeque->dequeArray->capacity;

	myDeque->dequeArray->data[myDeque->dequeArray->startIndex] = val;
	myDeque->dequeArray->size++;
}

void removeFrontDeque(deque* myDeque){
	assert(myDeque->dequeArray->size > 0); 
	myDeque->dequeArray->startIndex++;
	myDeque->dequeArray->size--;
}

/**
 *  addDynArr(DynArr *myDA, TYPE value)
 *  Entry: myDA, value added 
 *
 *  Output: Adds a value elemets to the end of the dynamic array */

void addDynArr(DynArr *myDA, TYPE value)
{
	assert(myDA != NULL && myDA->data != NULL);
	if(myDA->capacity <= myDA->size) 
		_dynArrSetCapacity(myDA, myDA->capacity *2); // if cap is less or same as size, multiply capacity 

	myDA->data[myDA->size++] = value;  // put an value element into dynamic array and inc size
} 

/**
 *  Nov.6. 2022 worksheet 26
 *  Entry:  
 *
 *  Output:  */
void orderedArrayAdd(DynArr *myDA, TYPE newElement)
{
	int index = binarySearch(myDA->data, myDA->size, newElement);
	dyArrayAddAt(myDA, index, newElement);
}

/**
 *  Nov.6. 2022 worksheet 26
 *  Entry:  
 *
 *  Output:  */
void dyArrayAddAt(DynArr *myDA, int index, TYPE newElement)
{
	assert(index >= 0 && index <= myDA->size);
	if(myDA->size >= myDA->capacity)
		_dynArrSetCapacity(myDA, myDA->capacity *2); // if cap is less or same as size, multiply capacity 

	for(int i = myDA->size ; i > index ; i--)
	{
		myDA->data[i] = myDA->data[i-1];
	}
	myDA->data[index] = newElement;  // put an value element into dynamic array and inc size
	myDA->size++;
}

/**
 * void deleteDynArr(DynArr *myDA)
 * Entry: myDA
 *
 * Output: Deallocates the date and deletes the dynamic array
 * Ref:	distict from removeAt
 */
void deleteDynArr(DynArr *myDA)
{
	assert(myDA != NULL && myDA->data != NULL);

	free(myDA->data);
	free(myDA);
}
/**
 * sizeDynArr(DynArr *myDA)
 * Entry: myDA
 *
 * Output: Returns the size of dynamic array
 * */

int sizeDynArr(DynArr *myDA)
{
	assert(myDA !=NULL);
	return myDA->size;
}

/**
 * TYPE getDynArr(DynArr *myDA, int position
 * Entry: myDA, data position to get
 *
 * Output: return a data at specific position
 */
TYPE getDynArr(DynArr *myDA, int position)
{
	assert(myDA != NULL && sizeDynArr(myDA) != 0);
	assert(position >= 0 && position < sizeDynArr(myDA));
	return myDA->data[position];
}

/** void putDynArr(DynArr *myDA, int position TYPE value)
 * Entry: myDA, position of data inputed, input data
 *
 * Output: put an element into the dynamic array at data position
 *		 overwriting the element that was there
 */
void putDynArr(DynArr *myDA, int position, TYPE value)
{
	assert(myDA != NULL && myDA->data != NULL);
	assert(position >= 0 && position < sizeDynArr(myDA));
	myDA->data[position] = value;
}

/** void swapDynArr(DynArr *myDA, int idx_i, int idx_j)
 * Entry: myDA, swap index i, j
 *
 * Oupput: Swap two specified elements in the dynamic arrya
 */
void swapDynArr(DynArr *myDA, int idx_i, int idx_j)
{
	assert(myDA != NULL && myDA->size > 1);         // size > 1: Array have at leat more two datas
	assert(idx_i >= 0 && idx_i < sizeDynArr(myDA));
	assert(idx_j >= 0 && idx_j < sizeDynArr(myDA));

	TYPE temp = 0;
	temp = myDA->data[idx_i];
	myDA->data[idx_i] = myDA->data[idx_j];
	myDA->data[idx_j] = temp;
} 
/** removeAtDynArr(DynArr *myDA, int idx_i)
 *	Entry: myDA, the address of element to remove
 * 
 *  Outpur: Removes the element at the specified location from the array and shift all the following elements back one spot to fill the gap
 */
void removeAtDynArr(DynArr *myDA, int idx_i)
{
	assert(myDA != NULL && myDA->data != NULL);
	assert(idx_i >= 0 && idx_i < sizeDynArr(myDA));
	myDA->size = myDA->size - 1;					// first dec size because i = i + 1	
	
	for(int i = idx_i; i < myDA->size; i++)
		myDA->data[i] = myDA->data[i+1];
}

/* ************************************************************************
	Stack Interface Functions
************************************************************************ */
/** Stack* newStack(int capacity)
 *  Entry: capacity, define the size of the stack
 *
 *  Output: Allocate and initializes the stack
 */
Stack* newStack(int capacity)
{
	Stack* myStack = (Stack*)malloc(sizeof(Stack));
	assert(myStack != NULL); 
//	DynArr* stackDynArr = (DynArr*)malloc(sizeof(DynArr));
	myStack->stackArray = newDynArr(capacity);	
	return myStack;
}

/**
 * void pushStack(Stack *myStack, TYPE value)
 * Entry: get value into DynArr of myStack
 *
 * Output: Push an element onto the top of the stack  
 */
void pushStack(Stack *myStack, TYPE value)
{
	assert(myStack != NULL);
	addDynArr(myStack->stackArray, value);	// Use DynArr function because DynArr is in myStack
}

/** int sizeStack(Stack* myStack)
 *
 * Outout: Return the size of stack
 */
int sizeStack(Stack* myStack)
{
	assert(myStack != NULL);
	return sizeDynArr(myStack->stackArray);
}
/** int isStackEmpty(Stack *myStack)
 *
 * Output: Returns "1" if the stack is empty or "0" if not
 */
int isStackEmpty(Stack* myStack)
{
	assert(myStack != NULL);
	int stackTop = sizeStack(myStack) - 1;
	if(stackTop< 0)
	{
		return 1;
	}
	return 0;	
}

/**
 * void popStack(Stack *myStack)
 * Entry: myStack
 *
 * Output: Removes the elemet on top of the stack
 */
void popStack(Stack *myStack)
{
	assert(myStack != NULL);
	if(!isStackEmpty(myStack))
	{	
		int stackTop = sizeStack(myStack) - 1;
		removeAtDynArr(myStack->stackArray, stackTop);  // FILO, So remove the top
	}else{
//		printf("... can not pop, pushStack first! \n");

	}
}

/** TYPE topStack(Stack *myStack)
 * Entry: myStack 
 *
 * Output: returns the elemet at the top of the stack 
 */
TYPE topStack(Stack *myStack)
{
	assert(myStack != NULL);
	int stackTop = sizeStack(myStack) - 1;
	return getDynArr(myStack->stackArray, stackTop);
}


/** deleteStack(DynArr *myStack)
 *
 *  Output: Deallocate the data and deletes the dynamic array
 */
void deleteStack(Stack *myStack)
{
	deleteDynArr(myStack->stackArray);
	free(myStack);
} 
/* ************************************************************************
	Bag Interface Functions
************************************************************************ */
/** Bag *newBag(int capacity
 * Definition: Maintains an unordered collection of elements
 * Result: Allocates and initializes the bag
 */
Bag* newBag(int capacity)
{
	Bag* myBag = (Bag*)malloc(sizeof(Bag));
	assert(myBag != NULL);
	myBag->bagArray = newDynArr(capacity);
	return myBag;
}

/** addBag(Bag *myBag, TYPE value
 *
 * Result: Adds an element into the bag
 */
void addBag(Bag *myBag, TYPE value)
{
	assert(myBag != NULL);
	addDynArr(myBag->bagArray, value);
}


TYPE getBag(Bag *myBag, int position)
{
	assert(myBag != NULL);
	return getDynArr(myBag->bagArray, position);
}


void addOrderedBag(Bag *myBag, TYPE value)
{
	assert(myBag != NULL);
	orderedArrayAdd(myBag->bagArray, value);
}


/** int sizeBag(Bag* myBag)
 *
 * Output: Return the size of bag 
 */
int sizeBag(Bag* myBag)
{
	assert(myBag != NULL && myBag->bagArray != NULL);
	return sizeDynArr(myBag->bagArray);
}

/** int isBagEmpty(Bag *myBag)
 *
 * Output: Returns "1" if the Bag is empty or "0" if not
 */
int isBagEmpty(Bag* myBag)
{
	assert(myBag != NULL);
	int bagSize = sizeBag(myBag);
	if(bagSize <= 0)
	{
		return 1;
	}
	return 0;	
}

/** int containsBag(Bag *myBag, TYPE value)
 *
 * Result: Returns "1" if the bag contains the specified element or "0" if not
 */
int containsBag(Bag *myBag, TYPE value)
{
	assert(myBag != NULL && myBag->bagArray != NULL);
	int bagSize = sizeBag(myBag);
	for(int i = 0; i < bagSize; i++)
	{
		if(value == myBag->bagArray->data[i]) // if Bag contains data same as valus
			return 1;                         // return 1
	}

	return 0;
}

int orderedArrayContains (Bag *myBag, TYPE testElement)
{
	int search_index =  binarySearch(myBag->bagArray->data, myBag->bagArray->size, testElement);
	return (testElement == myBag->bagArray->data[search_index]) ? 1 : 0;
}	

/** void removeBag(Bag *myBag, TYPE value)
 *
 * Remove the specific element from the bag and shift all the following elements back one spot to fil the gap
 */
void removeBag(Bag *myBag, TYPE value)
{
	assert(myBag != NULL && myBag->bagArray != NULL);
	int rmDataIndex = -1;
	int bagSize = sizeBag(myBag);
	for(int i = 0; i < bagSize; i++)
	{
		if(value == myBag->bagArray->data[i])
			rmDataIndex = i;		
	}
	
	if(rmDataIndex > -1)
		removeAtDynArr(myBag->bagArray, rmDataIndex);
}
void orderedArrayRemove (Bag* myBag, TYPE testElement) 
{
	int search_index = binarySearch(myBag->bagArray->data, myBag->bagArray->size, testElement);
	removeAtDynArr(myBag->bagArray, search_index);
}

/** deleteBag(DynArr *myBag)
 *
 *  Output: Deallocate the data and deletes the dynamic array
 */
void deleteBag(Bag* myBag)
{
	deleteDynArr(myBag->bagArray);
	free(myBag);
}
/* 2022. 11. 6. worksheet 
binary search

*/
int binarySearch(TYPE* data, int size, TYPE testValue)
{
	int low = 0;
	int high = size;
	int mid;

	while(low < high){
		mid = (low + high) / 2;
		if(LT(data[mid], testValue))
			low = mid + 1;
		else 
			high = mid;
	}

	return low;
}
