/* tests.c
   This file is used for testing the dynamic array, the stack and the bag implementations. 
   This test suite is by no means complete or thorough.
   More testing is needed on your own, and more tests will be performed by the TA.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "DA_Stack_Bag.h"

void assertTrue(int predicate, char *message) 
{
	printf("%s: ", message);
	if (predicate)
		printf("PASSED\n");
	else
		printf("FAILED\n");
}
int main(int argc, char* argv[])
{

	DynArr *myDA;
	myDA = newDynArr(2);

/* ************************************************************************
	Dynamic Array Tests
************************************************************************ */

	printf("\n\nTesting addDynArr...\n");
	addDynArr(myDA, 3);
	addDynArr(myDA, 4);
	addDynArr(myDA, 10);
	addDynArr(myDA, 5);
	addDynArr(myDA, 6);
	addDynArr(myDA, 88);	
	printf("The array's content: [3,4,10,5,6]\n");
	assertTrue(EQ(getDynArr(myDA, 0), 3), "Test 1st element == 3");
	assertTrue(EQ(getDynArr(myDA, 1), 4), "Test 2nd element == 4");
	assertTrue(EQ(getDynArr(myDA, 2), 10), "Test 3rd element == 10");
	assertTrue(EQ(getDynArr(myDA, 3), 5), "Test 4th element == 5");
	assertTrue(EQ(getDynArr(myDA, 4), 6), "Test 5th element == 6");
	assertTrue(EQ(getDynArr(myDA, 5), 88), "Test 6th element == 88");
	assertTrue(sizeDynArr(myDA) == 6, "Test size = 6");
	
	printf("\n\nTesting putDynArr...\nCalling putDynArr(myDA, 2, 7)\n");
	putDynArr(myDA, 2, 7); 
	printf("The array's content: [3,4,7,5,6]\n");
	assertTrue(EQ(getDynArr(myDA, 2), 7), "Test 3rd element == 7");
	assertTrue(sizeDynArr(myDA) == 5, "Test size = 5");
	
	printf("\n\nTesting swapDynArr...\nCalling swapDynArr(myDA, 2, 4)\n");
	swapDynArr(myDA, 2, 4);
	printf("The array's content: [3,4,6,5,7]\n");
	assertTrue(EQ(getDynArr(myDA, 2), 6), "Test 3rd element == 6");
	assertTrue(EQ(getDynArr(myDA, 4), 7), "Test 5th element == 7");
	
	printf("\n\nTesting removeAtDynArr...\nCalling removeAtDynArr(myDA, 1)\n");
	removeAtDynArr(myDA, 1);
	printf("The array's content: [3,6,5,7]\n");
	assertTrue(EQ(getDynArr(myDA, 0), 3), "Test 1st element == 3");
	assertTrue(EQ(getDynArr(myDA, 3), 7), "Test 4th element == 7");
	assertTrue(sizeDynArr(myDA) == 4, "Test size = 4");
	
	deleteDynArr(myDA);
	
/* ************************************************************************
	Stack Tests
************************************************************************ */
	
	Stack *myStack;
	myStack = newStack(2);
	
	printf("\n\nTesting stack interface...\n");
	pushStack(myStack, 3);
	pushStack(myStack, 6);
	pushStack(myStack, 5);
	pushStack(myStack, 7);
	printf("The stack's content: [3,6,5,7] <- top\n");
	assertTrue(!isStackEmpty(myStack), "Testing isStackEmpty");
	assertTrue(sizeStack(myStack) == 4, "Test size = 4");
	assertTrue(EQ(topStack(myStack), 7), "Test topStack == 7");
	
	popStack(myStack);
	printf("Poping...\nThe stack's content: [3,6,5] <- top\n");
	assertTrue(sizeStack(myStack) == 3, "Test size = 3");
	assertTrue(EQ(topStack(myStack), 5), "Test topStack == 5");
	
	pushStack(myStack, 9);
	printf("Pushing 9...\nThe stack's content: [3,6,5,9] <- top\n");
	assertTrue(sizeStack(myStack) == 4, "Test size = 4");
	assertTrue(EQ(topStack(myStack), 9), "Test topStack == 9");
	assertTrue(EQ(topStack(myStack), 9), "test topStack == 5");	
	deleteStack(myStack);
	
/* ************************************************************************
	Bag Tests
************************************************************************ */
	
	Bag *myBag;
	myBag = newBag(2);
	/*
	printf("\n\nTesting bag interface...\n");
	addBag(myBag, 3);
	addBag(myBag, 6);
	addBag(myBag, 5);
	addBag(myBag, 9);

	
	printf("The bag's content: [3,6,5,9]\n");
	assertTrue(!isBagEmpty(myBag), "Testing isBagEmpty");
	assertTrue(sizeBag(myBag) == 4, "Test size = 4");
	assertTrue(containsBag(myBag, 3), "Test containing 3");
	assertTrue(containsBag(myBag, 6), "Test containing 6");
	assertTrue(containsBag(myBag, 5), "Test containing 5");
	assertTrue(containsBag(myBag, 9), "Test containing 9");
	assertTrue(!containsBag(myBag, 7), "Test not containing 7");
	
	removeBag(myBag, 3);
	printf("Removing 3...\nThe bag's content: [6,5,9]\n");
 	assertTrue(!containsBag(myBag, 3), "Test not containing 3");
	
    deleteBag(myBag); 
	*/
/* ************************************************************************
	Ordered Bag Tests
************************************************************************ */
	
	
	//myBag = newBag(2);
	printf("\n\nTesting bag interface...\n");
	addOrderedBag(myBag, 2);
	addOrderedBag(myBag, 7);
	addOrderedBag(myBag, 1);
	addOrderedBag(myBag, 10);
	addOrderedBag(myBag, 5);
	addOrderedBag(myBag, 14);
	addOrderedBag(myBag, 4);

	assertTrue(EQ(getBag(myBag, 0), 1), "Test 1st element == 1");
	assertTrue(EQ(getBag(myBag, 1), 2), "Test 2nd element == 2");
	assertTrue(EQ(getBag(myBag, 2), 4), "Test 3rd element == 4");
	assertTrue(EQ(getBag(myBag, 3), 5), "Test 4th element == 5");
	assertTrue(EQ(getBag(myBag, 4), 7), "Test 5th element == 7");
	assertTrue(EQ(getBag(myBag, 5), 10), "Test 6th element == 10");
	assertTrue(EQ(getBag(myBag, 6), 14), "Test 7th element == 14");
	assertTrue(orderedArrayContains(myBag, 7), "Test containing 7");
	orderedArrayRemove(myBag, 7);
	assertTrue(!orderedArrayContains(myBag, 7), "Test not containing 7");
	//assertTrue(EQ(getDynArr(myDA, 5), 10), "Test 6th element == 88");

	deleteBag(myBag); 
	return 0;
}
