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

int compare(TYPE left, TYPE right)
{
	struct data* dataLeft;
   struct data* dataRight;

   dataLeft = (struct data*)left;
   dataRight = (struct data*)right;

   if(dataLeft -> number < dataRight -> number){
      return -1;
   }
   else if(dataLeft -> number > dataRight -> number){
      return 1;
   }
   else
	   return 0;
}


// Define this function, type casting the value of void* to the desired type

void print_type(TYPE value)
{
	struct data* data;
   data = (struct data*)value;
   printf("%d", data -> number);
}


