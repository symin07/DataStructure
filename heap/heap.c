#include <assert.h>
#include "heap.h"
#include "..\\DynamicArray\\DA_Stack_Bag.h"


/*
TYPE getDynArr(DynArr *myDA, int position)
{
	assert(myDA != NULL && sizeDynArr(myDA) != 0);
	assert(position >= 0 && position < sizeDynArr(myDA));
	return myDA->data[position];
}

void putDynArr(DynArr *myDA, int position, TYPE value)
{
	assert(myDA != NULL && myDA->data != NULL);
	assert(position >= 0 && position < sizeDynArr(myDA));
	myDA->data[position] = value;
}
*/


void swap(struct DynArr* v, int i, int j)
{
    TYPE temp = getDynArr(v, i);
    putDynArr(v, i, getDynArr(v,j));
    putDynArr(v, j, temp);
}  
int indexSmallest(struct DynArr *v, int i, int j) // Acually smaller
{
    if(LT(getDynArr(v,i), getDynArr(v,j)))
        return i;
    return j;
}
TYPE heapGetFist(struct DynArr *heap)
{
    assert(sizeDynArr(heap) > 0);
    return getDynArr(heap, 0);
}

void _adjustHeap(struct DynArr* heap, int size, int root)
{
    int curIdx = root;
    int chdIdx;
    
    while (curIdx <= (size/2 -1))    // while internal node 
    {
        int leftChdIdx = curIdx * 2 + 1;
        int rightChdIdx = curIdx * 2 + 2;
        if (rightChdIdx == size) 
            chdIdx = leftChdIdx;
        else if(leftChdIdx == indexSmallest(heap, leftChdIdx, rightChdIdx))
            chdIdx = leftChdIdx;
        else
            chdIdx = rightChdIdx;    
        if(chdIdx == indexSmallest(heap, curIdx, chdIdx))
            swap(heap, curIdx, chdIdx);
        curIdx = chdIdx;
    }
}
void heapRemoveFirst(struct DynArr *heap)
{
    int last = sizeDynArr(heap) - 1;
    if(last != 0)
        putDynArr(heap, 0, getDynArr(heap, last));
    removeAtDynArr(heap, last);
    _adjustHeap(heap, sizeDynArr(heap), 0);
}
void heapAdd(struct DynArr* heap, TYPE newValue)
{
    addDynArr(heap, newValue);
    int addrNewVal = sizeDynArr(heap) - 1;
    int addrParentVal = (addrNewVal - 1) / 2;
    while(addrNewVal != 0)
    {
       
        if(addrNewVal == indexSmallest(heap, addrNewVal, addrParentVal))
            swap(heap, addrNewVal, addrParentVal);
        addrNewVal = addrParentVal;
        addrParentVal = (addrNewVal - 1) / 2;
    }    
}

void buildHeap(struct DynArr* heap)
{
    int max = sizeDynArr(heap);
    for(int i = max/2-1; i >= 0; i--)
        _adjustHeap(heap, max, i);
}

void heapSort(struct DynArr* v)
{
    buildHeap(v);
    for (int i = sizeDynArr(v) -1; i > 0; i--)
    {
        swapDynArr(v, 0, i);
        _adjustHeap(v, i, 0);
    }
}

 //if(heap->data[addrNewVal] < heap->data[addrParentVal])  Impossible to access directly
        //    swap(heap, addrNewVal, addrParentVal);
        //if(getDynArr(heap, addrNewVal) < getDynArr(heap, addrParentVal))  erase for heapFunction use
        //    swap(heap, addrNewVal, addrParentVal);

