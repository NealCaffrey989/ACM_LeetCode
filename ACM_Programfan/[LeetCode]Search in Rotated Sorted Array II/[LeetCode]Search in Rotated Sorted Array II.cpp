// [LeetCode]Search in Rotated Sorted Array II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:{3,4,4,5,6,1,2} 4
Output:true
*/
class Solution {
public:
	bool search(vector<int> nums, int first, int last, int target){
		if (first > last)
			return false;
		int mid = first + (last - first) / 2;
		if (target == nums[first] || target == nums[last] || target == nums[mid])
			return true;
		if (nums[first] == nums[last] && nums[first] == nums[mid]){
			for (int i = first + 1; i < last; ++i){
				if (nums[i] == target)
					return true;
			}
			return false;
		}
		if (nums[first] < target){
			if (nums[first] <= nums[mid] && target > nums[mid])
				return search(nums, mid + 1, last, target);
			else
				return search(nums, first, mid - 1, target);
		}
		else if (nums[last] > target){
			if (nums[mid] <= nums[last] && target < nums[mid])
				return search(nums, first, mid - 1, target);
			else
				return search(nums, mid + 1, last, target);
		}
		return false;
	}
	bool search(vector<int>& nums, int target) {
		if (nums.empty())
			return false;
		return search(nums, 0, nums.size() - 1, target);
	}
};

int main(void){
	Solution answer;
	int a[] = { 3, 1, 2, 2, 2};
	vector<int> ret;
	for (size_t i = 0; i < 5; ++i)
		ret.push_back(a[i]);
	cout << answer.search(ret, 1) << endl;
	system("Pause");
	return 0;
}

