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
/** Date: Oct. 31. 2022.  update Nov 04.
 *  Overview:
 *      It makes node free using recursive function from the root
 *      root -> leftmost -> right -> root
 *  Input: myTree
 *  Output: just free
 *  */
void _deleteBSTree(struct Node* delNode)
{
    //assert(delNode != NULL);
	if(delNode != NULL)
    {
		if(delNode->left != NULL) 
			_deleteBSTree(delNode->left);
        if(delNode->right != NULL)
			_deleteBSTree(delNode->right);
		if(delNode != NULL)		
			free(delNode); 
    }
}

/** Date: Oct. 31. 2022., update Nov 04. 
 *  Overview:
 *      Deallocate nodes in BST and deallocate the BST structure
 *  Input: myTree
 *  Output: just free
 *  */
void deleteBSTree(struct BSTree* myTree)
{
	assert(myTree != NULL); 
	_deleteBSTree(myTree->root);           // to use myTree->root recursively call internal function
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
    struct Node* newNode;
    struct Node* root = cur;
    if (cur == NULL)                                                       // if val is first value, root is empty
    {                                                                        
        struct Node* rNode = (struct Node *)malloc(sizeof(struct Node));;   // So, the root is filled with val
        rNode->value = val;
        rNode->left = NULL;
        rNode->right =NULL;
        cur = rNode;
        return cur;
    }
    
    struct Node* parent = cur;                                             // for comparing parent with cur
    while(cur != NULL)
    {
        parent = cur;                                // save parent for finding current's parent
        if (compare(cur->value, val) == 1)
            cur = cur->left;
        else if(compare(cur->value, val) == -1)
            cur = cur->right;
    }
    
    newNode = (struct Node *)malloc(sizeof(struct Node));
    assert(newNode != NULL);
    newNode->value = val;
    newNode->left = NULL;
    newNode->right =NULL;
    cur = newNode;
   if (compare(parent->value, cur->value) == 1)
        parent->left = cur;
     else if(compare(parent->value, cur->value) == -1)
        parent->right = cur;  
        
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

    if(compare(traverseCur->value, val) == 1)
	{												     // current Node is greater than searching value
        _containsBSTree(traverseCur->left, val);
	}													// move to left child and call recursive function
    else if(compare(traverseCur->value, val) == -1)
	{														 // current Node is less than searching value
        _containsBSTree(traverseCur->right, val);
	}												        // move to right child and call recursive function
    else	// current Node is same as the searching value
		return 1; // return 1 b/c we find it

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

TYPE _leftMost(struct Node *current)
{
    while (current->left != 0) 
        current = current->left;
    return current->value;
}


struct Node *_removeLeftMost(struct Node *current)
{
    assert(current != NULL);
    struct Node* lastNode = 0;
    struct Node* currNode = current; 
    
    while (currNode->left != NULL) 
    { 
        lastNode = currNode; 
        currNode = currNode->left;
    }


    if (currNode->right != NULL) 
    {
        if (lastNode != NULL)
        lastNode->left = currNode->right;
        else
        lastNode = currNode->right;

        return lastNode;    
    }
    else if (current != currNode) {

    currNode->value = 0;
    currNode->left = 0;
    currNode->right = 0; 
    free(currNode); 
    lastNode->left = 0;

    return current;
}

    return 0;
}



/** Date: Oct. 31. 2022. 
 *  Overview:
 *     Remove the specific element from the BST
 *     I tried to implement using recursive method, but free is not working
 *  Input: BSTree, value(want to delete)
 *  Output: 
 * */
struct Node*  _removeBSTree(struct Node* current, TYPE val)
{  
    if (compare(current->value, val) == 0) 
    { 
        if (current->right == 0)
            return current->left; 
        else {
            current->value = _leftMost(current->right);
            current->right = _removeBSTree(current->right, val);
        }
    }
    else if (compare(val, current->value) == -1)
        current->left = _removeBSTree(current->left, val);
    else
        current->right = _removeBSTree(current->right, val);

    return current;
}
  

/** Date: Oct. 31. 2022. 
 *  Overview:
 *     Remove the specific element from the BST
 *  Input: BSTree, value(want to delete)
 *  Output: 
 * */
void removeBSTree(BSTree *tree, TYPE value)
{
/*
    if(containsBSTree(tree, value) == 1)
        _removeBSTree(tree->root, value);
    tree->count = tree->count - 1;
*/
    if(containsBSTree(tree, value) == 1)
	{
        tree->root = _removeBSTree(tree->root, value);
		tree->count = tree->count - 1;
	}

   // free(removeNode);  // -->> segmentation faulti
                         // in Test function, when Executing deleteAll 
                         // double free memory fault 
}



void _printBSTtree(struct Node *treeNode)
{
	
   if (treeNode != NULL)
   {
      _printBSTtree(treeNode->left);
      _printBSTtree(treeNode->right);
     print_type(treeNode->value);
   }
}

/** Date: Oct. 31. 2022.
 *  Overview:
 *    Prints the values in the BST.
 *    Define this in your compare.c file
 *  Input: BSTree
 *  Output:
 * */
void printBSTree(BSTree *myTree)
{
	assert(myTree != NULL);
	 _printBSTtree(myTree->root);
}


/*----------------------------------------------------------------------------*/

// Test value stuff -----

struct TestValues
{
    struct data* values;
    int n;
};

void initValue(struct data* value, int number, const char* name)
{
    value->number = number;
    value->name = malloc((strlen(name) + 1) * sizeof(char));
    strcpy(value->name, name);
}

void freeValue(struct data* value)
{
    free(value->name);
}

struct TestValues* createValues()
{
    struct TestValues* values = malloc(sizeof(struct TestValues));
    values->n = 4;
    values->values = malloc(values->n * sizeof(struct data));
    
    initValue(&(values->values[0]), 50, "rooty");
    initValue(&(values->values[1]), 13, "lefty");
    initValue(&(values->values[2]), 110, "righty");
    initValue(&(values->values[3]), 10, "lefty of lefty");
    
    return values;
}

void destroyValues(struct TestValues* values)
{
    for (int i = 0; i < values->n; ++i)
    {
        freeValue(&(values->values[i]));
    }
    free(values->values);
    free(values);
}

// -----

void printTestResult(int predicate, char *nameTestFunction, char 
*message){
    if (predicate)
        printf("%s(): PASS %s\n",nameTestFunction, message);
    else
        printf("%s(): FAIL %s\n",nameTestFunction, message);        
}

/**
 * Tests adding 4 nodes to the BST.
 */
void testAddNode()
{
    struct TestValues* tv = createValues();
    struct BSTree *tree	= newBSTree();
    
    // Add all values to the tree
    for (int i = 0; i < tv->n; ++i)
    {
        addBSTree(tree, &(tv->values[i]));
        if (tree->count != i + 1)
        {
            printf("addNode() test: FAIL to increase count when inserting\n");
            return;
        }
    }
    
    // Check that root node is rooty
    if (tree->root->value != &(tv->values[0]))
    {
        printf("addNode() test: FAIL to insert 50 as root\n");
        return;
    }
    else
    {
        printf("addNode() test: PASS when adding 50 as root\n");
    }
    
    if (tree->root->left->value != &(tv->values[1]))
    {
        printf("addNode() test: FAIL to insert 13 as left child of root\n");
        return;
    }
    else
    {
        printf("addNode() test: PASS when adding 13 as left of root\n");
    }
    
    if (tree->root->right->value != &(tv->values[2]))
    {
        printf("addNode() test: FAIL to insert 110 as right child of root\n");
        return;
    }
    else
    {
        printf("addNode() test: PASS when adding 110 as right of root\n");
    }
    
    if (tree->root->left->left->value != &(tv->values[3]))
    {
        printf("addNode() test: FAIL to insert 10 as left child of left of root\n");
        return;
    }
    else
    {
        printf("addNode() test: PASS when adding 10 as left of left of root\n");
    }
    
    deleteBSTree(tree);
    destroyValues(tv);
}

/**
 * Tests that the BST contains the added elements,
 * and that it does not contain an element that was not added.
 */
void testContainsBSTree()
{
    struct TestValues* tv = createValues();
    struct BSTree *tree	= newBSTree();
    
    // Create value not added to the tree
    struct data notInTree;
    notInTree.number = 111;
    notInTree.name = "not in tree";
    
    // Add all other values to the tree
    for (int i = 0; i < tv->n; ++i)
    {
        addBSTree(tree, &(tv->values[i]));
    }
    
    printTestResult(containsBSTree(tree, &(tv->values[0])), "containsBSTree", "when test containing 50 as root");
    printTestResult(containsBSTree(tree, &(tv->values[1])), "containsBSTree", "when test containing 13 as left of root");
    printTestResult(containsBSTree(tree, &(tv->values[2])), "containsBSTree", "when test containing 110 as right of root");
    printTestResult(containsBSTree(tree, &(tv->values[3])), "containsBSTree", "when test containing 10 as left of left of root");
    
    printTestResult(!containsBSTree(tree, &notInTree), "containsBSTree", "when test containing 111, which is not in the tree");
    
    deleteBSTree(tree);
    destroyValues(tv);
}

/**
 * Tests leftMost.
 */
void testMinMax()
{
	struct TestValues* tv = createValues();
    BSTree* tree	= newBSTree();

    for (int i = 0; i < tv->n; ++i)
    {
        addBSTree(tree, &(tv->values[i]));
    }
	
	if(compare(minBSTree(tree), &(tv->values[3])) == 0)
		printf("Test minBSTree(): PASS\n");
    else
        printf("Test minBSTree(): FAIL\n");
	
	if(compare(maxBSTree(tree), &(tv->values[2])) == 0)
		printf("Test maxBSTree(): PASS\n");
    else
        printf("Test maxBSTree(): FAIL\n");
	
	deleteBSTree(tree);
    destroyValues(tv);
}



/**
 * Tests removal of all nodes.
 */
void testRemoveBSTree()
{
    struct TestValues* tv = createValues();
    BSTree *tree	= newBSTree();

    for (int i = 0; i < tv->n; ++i)
    {
        addBSTree(tree, &(tv->values[i]));
    }
    
	printf("Original tree:\n");
	printBSTree(tree);
	
    removeBSTree(tree, &tv->values[3]);
	printf("The tree below should not contain the value 10\n");
	printBSTree(tree);
	        
    removeBSTree(tree, &tv->values[2]);
	printf("The tree below should not contain the value 110\n");
	printBSTree(tree);
	   
    removeBSTree(tree, &tv->values[1]);
	printf("The tree below should not contain the value 13\n");
	printBSTree(tree);
        
    removeBSTree(tree, &tv->values[0]);
	printf("The tree below should be empty\n");
	printBSTree(tree);
    
    deleteBSTree(tree);
    destroyValues(tv);
}


// Main function for testing

int main(int argc, char *argv[])
{	

   /* After implementing your code, you must uncomment the following calls to the test functions and test your code. Otherwise, you will not receive any 
points */

  	testAddNode();
	
	printf("\n");
  	testContainsBSTree();
	
	printf("\n");
    testMinMax();
	
	printf("\n");
    testRemoveBSTree();
    
	return 0;
}
