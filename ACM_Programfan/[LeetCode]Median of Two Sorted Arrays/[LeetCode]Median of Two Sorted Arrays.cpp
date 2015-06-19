// [LeetCode]Median of Two Sorted Arrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;
/*
Input:  a[] = { 1, 2, 3, 4 }, b[] = { 3, 4, 5, 6 };
Output: 3.5
*/
class Solution {
public:
	double findKSorteArrays(int A[], int m, int B[], int n, int k){
		if (m>n)
			return findKSorteArrays(B, n, A, m, k);
		if (m == 0)
			return B[k - 1];
		if (k == 1)
			return min(A[0], B[0]);
		int px = min(k / 2, m), py = k - px;
		if (A[px - 1] < B[py - 1])
			return findKSorteArrays(A + px, m - px, B, n, k - px);
		else if (A[px - 1] > B[py - 1])
			return findKSorteArrays(A, m, B + py, n - py, k - py);
		else
			return A[px - 1];
	}
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		int total = n + m;
		if (total & 0x1)
			return findKSorteArrays(A, m, B, n, total / 2 + 1);
		else
			return (findKSorteArrays(A, m, B, n, total / 2) + findKSorteArrays(A, m, B, n, total / 2 + 1)) / 2;
	}
};


int main(void){
	Solution answer;
	int a[] = { 1, 2, 3, 4 }, b[] = { 3, 4, 5, 6 };
	cout << answer.findMedianSortedArrays(a, 4, b, 4) << endl;
	system("Pause");
	return 0;
}