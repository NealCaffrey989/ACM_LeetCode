// [LeetCode]Kth Largest Element in an Array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:[3,2,1,5,6,4], 2
Output:5
*/

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		if (nums.empty() || nums.size() < k)
			return 0;
		int first = 0, last = nums.size() - 1;
		while (first < last){
			int f = first, l = last;
			int key = nums[first];
			while (f < l){
				while (f < l && nums[l] < key)
					--l;
				nums[f] = nums[l];
				while (f < l && nums[f] >= key)
					++f;
				nums[l] = nums[f];
			}
			nums[f] = key;
			if (f == k - 1)
				return nums[k - 1];
			else if (f < k - 1)
				first = f + 1;
			else
				last = f - 1;
		}
		return nums[k - 1];
	}
};
int main(void){
	Solution answer;
	int a[] = { 3, 2, 1, 5, 6, 4 };
	vector<int> nums;
	for (size_t i = 0; i < 6; ++i)
		nums.push_back(a[i]);
	cout << answer.findKthLargest(nums, 2) << endl;
	system("Pause");
	return 0;
}
