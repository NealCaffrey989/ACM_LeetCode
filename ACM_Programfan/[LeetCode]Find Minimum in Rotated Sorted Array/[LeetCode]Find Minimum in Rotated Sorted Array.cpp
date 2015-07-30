// [LeetCode]Find Minimum in Rotated Sorted Array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:[4 5 6 7 0 1 2]
Output:0
*/
class Solution {
public:
	int findMin(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int low = 0, high = nums.size() - 1;
		int mid;
		while (low <= high){
			mid = low + (high - low) / 2;
			if (nums[mid] > nums.back())
				low = mid + 1;
			else 
				high = mid - 1;
		}
		return nums[low];
	}
};
int main(void){
	Solution answer;
	int a[] = { 4, 5, 6, 7, 0, 1, 2, 3 };
	vector<int> ans;
	for (size_t i = 0; i < 8; ++i)
		ans.push_back(a[i]);
	cout << answer.findMin(ans) << endl;
	system("Pause");
	return 0;
}

