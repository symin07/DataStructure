/***********************************************************
* Author: Gunnar Egge
* Email: eggeg@oregonstate.edu
* Date Created:  10/19/2022
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
struct LinkedList{
	struct Link *first_link;
	struct Link *last_link;
	int size;


};

struct Link
{
	struct Link *next_link;
	struct Link *previous_link;
	TYPE value;

};


/* ************************************************************************
	Linked List Functions
************************************************************************ */
LinkedList* linkedListCreate(){

	
    LinkedList* newLinkedList = (LinkedList*) malloc(sizeof(LinkedList)); 
    assert(newLinkedList != NULL); 
    newLinkedList->size = 0;
    newLinkedList->first_link = (Link*) malloc(sizeof(Link));
	newLinkedList->last_link = (Link*) malloc(sizeof(Link));
	newLinkedList->first_link->next_link = newLinkedList->last_link;
	newLinkedList->last_link->next_link = NULL;
	newLinkedList->first_link->value = 0;
	newLinkedList->last_link->value = 0;
    
    return newLinkedList;
}											
void deletelinkedList(LinkedList* list){

	assert(list != NULL); 

	if(list->first_link->next_link != list->last_link){

		Link *next_link = list->first_link->next_link;
		Link *curr_link = list->first_link->next_link;

		while(curr_link != list->last_link){
			next_link = curr_link->next_link;
			free(curr_link);
			curr_link = next_link;
		}
	}
	free(list->last_link);
	free(list->first_link);
    free(list); 

}
int sizelinkedList(LinkedList* myList){
	return myList->size;
}
int isEmptyLinkedList(LinkedList* myList){
	assert(myList != NULL);
	if(myList->size != 0){
		return 0;
	}
	return 1;
}

//adds a new link before the given value
void addLinkBefore(LinkedList* list, TYPE value){
	Link *new_link = (Link*) malloc(sizeof(Link));
	new_link->value = value;
	 //value variable inside new link is set to passed in value.

	Link *temp_curr_link = list->first_link;
	Link *temp_next_link = temp_curr_link->next_link;
	
	while(temp_next_link != list->last_link){
		temp_curr_link = temp_next_link;
		temp_next_link = temp_curr_link->next_link;
	}
	new_link->next_link = temp_curr_link->next_link;
	temp_curr_link->next_link = new_link;
	list->size++;
	return;
}


void removeLink(LinkedList* list, TYPE value){
	Link *temp_curr_link = list->first_link->next_link;
	Link *temp_next_link = temp_curr_link->next_link;
	if(list->size == 0){
		return;
	}
	if(temp_curr_link->value == value){
		list->first_link->next_link = temp_next_link;
		free(temp_curr_link);
		list->size--;
	}
	while(temp_next_link->value != value){
		if(temp_next_link->next_link == NULL){
			return;
		}
		temp_curr_link = temp_next_link;
		temp_next_link = temp_curr_link->next_link;
		
	}
	temp_curr_link->next_link = temp_next_link->next_link;
	free(temp_next_link);
	list->size--;
}
void printLinkedList(LinkedList* list){
	
	assert(list != NULL);
	if(list->first_link->next_link == list->last_link){
		return;
	}
	Link *print_link = list->first_link->next_link;
	while(print_link != list->last_link){
		printf("%d\n\n",print_link->value);
		print_link = print_link->next_link;
	}

}

/* ************************************************************************
	Deque Functions
************************************************************************ */
Deque* dequeCreate(){
	 Deque* newDeque = (Deque*) malloc(sizeof(Deque)); 
    assert(newDeque != NULL); 
    newDeque->size = 0;
    newDeque->first_link = (Link*) malloc(sizeof(Link));
	newDeque->last_link = (Link*) malloc(sizeof(Link));
	newDeque->first_link->next_link = newDeque->last_link;
	newDeque->last_link->next_link = NULL;
    
    return newDeque;
}							// Allocates and initializes the deque
void deleteDeque(Deque* myDeque){
	assert(myDeque != NULL); 

	if(myDeque->first_link->next_link != myDeque->last_link){

		Link *next_link = myDeque->first_link->next_link;
		Link *curr_link = myDeque->first_link->next_link;

		while(curr_link != myDeque->last_link){
			next_link = curr_link->next_link;
			free(curr_link);
			curr_link->next_link;
		}
	}
	free(myDeque->last_link);
	free(myDeque->first_link);
    free(myDeque); 
}				// Deallocates the data and deletes the deque
int sizeDeque(Deque* myDeque){
	return myDeque->size;
}					// Returns the size of the deque
int isEmptyDeque(Deque* myDeque){
	assert(myDeque != NULL);
	if(myDeque->size != 0){
		return 0;
	}
	return 1;
}				// Returns 1 if the deque is empty and 0 otherwise
void addFrontDeque(Deque* myDeque, TYPE value){
	Link *new_link =(Link*) malloc(sizeof(Link));
	new_link->value = value;
	Link *temp_next = myDeque->first_link->next_link;
	Link *temp_current = myDeque->first_link;
	while(temp_next != myDeque->last_link){
		temp_current = temp_next;
		temp_next = temp_next->next_link;
	}
	temp_current->next_link = new_link;
	new_link->next_link = myDeque->last_link;
	myDeque->size++;

	
}	// Adds a new link with the given value to the front of the deque
void addBackDeque(Deque* myDeque, TYPE value){
	Link *new_link =(Link*) malloc(sizeof(Link));
	new_link->next_link = myDeque->first_link->next_link->next_link; // sets new nodes next link pointer to next item in Deque
	new_link = myDeque->first_link->next_link; 
	myDeque->size++;// sets new node as sentinal node's next link
}	// Adds a new link with the given value to the back of the deque
TYPE frontDeque(Deque* myDeque){
	Link *temp_next = myDeque->first_link->next_link;
	Link *temp_current = myDeque->first_link;
	while(temp_next != myDeque->last_link){
		temp_current = temp_next;
		temp_next = temp_next->next_link;
	}

	return temp_current->value;
}				// Returns the value of the link at the front of the deque
TYPE backDeque(Deque* myDeque){
	return myDeque->first_link->next_link->value;
}							// Returns the value of the link at the back of the deque

