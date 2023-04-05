/*
 * In this file, you will write the structures and functions needed to
 * implement a priority queue.  Feel free to implement any helper functions
 * you need in this file to implement a priority queue.  Make sure to add your
 * name and @oregonstate.edu email address below:
 *
 * Name: MIN HO KIM
 * Email: kimminh@oregonstate.edu
 */

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "pq.h"
#include "dynarray.h"
#include "structs.h"
/*
 * This is the structure that represents a priority queue
 */

struct pq
{
  struct dynarray* dyn_array;
};


/*
* Struct to store the elements of the priority queue
*/
struct node
{
    void* value;
    int priority;
};





/*
 * This function should allocate and initialize an empty priority queue and
 * return a pointer to it.
 */

pq* createPq()
{    
    // FIXME
    pq* new_queue = (pq*)malloc(sizeof(pq));
    new_queue->dyn_array = dynarray_create();
    return new_queue;
}


/*
 * This function should free the memory allocated to a given priority queue
 */
void freePq(pq* myPq)
{
  dynarray_free(myPq->dyn_array);
  free(myPq);
}

/*
 * This function should return 1 if the specified priority queue is empty and
 * 0 otherwise.
 */

int isemptyPq(pq* myPq)
{
    assert(myPq != NULL);
    if(dynarray_size(myPq->dyn_array) == 0)
      return 1;
    else
      return 0;
	
}

int _compare(void* left, void* right)
{
  node* leftComp = (node*)left;
  node* rightComp = (node*)right;
  
  if(leftComp->priority > rightComp->priority)
    return 1;
  else if(leftComp->priority < rightComp->priority)
    return -1;
  else
    return 0;
}

void _swap(pq* myPq, int i, int j)
{
    node* temp = dynarray_get(myPq->dyn_array, i);
    dynarray_set(myPq->dyn_array, i, dynarray_get(myPq->dyn_array, j));
    dynarray_set(myPq->dyn_array, j, temp);
}  
/*
 * This function should add a given element into a priority queue with a
 * specified priority value.
 */

void addPq(pq* myPq, void* value, int priority)
{
  // FIXME
  assert(myPq != NULL);
  node* toDo = (node*)malloc(sizeof(node));
  assert(toDo != NULL);
  toDo->value = value;
  toDo->priority = priority;
  
  dynarray_insert(myPq->dyn_array, toDo);
  int nvIdx = dynarray_size(myPq->dyn_array) - 1;
  int parentIdx = (nvIdx - 1) / 2;
  while (nvIdx > 0)
  {
    if(_compare(dynarray_get(myPq->dyn_array, parentIdx), 
                  dynarray_get(myPq->dyn_array, nvIdx)) == 1)
      _swap(myPq, parentIdx, nvIdx);
    nvIdx = parentIdx;
    parentIdx = (nvIdx - 1) / 2; 
  }
}


/*
 * This function should return the value of the item with lowest priority
 *
 */

void* getPq(pq* myPq)
{
  //FIXME
  assert(myPq != NULL);
  //void* getTask = malloc(sizeof(node));
  node* getTask = (node*) dynarray_get(myPq->dyn_array, 0);
  if(dynarray_size(myPq->dyn_array) > 0)
    return getTask;
  else 
    return NULL;
}


void _downHeap(pq* myPq, int size)
{
    int curIdx = 0;
    int chdIdx;
    int internalCond = size/2 - 1;    // internal node condtion
    while (curIdx <= internalCond)    // while curIdx is internal node 
    {
        int leftChdIdx = curIdx * 2 + 1;
        int rightChdIdx = curIdx * 2 + 2;
        if (rightChdIdx == size) 
            chdIdx = leftChdIdx;   
        else if(_compare(dynarray_get(myPq->dyn_array, leftChdIdx), 
                  dynarray_get(myPq->dyn_array, rightChdIdx)) == 1)
            chdIdx = rightChdIdx;
        else
            chdIdx = leftChdIdx;    
        if(_compare(dynarray_get(myPq->dyn_array, curIdx), 
                  dynarray_get(myPq->dyn_array, chdIdx)) == 1)
            _swap(myPq, curIdx, chdIdx);
        curIdx = chdIdx;
    }
}

/*
 * This function should remove the value with lowest priority 
 */

void removePq(struct pq* myPq)
{
   int last = dynarray_size(myPq->dyn_array) - 1;
    if(last != 0)
         dynarray_set(myPq->dyn_array, 0, dynarray_get(myPq->dyn_array, last));
    dynarray_remove(myPq->dyn_array, last);

    _downHeap(myPq, dynarray_size(myPq->dyn_array));
   
}


/*
 * This function should print the values that are in the pq
 * and their priorities on the screen
 * from the queue.
 */
void printPq(struct pq* myPq)
{
  // FIXME
  assert(myPq != NULL);
  for(int i = 0; i < dynarray_size(myPq->dyn_array); i++)
  {
    //task* getTask = (task*)dynarray_get(myPq->dyn_array, i);
    node* getTask = (node*)dynarray_get(myPq->dyn_array, i);
    // char* data2 = (char*) data->value; 
   // _printPq(data);
    printf("task: %s", (char*)getTask->value);
    printf(", priority: %d\n", getTask->priority);
  }  
}