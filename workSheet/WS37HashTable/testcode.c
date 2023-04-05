#include <stdio.h>
#define HASH(A) A-97 
int main()
{
    int numerator, denominator;
    numerator = 10;
    denominator = 4;
    char* newchar = "deill";
    int testchar = HASH(newchar[2]);
    char** pptr = (char**)malloc(8 * sizeof(char*));
    char* ptr1 = "amiga";
    char* ptr2 = "bmiga";
    char* ptr3 = "cmiga";

    pptr[0] = ptr1;

    printf("%s\n", pptr[0]);
    printf("0 === %d\n", testchar);
    char integer = 'i';
    printf("a = %d\n", integer);
    printf("(double) numerator/denomirator %.2f\n", (double)numerator/denominator);
    printf("numerator/(double) denomirator %.2f\n", numerator/(double)denominator);
    
}