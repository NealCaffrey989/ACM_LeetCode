// [LeetCode]Search Insert Position.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:[1,3,5,6]  5 
Output:2
*/
class Solution {
public:
	int searchInsert(vector<int>& nums, int f, int l, int target) {
		if (nums[f] >= target)
			return f;
		int mid = f + (l - f) / 2;
		if (target <= nums[mid])
			return searchInsert(nums, f, mid - 1, target);
		else
			return searchInsert(nums, mid + 1, l, target);
	}
	int searchInsert(vector<int>& nums, int target) {
		if ((nums.size() == 0) || (target <= nums.front()))
			return 0;
		if (target>nums.back())
			return nums.size();
		return searchInsert(nums, 0, nums.size() - 1, target);
	}
};

int main(void){
	Solution answer;
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);
	cout << answer.searchInsert(v, 0) << endl;
	cout << answer.searchInsert(v, 2) << endl;
	cout << answer.searchInsert(v, 4) << endl;
	cout << answer.searchInsert(v, 5) << endl;
	cout << answer.searchInsert(v, 7) << endl;
	cout << answer.searchInsert(v, 9) << endl;
	system("Pause");
	return 0;
}

