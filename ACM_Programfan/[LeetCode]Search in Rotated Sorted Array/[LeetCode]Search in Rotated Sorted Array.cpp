// [LeetCode]Search in Rotated Sorted Array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:{3,4,5,6,1,2} 4
Output:1
*/

class Solution {
public:
	int search(vector<int>& nums, int f, int l, int target) {
		if (f>l)
			return -1;
		if (target == nums[f])
			return f;
		if (target == nums[l])
			return l;
		int mid = f + (l - f) / 2;
		if (target == nums[mid])
			return mid;
		if (nums[f] == nums[l] && nums[f] == nums[mid]){
			for (int i = f; i<l; i++){
				if (nums[i] == target)
					return i;
			}
			return -1;
		}
		if (nums[f] < target){
			if (nums[f] < nums[mid] && target > nums[mid])
				return search(nums, mid + 1, l, target);
			else
				return search(nums, f, mid - 1, target);
		}
		else if(nums[l]>target){
			if (nums[mid]<nums[l] && target < nums[mid])
				return search(nums, f, mid - 1, target);
			else
				return search(nums, mid + 1, l, target);
		}
		return -1;
	}
	int search(vector<int>& nums, int target) {
		if (nums.empty())
			return -1;
		return search(nums, 0, nums.size()-1, target);
	}
};

int main(void){
	Solution answer;
	int a[] = { 3, 1, 2, 2, 2 };
	vector<int> ret;
	for (size_t i = 0; i < 5; ++i)
		ret.push_back(a[i]);
	cout << answer.search(ret, 1) << endl;
	cout << answer.search(ret, 7) << endl;
	cout << answer.search(ret, 4) << endl;
	cout << answer.search(ret, 9) << endl;
	cout << answer.search(ret, 10) << endl;
	cout << answer.search(ret, 3) << endl;
	system("Pause");
	return 0;
}

