/**
 *  Author: MIN HO
 *  Date Created: Oct. 31. 2022.
 *  Last Modification Date:
 *  File name: bst.c
 *  Overview: Implement tree operation defined by bst.h
 *  Inputs, Outputs are defined at each function 
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "bst.h"
#include "structs.h"

/** Date: Oct. 31. 2022. 
 *  Overview:
 *      Allocate and initializes the BST
 *  Input: nothing
 *  Output: return bsTree
 * */

struct Node
{
	TYPE         value;
	struct Node* left;
	struct Node* right;
};

struct BSTree
{
	struct Node* root;
	int          count;
};
struct BSTree* newBSTree()
{
    struct BSTree* bsTree = (struct BSTree*)malloc(sizeof(struct BSTree));   
    assert(bsTree != NULL);
    bsTree->root = NULL; 
    bsTree->count = 0;
    return bsTree;
}
/** Date: Oct. 31. 2022. 
 *  Overview:
 *      It makes node free using recursive function from the root
 *      root -> leftmost -> right -> root
 *  Input: myTree
 *  Output: just free
 *  */
struct Node* _deleteBSTree(struct Node* delNode)
{
    if(delNode != NULL)
    {
        _deleteBSTree(delNode->left);
        _deleteBSTree(delNode->right);
        free(delNode);
    }
}

/** Date: Oct. 31. 2022. 
 *  Overview:
 *      Deallocate nodes in BST and deallocate the BST structure
 *  Input: myTree
 *  Output: just free
 *  */
void deleteBSTree(struct BSTree* myTree)
{
    _deleteBSTree(myTree->root);           // to use myTree->root recursively call internal function
    myTree->root = 0;
    myTree->count = 0;
    free(myTree);
}	

/** Date: Oct. 31. 2022. 
 *  Overview:
 *      Returns "1" if the BST is empty or "0" if not 
 *  Input: myTree
 *  Output: "1" or "0"
 *  */
int isEmptyBSTree(BSTree* myTree)
{
    assert(myTree != NULL);
    if (myTree->root != NULL )
        return 1;
    else
        return 0;
}

/** Date: Oct. 31. 2022. 
 *  Overview:
 *     Returns the size of the BST
 *  Input: myTree
 *  Output: int size
 *  */
int sizeBBSTree(BSTree* myTree)
{
    assert(myTree != NULL);
    return myTree->count;
}

/** Date: Oct. 31. 2022. 
 *  Overview:
 *      Add node(TYPE=void* val) to tree
 *      change Recursive -> while
 *  Input: root Node, inserted Value
 *  Output: return always root
 * */
struct Node* _addNode(struct Node *cur, TYPE val)
{
    struct Node* root = cur;
    struct Node* newNode;
    if (root == NULL)                                                       // if val is first value, root is empty
    {                                                                        
        struct Node* rNode = (struct Node *)malloc(sizeof(struct Node));;   // So, the root is filled with val
        rNode->value = val;
        rNode->left = NULL;
        rNode->right =NULL;
        root = rNode;
    }
    struct Node* parent = root;                                             // for comparing parent with cur
    
    
    while(cur != NULL)
    {
        parent = cur;                                // save parent for finding current's parent
        if (compare(cur->value, val) > 0)
            cur = cur->left;
        else if(compare(cur->value, val) < 0)
            cur = cur->right;
        else if(compare(cur->value, val) == 0)
            printf("Wrong number.");
    }
    
    newNode = (struct Node *)malloc(sizeof(struct Node));
    assert(newNode != NULL);
    newNode->value = val;
    newNode->left = NULL;
    newNode->right =NULL;
    cur = newNode;
    if (compare(parent->value, cur->value) > 0)
        parent->left = cur;
    else if(compare(parent->value, cur->value) < 0)
        parent->right = cur;
    else if(compare(parent->value, cur->value) == 0); // if parent->value == cur->value, the first value inserted.  
        
    return root;
}  

/** Date: Oct. 31. 2022. 
 *  Overview:
 *      Add node(TYPE=void* val) to tree
 *      change Recursive -> while
 *      Call Function in tests.c:  addBSTree(tree, &(tv->values[i]));  tv->values[i] is data* 
 *  Input: root Node, inserted Value
 *  Output: return always root
 * */
void addBSTree(struct BSTree* myTree, TYPE value)
{
    myTree->root = _addNode(myTree->root, value);
    myTree->count++;
}

/** Date: Oct. 31. 2022. 
 *  Overview:
 *     Returns "1" if the BST contains the specified element or "0" if not
 *     Recursive implementation
 *  Input: root Node, serching Value
 *  Output: Returns "1"  recursively if the BST contains the specified element
 *          and returns "0" serching reach the leafs node and call their NULL children 
 * */
