#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "bst.h"

struct AVLnode
{
	TYPE         value;
	struct AVLnode* left;
	struct AVLnode* right;
    int height;
};

struct BinarySearchTree
{
	struct AVLnode* root;
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

int h (struct AVLnode* current)
{
    if (current == 0)
        return -1;
    
    return current->height;
}

void setHeight (struct AVLnode* current)
{
    int lch = h(current->left);
    int rch = h(current->right);
    if (lch < rch)
        current->height = 1 + rch;
    else
        current->height = 1 + lch;
}

int bf (struct AVLnode* current)
{
    return h(current->right) - h(current->left);
}
struct AVLnode* rotateLeft(struct AVLnode* current)
{
    struct AVLnode* temp = (struct AVLnode*)malloc(sizeof(struct AVLnode));
    temp->value = current->value;
    temp->left = 0;
    temp->right = 0;
    temp->height = 0;
    current->right->left = temp;
    current = current->right;
    return current;
}
struct AVLnode* rotateRight(struct AVLnode* current)
{
    struct AVLnode* temp = (struct AVLnode*)malloc(sizeof(struct AVLnode));
    temp->value = current->value;
    temp->left = 0;
    temp->right = 0;
    temp->height = 0;
    
    current->left->right = temp;
    current = current->left;
    return current;
}

struct AVLnode* balance (struct AVLnode* current)
{
    int cbf = bf(current);
    if (cbf < -1)
    {
        if (bf(current->left) > 0)    // double roatation
            current->left = rotateLeft(current->left);
        return rotateRight(current);
    }else if(cbf > 1){
        if(bf(current->right) < 0)
            current->right = rotateRight(current->right);
        return rotateLeft(current);
    }
    setHeight(current);
    return current;
}
struct AVLnode *AVLnodeAdd(struct AVLnode* current, TYPE newValue) 
{
    struct AVLnode* newnode;
    if (current == 0)
    {
        newnode = (struct AVLnode *) malloc(sizeof(struct AVLnode));
        assert(newnode != 0);
        newnode->value = newValue;
        newnode->left = newnode->right = 0;
        newnode->height = 0;
        return newnode;
    }else if(LT(newValue, current->value))
        current->left = AVLnodeAdd(current->left, newValue);
    else    
        current->right = AVLnodeAdd(current->right, newValue);
    
    return balance(current);
}

int main(int argc, char *argv[])
{	

   /* After implementing your code, you must uncomment the following calls to the test functions and test your code. Otherwise, you will not receive any 
points */

  	struct BinarySearchTree* bst = 
        (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
    BSTinit(bst);
    
    bst->root = AVLnodeAdd(bst->root, 10);
    bst->root = AVLnodeAdd(bst->root, 14);
    bst->root = AVLnodeAdd(bst->root, 19);
    bst->root = AVLnodeAdd(bst->root, 8);
    bst->root = AVLnodeAdd(bst->root, 6);

/*
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
*/
}  


