#include "..\\DynamicArray\\DA_Stack_Bag.h"

#ifndef HEAP_H
#define HEAP_H 1



/* ************************************************************************
	HEAP interface
************************************************************************ */

void swap(struct DynArr* v, int i, int j);  
int indexSmallest(struct DynArr *v, int i, int j);
TYPE heapGetFist(struct DynArr *heap);
void heapRemoveFirst(struct DynArr *heap);
void heapAdd(struct DynArr* heap, TYPE newValue);
void buildHeap(struct DynArr *heap);
void heapSort(struct DynArr* v);
# endif
