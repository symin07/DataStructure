#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef TYPE
#define TYPE int
#endif 


typedef struct dlink {
     TYPE value;
    struct dlink * next;
    struct dlink * prev;
}dlink;

typedef struct linkedList {
    int size;
    struct dlink * frontSentinel;
    struct dlink * backSentinel;
}linkedList;

/* these functions are written for you */ 
void LinkedListInit (struct linkedList *q) 
{
    q->frontSentinel = (struct dlink *) malloc(sizeof(struct dlink));
     assert(q->frontSentinel != 0);
    q->backSentinel = (struct dlink *) malloc(sizeof(struct dlink)); 
    assert(q->backSentinel);
    q->frontSentinel->next = q->backSentinel; 
    q->backSentinel->prev = q->frontSentinel; 
    q->frontSentinel->prev = q->frontSentinel;
    q->backSentinel->next = q->backSentinel;
    q->size = 0;
}


/* _addLink places a new link BEFORE the provide link, lnk */ 

void _addLink (struct linkedList *q, struct dlink *lnk, TYPE e) {

    dlink* newLink = (dlink*)malloc(sizeof(dlink));
    assert(newLink != NULL);
    newLink->value = e;
    newLink->next = NULL;
    if(lnk == q->frontSentinel->next)
    {
        newLink->next = q->frontSentinel->next;
        newLink->prev = q->frontSentinel->next->prev;
        q->frontSentinel->next->prev = newLink;
        q->frontSentinel->next = newLink;
    }else if(lnk == q->backSentinel){
        newLink->prev = q->backSentinel->prev;
        newLink->next = q->backSentinel->prev->next;
        q->backSentinel->prev->next = newLink;
        q->backSentinel->prev = newLink; 
    }
    q->size = q->size + 1;
}

void _removeLink (struct linkedList *q, struct dlink *lnk) {
    assert(q->size != 0);
     dlink* removed;
    if(lnk == q->frontSentinel->next)
    {
        removed = q->frontSentinel->next;
        q->frontSentinel->next = q->frontSentinel->next->next;
        q->frontSentinel->next->prev = q->frontSentinel->next->prev->prev;
        free(removed);   
    }else if(lnk == q->backSentinel){
        
        removed = q->backSentinel->prev;
        q->backSentinel->prev = q->backSentinel->prev->prev;
        q->backSentinel->prev->next =  q->backSentinel->prev->next->next;
        free(removed);
    }

    q->size = q->size - 1;

}


void linkedListRemoveFront (struct linkedList *q) 
{ 
    //assert(linkedListIsEmpty(q) != 1);
    _removeLink (q, q->frontSentinel->next);
}

void LinkedListRemoveBack (struct linkedList *q) { 
   // assert(! linkedListIsEmpty(q));
    _removeLink (q, q->backSentinel);
}

void linkedListFree (struct linkedList *q) {
     while (q->size > 0)
        linkedListRemoveFront(q); 
    free (q->frontSentinel);
    free (q->backSentinel);
    q->frontSentinel = q->backSentinel = NULL;
    free(q);
}

void LinkedListAddFront (struct linkedList *q, TYPE e)
{ 
    _addLink(q, q->frontSentinel->next, e); 
}

void LinkedListAddBack (linkedList *q, TYPE e)
{ 
    _addLink(q, q->backSentinel, e); 
}



int LinkedListIsEmpty (struct linkedList *q) { 
    return q->size == 0;
}
 
/* write addLink and removeLink. Make sure they update the size field correctly */

int LinkedListIsEmptyII (struct linkedList *q) { 
    return (q->frontSentinel->next == q->backSentinel); 
}


TYPE LinkedListFront (struct linkedList *q) {
    assert(q != NULL);
    return q->frontSentinel->next->value;
}

TYPE LinkedListBack (struct linkedList *q) {
    assert(q != NULL);
    return q->backSentinel->prev->value;
}
void printList(linkedList* q)
{
    struct dlink* iterator = q->frontSentinel->next;
    printf("printList:       ");
    while(iterator != q->backSentinel)
    {
        printf("   %d", iterator->value);
        iterator = iterator->next;
    }
    printf("\n");
}

int main()
{
    linkedList* q = (linkedList*)malloc(sizeof(linkedList));
    assert(q != NULL);
    LinkedListInit(q);

    LinkedListAddFront(q, 3);
    LinkedListAddFront(q, 2);
    LinkedListAddFront(q, 1);

    printf("expected 1 2 3 \n");
    printList(q);
    LinkedListAddBack(q, 10);
    LinkedListAddBack(q, 11);
    LinkedListAddBack(q, 12);
     
    printf("expected 1 2 3 10 11 12    \n");
    printList(q);

    LinkedListRemoveBack (q);    
    LinkedListRemoveBack (q);

    printf("expected 1 2 3 10    \n");
    printList(q);

    printf("expected 10 == %d \n",LinkedListBack(q));
    linkedListRemoveFront (q);
    linkedListRemoveFront (q);
    
    printf("expected 3 10    \n");
    printList(q);

    printf("expected 3 == %d \n",LinkedListFront(q));

    linkedListRemoveFront (q);
    linkedListRemoveFront (q);

    if(LinkedListIsEmpty(q))
        printf("The linkedList is empty \n");
    
    if(LinkedListIsEmptyII(q))
        printf("The linkedList is empty II \n");

    return 0;
}
