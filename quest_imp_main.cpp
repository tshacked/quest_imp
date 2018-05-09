#include <stdio.h>
#include <iostream>
using namespace std;

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

int main() {
	cout << "Hi Im Tamar" << endl;

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
	//compress();
	system("pause");
	return 0;
}


/*
Write a C function that compresses a C string from a sequence of characters 
to a sequence of characters & the # of consecutive times they appear. 
For instance: compress("aabcccdd") = "a2b1c3d2".
*/

void compress(char* dst, const char* src)
{
	while (*src) {
		// in this loop, we'll do one char/num pair at a time
		*dst = *src++;

		int count = 1;
		for (; *src == *dst; ++src) {
			++count;
		}

		// now src points to a different character than we started with which could be the end of the string too
		++dst;
		dst += sprintf(dst, "%d", count);
	}
	*dst = 0; // remember to null terminate
}
