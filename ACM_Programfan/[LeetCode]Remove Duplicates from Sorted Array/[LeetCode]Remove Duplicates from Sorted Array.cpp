// [LeetCode]Remove Duplicates from Sorted Array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Input: A = [1,1,2], n=3
Output: 2
*/
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int count = 1;
		for (size_t i = 1; i < nums.size(); ++i){
			if (nums[i - 1] != nums[i]){
				nums[count] = nums[i];
				count++;
			}
		}
		if (count != nums.size())
			nums.erase(nums.begin() + count);
		return count;
	}
};
int main(void){
	Solution answer;
	int a[] = { 1, 1, 2};
	vector<int> nums;
	for (size_t i = 0; i < 1; ++i)
		nums.push_back(a[i]);
	cout << answer.removeDuplicates(nums) << endl;
	for (size_t i = 0; i < nums.size(); ++i)
		cout << nums[i] << " ";
	cout << endl;
/*	int n = answer.removeDuplicates(a, 3);
	int i = 0;
	while (n--){
		cout << a[i++] << endl;
	}*/
	system("Pause");
	return 0;
}

