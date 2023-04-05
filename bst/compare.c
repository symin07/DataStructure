#include <stdio.h>
#include <assert.h>
#include "bst.h"
#include "structs.h"

/* Define this function, type casting the value of void * to the desired type.
   The current definition of TYPE in bst.h is void*, which means that left and
   right are void pointers. To compare left and right, you should first cast
   left and right to the corresponding pointer type (struct data *), and then
   compare the values pointed by the casted pointers.

   Return value:
   -1 if left < right return
    1 if left > right return
    0 if left = right return

   DO NOT compare the addresses pointed by left and right, i.e. "if (left < right)",
   which is really wrong.
*/
struct Node
{
   TYPE value;
   struct Node *left;
   struct Node *right;
};

struct BSTree
{
   struct Node *root;
   int count;
};
int compare(TYPE left, TYPE right)
{
   struct data *leftComp = (struct data *)left;
   struct data  *rightComp = (struct data *)right;

   if (leftComp->number > rightComp->number)
      return 1;
   else if (leftComp->number < rightComp->number)
      return -1;
   else if (leftComp->number == rightComp->number)
      return 0;
}

void print_type(TYPE value)
{
   struct data *val = (struct data *)value;
   printf("Value: %d, Name: %s \n", val->number, val->name);
}



