#include <stdio.h>
#include <iostream>
#include "singleton.h"
#include "functions.h"

//#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)
#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))


//-------------------------------------------------------------------------
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
		++dst;
		dst += sprintf(dst, "%d", count);
	}
	*dst = 0; // remember to null terminate
}

//Bubble sort IMP 
//-------------------------------------------------------------------------
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
//-------------------------------------------------------------------------
void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}
//-------------------------------------------------------------------------
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("n");
}
//-------------------------------------------------------------------------
int check_bubbleSort()
{
	int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	int n = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, n);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}
//-------------------------------------------------------------------------
void printVector(vector<int>& A) {
	for (auto i = A.begin(); i != A.end(); ++i)
		std::cout << *i << ' ';
	std::cout << endl;
}
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
int main() {
	cout << "Starting Test" << endl;
//-------------------------------------------------------------------------
	cout << "CyclicRotation --------------> " << endl;
	vector<int> in{ 3, 8, 9, 7, 6 };
	cout << "Input vector: ";
	printVector(in);

	int k = 2;
	vector<int> out = CyclicRotation_solution(in, k);
	cout << "Output vector: ";
	printVector(out);

	system("pause");
	return 0;
//-------------------------------------------------------------------------

//-------------------------------------------------------------------------
	SingleMgr& _sm = SingleMgr::instance();
	
//-------------------------------------------------------------------------

	int a[17];
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
//-------------------------------------------------------------------------	
	cout << " bubbleSort ---->";
    check_bubbleSort();
	cout << " ---------------";
//-------------------------------------------------------------------------		
	system("pause");
	return 0;
}
//-------------------------------------------------------------------------





