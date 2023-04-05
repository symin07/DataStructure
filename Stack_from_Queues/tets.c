#include <stdio.h>


typedef struct ptrtst{
    int a;
    int *b;
}ptrtst;

int main()
{
    ptrtst* pt = (ptrtst*)malloc(sizeof(ptrtst));
    pt->a = 4;
    pt->b = 5;
    printf("this is a = %d \n", pt->a);
    printf("this is b = %d", (*pt).b);;
}