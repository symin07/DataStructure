//퀵 정렬(Quick Sort)
#include <stdio.h>
#include <stdlib.h>
#include <wincon.h>
#include <winbase.h>
#include <time.h>
#include <stdbool.h>
#define SWAP(a,b)  {int t; t = a; a=b; b=t;}//a와 b를 교환
#define LENGTH(arr)  (sizeof(arr)/sizeof(arr[0]))

enum Color
{
    BLACK, BLUE, GREEN, JADE, RED, PURPLE, YELLOW, WHITE, GRAY,
    LIGHT_BLUE, LIGHT_GREEN, LIGHT_JADE, LIGHT_RED, LIGHT_PURPLE, LIGHT_YELLOW, LIGHT_WHITE
};
void changecolor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

#define MAX_ELEM 30
void QuickSort2(int* obase, int on,int *base,int n);
void MakeRandoms(int* base, int n, int end);
void ViewArr(int* arr, int n);
int main(void)
{   
    int arr[MAX_ELEM];
    MakeRandoms(arr, MAX_ELEM, 100);
    
    ViewArr(arr, MAX_ELEM);    
    QuickSort2(arr, MAX_ELEM,arr, MAX_ELEM);
    ViewArr(arr, MAX_ELEM);    
    return 0;
}
void MakeRandoms(int* base, int n, int end)
{
    srand((unsigned)time(0));
    int i = 0;
    for (i = 0; i < n; i++)
    {
        base[i] = rand() % end;
    }
}

void PrintSpace(int n);
void View2(int *obase, int on, int *base, int n, int left, int right,int how);
void QuickSort2(int* obase, int on, int* base, int n)
{
    int pivot = 0; // 피벗의 위치 기억하는 변수
    int left = 0, right = 0; // 피벗보다 큰 값과 작은 값의 위치를 찾기위한 변수

    if (n <= 1)
    {
        return;
    }

    left = 0;
    right = n;
    while (1)
    {
        Sleep(300);
        for (left++; (left < n) && (base[0] >= base[left]); left++)
        {
            View2(obase, on, base, n, left, right,0);
            
        }
        View2(obase, on, base, n, left, right, 0);
        changecolor(LIGHT_YELLOW);
        PrintSpace(base - obase + left);
        printf("BIG\n");
        for (right--; (right > 0) && (base[0] < base[right]); right--)
        {
            View2(obase, on, base, n, left, right,0);
        }
        View2(obase, on, base, n, left, right, 0);
        changecolor(LIGHT_YELLOW);        
        PrintSpace(base-obase+right);
        printf("small\n");
        if (left < right)
        {               
            SWAP(base[left], base[right]);            
            View2(obase, on, base, n, left, right,1);
        }        
        else
        {
            break;
        }
    }        
    
    SWAP(base[0], base[right]);          
    View2(obase, on, base, n, left, right,2);
    Sleep(300);
    int gap = base - obase;
    if (right >1)
    {
        changecolor(LIGHT_YELLOW);
        printf("Recursice call start:%d count:%d\n", gap,right);
    }
    QuickSort2(obase,on,base, right);    
    if (n - left >1)
    {
        changecolor(LIGHT_YELLOW);
        printf("Recursice call start:%d count:%d\n", gap+left, n-left);
    }
    QuickSort2(obase,on,base + left, n - left);
}
void View2(int* obase, int on, int* base, int n, int left, int right,int how)
{    
    int gap = base - obase;
    n += gap;
    left += gap;
    right += gap;
    int i = 0;
    for (i = 0; i < on; i++)
    {
        changecolor(WHITE);
        if (i < gap)
        {
            changecolor(BLACK);
        }
        if (i == gap)
        {
            changecolor(LIGHT_RED);
            if (how == 2)
            {
                changecolor(LIGHT_PURPLE);
            }
        }
        if (i == left)
        {
            if (how == 0)
            {
                changecolor(LIGHT_GREEN);
            }
            if (how == 1)
            {
                changecolor(LIGHT_PURPLE);
            }
        }
        if (i == right)
        {
            if (how == 0)
            {
                changecolor(LIGHT_PURPLE);
            }
            if (how == 1)
            {
                changecolor(LIGHT_GREEN);
            }
            if (how == 2)
            {
                changecolor(LIGHT_RED);
            }
        }
        if (i >= n)
        {
            changecolor(BLACK);
        }
        printf("%2d ", obase[i]);
    }
    printf("\n");
    changecolor(WHITE);
}

void ViewArr(int* arr, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("%2d ", arr[i]);        
    }
    printf("\n");
}
void PrintSpace(int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("   ");
    }
}