
#include <stdio.h>
#include <stdlib.h>
#include "heap.h" 

void assertTrue(int predicate, char *message) 
{
	printf("%s: ", message);
	if (predicate)
		printf("PASSED\n");
	else
		printf("FAILED\n");
}


int main()
{
    TYPE heapTestData[] = {9, 3, 2, 4, 5, 7, 8, 6, 1, 0};
    int arrNum = sizeof(heapTestData) / sizeof(TYPE);
    DynArr* heap;
    heap = newDynArr(2);
    for(int i = 0; i < arrNum; i++)
        addDynArr(heap, heapTestData[i]);
    printf("Itil data, before heap: ");
    for (int i = 0; i < arrNum; i++)
        printf("   %d", getDynArr(heap, i));
    buildHeap(heap);
    printf("\nAfter Build, getHeapFirst: ");
    for (int i = 0; i < arrNum; i++)
    {
        printf("   %d", heapGetFist(heap));
        heapRemoveFirst(heap);
    }
    
    for(int i = 0; i < arrNum; i++)
        addDynArr(heap, heapTestData[i]);

    heapSort(heap);
    printf("\nsorted heap data: ");
    for (int i = 0; i < arrNum; i++)
        printf("   %d", getDynArr(heap, i));
}