void removeFrontDeque(Deque* myDeque){
	Link *new_front = myDeque->first_link;
	Link *temp_next = myDeque->first_link->next_link;
	Link *temp_current = myDeque->first_link;
	while(temp_next != myDeque->last_link){
		new_front = temp_current;
		temp_current = temp_next;
		temp_next = temp_next->next_link;
	}
	new_front->next_link = myDeque->last_link;
	free(temp_current);

}			// Removes the link at the front of the deque

void removeBackDeque(Deque* myDeque){
	if(myDeque->first_link->next_link != myDeque->last_link){
	myDeque->first_link->next_link = myDeque->first_link->next_link->next_link;
	free(myDeque->first_link->next_link);
	}
}			// Removes the link at the back of the deque
void printDeque(Deque* myDeque){
	Link *temp_next = myDeque->first_link->next_link;
	Link *temp_current = myDeque->first_link;
	while(temp_next != myDeque->last_link){
		printf("%d\n\n",temp_current->value);
		temp_current = temp_next;
		temp_next = temp_next->next_link;
	}
	
}	

/* ************************************************************************
	Bag Functions
************************************************************************ */
Bag* bagCreate(){
	 Bag* newBag = (Bag*) malloc(sizeof(Bag)); 
    assert(newBag != NULL); 
    newBag->size = 0;
    newBag->first_link = (Link*) malloc(sizeof(Link));
	newBag->last_link = (Link*) malloc(sizeof(Link));
	newBag->first_link->next_link = newBag->last_link;
	newBag->last_link->next_link = NULL;
    
    return newBag;
}							// Allocates and initializes the bag.
void deleteBag(Bag* myBag){
	assert(myBag != NULL); 

	if(myBag->first_link->next_link != myBag->last_link){

		Link *next_link = myBag->first_link->next_link;
		Link *curr_link = myBag->first_link->next_link;

		while(curr_link != myBag->last_link){
			next_link = curr_link->next_link;
			free(curr_link);
			curr_link->next_link;
		}
	}
	free(myBag->last_link);
	free(myBag->first_link);
    free(myBag); 
}				// Deallocates the data and deletes the bag
int sizeBag(Bag* myBag){
	return myBag->size;
}					// Returns the size of the bag
int isBagEmpty(Bag* myBag){
	if(myBag->size == 0){
		return 1;
	}
	return 0;
}					// Returns "1" if the bag is empty or "0" if not 
void addBag(Bag* myBag, TYPE value){
	Link *new_link = (Link*) malloc(sizeof(Link)); //creates and allocates space for new link in bag
	if(myBag->first_link->next_link != myBag->last_link){ //if bag is not empty set links appropriately
	
	new_link->value = value; // assigns value variable of new link the value passed in by function
	new_link->next_link = myBag->first_link->next_link->next_link; // sets the new links next link to keep list unbroken
	myBag->first_link->next_link = new_link; // sets sentinals next link to the new link
	myBag->size++;
	} 										//if bag IS empty insert new link appropriately
	new_link->next_link = myBag->last_link; //if 
	myBag->first_link->next_link = new_link;
	myBag->size++;
}		// Adds an element into the bag
int containsBag(Bag* myBag, TYPE value){
	Link *temp_next = myBag->first_link->next_link;
	Link *temp_current = myBag->first_link;
	while(temp_next != myBag->last_link){
		if(temp_next->value == value){
			return 1;
		}
		temp_current = temp_next;
		temp_next = temp_next->next_link;
	}
	return 0;
}	// Returns "1" if the bag contains the specified element or "0" if not 
void removeBag(Bag* myBag, TYPE value){
	Link *temp_next = myBag->first_link->next_link;
	Link *temp_current = myBag->first_link;
	while(temp_next != myBag->last_link){
		if(temp_next->value == value){
			temp_current->next_link = temp_next->next_link;
			free(temp_next);
		}
		temp_current = temp_next;
		temp_next = temp_next->next_link;
	}
	return;
}		// Removes the specific element from the bag
void printBag(Bag* myBag){
	
	if(myBag->first_link->next_link != myBag->last_link){
		Link *temp_current = myBag->first_link->next_link;
		while(temp_current != myBag->last_link){
			printf("%d/n/n",temp_current->value);
			temp_current = temp_current->next_link;
		}
	}
}			