// Binary search tree (BST) interface.

#ifndef BST_H
#define BST_H 1

# ifndef TYPE
# define TYPE	int
# endif


void _print_type(TYPE curval);				// Prints TYPE values, define this in your compare.c file


typedef struct BinarySearchTree BinarySearchTree;


/* ************************************************************************
	BST Interface
************************************************************************ */

void BSTinit(struct BinarySearchTree *tree);				// Allocates and initializes the BST
void BSTadd(struct BinarySearchTree *tree, TYPE newValue);			// Deallocate nodes in BST and deallocate the BST structure
int BSTsize(struct BinarySearchTree *tree);				// Returns "1" if the BST is empty or "0" if not 
struct node * BSTnodeAdd (struct node *current, TYPE newValue); 				// Returns the size of the BST
int BSTcontains (struct BinarySearchTree *tree, TYPE d);		// Adds an element into the BST
void BSTremove (struct BinarySearchTree *tree, TYPE d);	// Returns "1" if the BST contains the specified element or "0" if not
TYPE leftMostChild (struct node * current);					// Returns the minimum value in the BST 
struct node * removeLeftmostChild (struct node *current) ;					// Returns the maximum value in the BST  
struct node* BSTnodeRemove (struct node * current, TYPE d);		// Remove the specific element from the BST
void printBSTree(struct BinarySearchTree *tree);				// Prints the values in the BST.

# endif