int _containsBSTree(struct Node* traverseCur, TYPE val)
{
    
    if(traverseCur == NULL)                              // if current is NULL
        return 0;                                        // it is called by leaf node, so we can not find the TYPER val in tree
    /*
    struct Node* includeQ = (struct Node *)malloc(sizeof(struct Node));
    assert(includeQ != NULL);
    includeQ->value = val;
    includeQ->left = NULL;
    includeQ->right =NULL;
    */
    if(compare(traverseCur->value, val) > 0)      // current Node is greater than searching value
        _containsBSTree(traverseCur->left, val);              // move to left child and call recursive function
    else if(compare(traverseCur->value, val) < 0) // current Node is less than searching value
        _containsBSTree(traverseCur->right, val);             // move to right child and call recursive function
    else if(compare(traverseCur->value, val) == 0)// current Node is same as the searching value
        return 1;                                             // return 1 b/c we find it
}

/** Date: Oct. 31. 2022. 
 *  Overview:
 *     Returns "1" if the BST contains the specified element or "0" if not
 *     Call internal function to use myTree->root recursively
 *  Input: myTree, searching value
 *  Output: Returns "1" if the BST contains the specified element or "0" if not
 * */
int containsBSTree(BSTree* myTree, TYPE value)
{
    assert(myTree != NULL);
    return _containsBSTree(myTree->root, value);
} 

/** Date: Oct. 31. 2022. 
 *  Overview:
 *     Returns the minimum value in the BST 
 *  Input: myTree
 *  Output: Returns leftMost value because it is Minimum value
 * */
TYPE minBSTree(BSTree* myTree)
{
    assert(myTree != NULL);
    struct Node* traverseMinNode = myTree->root;
    struct Node* minNode;
    while(traverseMinNode != NULL)
    {
        minNode = traverseMinNode;                // save minNode to keep NULL's parent
        traverseMinNode = traverseMinNode->left;
    }

    return minNode->value;
}

/** Date: Oct. 31. 2022. 
 *  Overview:
 *     Returns the maximum value in the BST  
 *  Input: 
 *  Output: Returns rightMost value because it is Maximum value
 * */
TYPE maxBSTree(BSTree* myTree)
{
    assert(myTree != NULL);
    struct Node* traverseMaxNode = myTree->root;
    struct Node* maxNode;
    while(traverseMaxNode != NULL)
    {
        maxNode = traverseMaxNode;                // save maxNode to keep NULL's parent
        traverseMaxNode = traverseMaxNode->right;
    }

    return maxNode->value;
}
/** Date: Oct. 31. 2022. 
 *  Overview:
 *     Remove the specific element from the BST
 *     I tried to implement using recursive method, but free is not working
 *  Input: BSTree, value(want to delete)
 *  Output: 
 * */

struct Node* _removeBSTree(struct Node* cur, TYPE val)
{
    /* struct Node* parentNode = travFromRoot;

    if(compare(travFromRoot->value, val) > 0)
        _removeBSTree(travFromRoot->left, val);
    else if(compare(travFromRoot->value, val) < 0)
        _removeBSTree(travFromRoot->right, val);
    else if(compare(travFromRoot->value, val) == 0)
    { 
        free(travFromRoot->value);
        free(travFromRoot);
       travFromRoot->value = NULL;
        travFromRoot = NULL;
    } */
    // struct BSTree* tree = (struct BSTree*)malloc(sizeof(BSTree));
    // struct Node* root = cur;
    
    struct Node* parent = cur;                            // for comparing parent with cur
    
    while(cur != NULL)
    {
                            
        if(compare(cur->value, val) == 0)
        {
            if(parent->left == cur) parent->left = NULL;
            else if(parent->right == cur) parent->right = NULL;
            return cur;
        }else if (compare(cur->value, val) > 0)
        {
            parent = cur;
            cur = cur->left;
        }
        else if(compare(cur->value, val) < 0)
        {
            parent = cur;
            cur = cur->right;
        }
    }

   // tree->root = root;  
        
    //return tree;


}
/** Date: Oct. 31. 2022. 
 *  Overview:
 *     Remove the specific element from the BST
 *  Input: BSTree, value(want to delete)
 *  Output: 
 * */
void removeBSTree(BSTree *tree, TYPE value)
{
    struct Node* removeNode;
    if(containsBSTree(tree, value) == 1)
        removeNode = _removeBSTree(tree->root, value);
    tree->count = tree->count - 1;
    free(value);
    free(removeNode);
}

