#include <stdio.h>
#include <iostream>
#include "functions.h"


/* An array A consisting of N integers is given. 
Rotation of the array means that each element is shifted right by one index, 
and the last element of the array is moved to the first place. 
For example, the rotation of array 
A = [3, 8, 9, 7, 6] 
 is [6, 3, 8, 9, 7] (elements are shifted right by one index and 6 is moved to the first place).

The goal is to rotate array A K times; that is, each element of A will be shifted to the right K times.

Write a function:

vector<int> solution(vector<int> &A, int K);

that, given an array A consisting of N integers and an integer K, returns the array A rotated K times.

For example, given

A = [3, 8, 9, 7, 6]
K = 3
the function should return [9, 7, 6, 3, 8]. Three rotations were made:

[3, 8, 9, 7, 6] -> [6, 3, 8, 9, 7]
[6, 3, 8, 9, 7] -> [7, 6, 3, 8, 9]
[7, 6, 3, 8, 9] -> [9, 7, 6, 3, 8]
For another example, given

A = [0, 0, 0]
K = 1
the function should return [0, 0, 0]

Given

A = [1, 2, 3, 4]
K = 4
the function should return [1, 2, 3, 4]

Assume that:

N and K are integers within the range [0..100];
each element of array A is an integer within the range [−1,000..1,000].
In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.
*/

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
//A = [3, 8, 9, 7, 6]
//A = [6, 3, 8, 9, 7]


vector<int> CyclicRotation_solution(vector<int> &A, int k)
{
	vector<int> out;
	if (A.empty()) return out;
	int s = A.size();
	for (int i = 0; i < A.size(); i++) {
		out.push_back(A[(i + k) % s]);
	}
	
	/*int s = out.size();
	int tmp;
	for (int i = 0; i < k; i++) { //K times
		for (int j = 1; j < s; j++) {
			tmp = out[j];
			out[j] = out[j - 1];
		}
	}*/
	return out;
}
