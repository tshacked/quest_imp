#include <stdio.h>
#include <iostream>
using namespace std;
#include "singleton.h"

//#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)
#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))


// Write a C function that compresses a C string from a sequence of characters
// to a sequence of characters & the # of consecutive times they appear.
// For instance: compress("aabcccdd") = "a2b1c3d2".
//-------------------------------------------------------------------------
void compress(char* dst, const char* src)
{
	while (*src) {
		*dst = *src++;
		int count = 1;
		for (; *src == *dst; ++src) {
			++count;
		}
		++dst; // now src points to a different character than we started with which could be the end of the string too
		dst += sprintf(dst, "%d", count);
	}
	*dst = 0; // remember to null terminate
}
//-------------------------------------------------------------------------
int main() {
	cout << "Hi Im Tamar" << endl;

	SingleMgr& _sm = SingleMgr::instance();


//This only works for arrays on the stack
	int a[17];
	cout << "num of elements / Length if a[17] = "<< sizeof(a) <<"/" << sizeof(a[0]) << " = " << NELEMS(a) << endl;

	
	char src[] = "aabcccdd";
	int arr_s_bytes = sizeof(src);

	cout << "String: " << src << endl;
	cout << "total size bytes:   " << arr_s_bytes << endl;
	cout << "size of element/sell: " << sizeof(src[0]) << endl;
	int num_of_elements = NELEMS(src);
	cout << "number of elements: " << num_of_elements << endl;
	//char dst[num_of_elements];  -- cannot init - "expression did not evaluate to a constant"
	char dst[ sizeof(src) / sizeof(src[0]) ];
	compress(dst, src);
	cout << "src = " << src << endl;
	cout << "dst = " << dst << endl;
	system("pause");
	return 0;
}
//-------------------------------------------------------------------------





// C program for implementation of Bubble sort
#include <stdio.h>

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place   
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("n");
}

// Driver program to test above functions
int check_bubbleSort()
{
	int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	int n = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, n);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}
