// [LeetCode]Merge Sorted Array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Input:[1,2,4,6,7]  5  [3,5,8]  3
Output:[1,2,3,4,5,6,7,8]
*/
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (m <= 0){
			nums1 = nums2;
			return;
		}
		if (n <= 0)
			return;
		int sign = n + m - 1;
		int n1 = m - 1, n2 = n - 1;
		while (sign >= 0){
			if (nums1[n1] > nums2[n2])
				nums1[sign--] = nums1[n1--];
			else if (nums1[n1] < nums2[n2])
				nums1[sign--] = nums2[n2--];
			else{
				nums1[sign--] = nums1[n1--];
				nums1[sign--] = nums2[n2--];
			}
			if (n2 < 0)
				return;
			if (n1 < 0){
				while (sign >= 0)
					nums1[sign--] = nums2[n2--];
			}
		}
/*		for (size_t i = 0; i < n; ++i)
			nums1[i + m] = nums2[i];
		sort(nums1.begin(), nums1.end());*/
	}
};
int main(void){
	Solution answer;
	int a[] = { 1, 2, 4, 6, 7 };
	int b[] = { 3, 5, 8 };
	vector<int> num1(2), num2;
	for (size_t i = 0; i < 1; ++i)
		num1[i] = a[i];
	for (size_t i = 0; i < 1; ++i)
		num2.push_back(b[i]);
	answer.merge(num1, 1, num2, num2.size());
	for (size_t i = 0; i < num1.size(); ++i)
		cout << num1[i] << " ";
	cout << endl;
	system("Pause");
	return 0;
}