#include <windows.h>
#include <oleidl.h>
#include <ole2.h>
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10


void inserting_sort(int* list)        
{
	int i, k;
	for (i = 1; i < SIZE; i++) {
		int key = list[i];
		for (k = i - 1; k >= 0; k--) {
			if (key < list[k])
				list[k + 1] = list[k];
			else
				break;
		}
		list[k + 1] = key;
	}
}

int main()
{
	int i, k, j;
	int list[SIZE] = {100,30,20,78,89,12,56,38,113,66};

	HDC hdc = GetWindowDC(GetForegroundWindow());

	for (i = 1; i < SIZE; i++) {
		int key = list[i];
		for (k = i - 1; k >= 0; k--) {
			
			Rectangle(hdc, 0, 0, 800, 800);

			if (key < list[k])
				list[k + 1] = list[k];
			else
				break;

			for (j = 0; j < SIZE; j++)
				Rectangle(hdc, 200 + j * 30, 200, 230 + j * 30, 200 - list[j]);

			Sleep(500);
		}
		list[k + 1] = key;
	}

	for (j = 0; j < SIZE; j++)
		Rectangle(hdc, 200 + j * 30, 200, 230 + j * 30, 200 - list[j]);
	Sleep(1000);

	return 0;
}