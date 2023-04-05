#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "bst.h"

struct node
{
	TYPE         value;
	struct node* left;
	struct node* right;
};

struct BinarySearchTree
{
	struct node* root;
	int          size;
};


/*----------------------------------------------------------------------------*/
//BINARY SEARCH TREE FUNCTIONS GO HERE
/*----------------------------------------------------------------------------*/

void BSTinit(struct BinarySearchTree *tree) 
{ 
    tree->size = 0;
    tree->root = 0;
}

struct node* BSTnodeAdd (struct node *current, TYPE newValue) 
{
    
    struct node* newNode;
    if (current == NULL)                                                       // if val is first value, root is empty
    {                                                                        
        struct node* rNode = (struct node *)malloc(sizeof(struct node));;   // So, the root is filled with val
        rNode->value = newValue;
        rNode->left = NULL;
        rNode->right =NULL;
        current = rNode;
        return current;
    }
    
    struct node* parent = current;                                             // for comparing parent with cur
    
    while(current != NULL)
    {
        parent = current;                                // save parent for finding current's parent
        if (current->value > newValue)
            current = current->left;
        else if(current->value <= newValue)
            current = current->right;
    }
    
    newNode = (struct node *)malloc(sizeof(struct node));
    assert(newNode != NULL);
    newNode->value = newValue;
    newNode->left = NULL;
    newNode->right =NULL;
    
    current = newNode;
    if (parent->value > current->value)
        parent->left = current;
    else if(parent->value <= current->value) 
        parent->right = current; 
        
    return current;
}
void BSTadd(struct BinarySearchTree *tree, TYPE newValue)
{ 
    tree->root = BSTnodeAdd(tree->root, newValue); 
    tree->size++; 
}
int BSTsize (struct BinarySearchTree *tree) 
{ 
    return tree->size; 
} 

int _BTScontains(struct node *current, TYPE d)
{
    if(current == NULL)                              // if current is NULL
        return 0;                                 // it is called by leaf node, so we can not find the TYPER val in tree
    if(current->value > d )      // current Node is greater than searching value
        _BTScontains(current->left, d);              // move to left child and call recursive function
    else if(current->value < d) // current Node is less than searching value
        _BTScontains(current->right, d);             // move to right child and call recursive function
    else if(current->value == d)// current Node is same as the searching value
        return 1; 
}

int BSTcontains(struct BinarySearchTree *tree, TYPE d)
{
     assert(tree != NULL);
    return _BTScontains(tree->root, d);

}
struct node* BSTnodeRemove (struct node * current, TYPE d) 
{
    //struct node* root = current;
    if(current->value == d)             // current Node is same as the searching value
    {
        if(current->right == NULL)
        {
            return current->left;
        }else{
            current->value = leftMostChild(current->right);
            struct node* remove = removeLeftmostChild(current->right);
        }
    }else if(current->value > d )         // current Node is greater than searching value
        current->left = BSTnodeRemove(current->left, d);              // move to left child and call recursive function
    else if(current->value < d) // current Node is less than searching value
        current->right = BSTnodeRemove(current->right, d);             // move to right child and call recursive function
   
    return current;

}
void BSTremove (struct BinarySearchTree *tree, TYPE d) 
{ 
    if (BSTcontains(tree, d)) 
    {
        tree->root = BSTnodeRemove(tree->root, d);
        //BSTnodeRemove(tree->root, d);
        tree->size--;
    }
}

TYPE leftMostChild (struct node * current) 
{
    struct node* leftmost;
    while(current != NULL)
    {
        leftmost = current;                // save minNode to keep NULL's parent
        current = current->left;
    }
    return leftmost->value;

}
struct node* removeLeftmostChild (struct node *current) 
{
    struct node* leftmost;
    while(current != NULL)
    {
        leftmost = current;                // save minNode to keep NULL's parent
        current = current->left;
    }

    return leftmost;
}


void printBSTree(struct BinarySearchTree *tree)				// Prints the values in the BST.
{
	/*write this*/
	
}


void _assertTrue(int predicate, char *message) 
{
	printf("%s: ", message);
	if (predicate)
		printf("PASSED\n");
	else
		printf("FAILED\n");
}


int main(int argc, char *argv[])
{	

   /* After implementing your code, you must uncomment the following calls to the test functions and test your code. Otherwise, you will not receive any 
points */

  	struct BinarySearchTree* bst = 
        (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
    BSTinit(bst);
    
    BSTadd(bst, 1);
    BSTadd(bst, 10);
    BSTadd(bst, 15);
    BSTadd(bst, 3);
    BSTadd(bst, 9);
    BSTadd(bst, 45);
    BSTadd(bst, 25);
    BSTadd(bst, 7);


    _assertTrue(BSTcontains(bst, 9), "Test containing 9");
    _assertTrue(BSTcontains(bst, 3), "Test containing 3");
    _assertTrue(BSTcontains(bst, 25), "Test containing 25");
    _assertTrue(BSTcontains(bst, 1), "Test containing 1");

    BSTremove(bst, 3);
    BSTremove(bst, 1);
    BSTremove(bst, 25);
    BSTremove(bst, 9);
    
    _assertTrue(!BSTcontains(bst, 3), "Test not containing 3");
    _assertTrue(!BSTcontains(bst, 1), "Test not containing 1");
    _assertTrue(!BSTcontains(bst, 25), "Test not containing 25");
    _assertTrue(!BSTcontains(bst, 9), "Test not containing 9");

}    
    
    