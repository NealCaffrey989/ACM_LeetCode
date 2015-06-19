// [LeetCode]Search for a Range.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:[5,7,7,8,8,9] 8
Output:[3,4]
*/
class Solution {
public:
	int searchfRange(vector<int>& nums, int f, int l, int target){
		if (f > l || nums[l] != target)
			return l + 1;
		if (nums[f] == target)
			return f;
		int mid = f + (l - f) / 2;
		if (nums[mid] == target)
			return searchfRange(nums, f, mid - 1, target);
		else
			return searchfRange(nums, mid + 1, l, target);
	}
	int searchlRange(vector<int>& nums, int f, int l, int target){
		if (f > l || nums[f] != target)
			return f - 1;
		if (nums[l] == target)
			return l;
		int mid = f + (l - f) / 2;
		if (nums[mid] == target)
			return searchlRange(nums, mid + 1, l, target);
		else
			return searchlRange(nums, f, mid - 1, target);
	}
	vector<int> searchRange(vector<int>& nums, int f, int l, int target){
		if (f > l || target < nums[f] || target > nums[l])
			return vector<int>(2, -1);
		vector<int> range(2,-1);
		int mid = f + (l - f) / 2;
		if (nums[f] == target){
			range[0] = f;
			range[1] = searchlRange(nums, f+1, l, target);
			return range;
		}
		if (nums[l] == target){
			range[0] = searchfRange(nums, f, l-1, target);
			range[1] = l;
			return range;
		}
		if (nums[mid] == target){
			range[0] = searchfRange(nums, f, mid - 1, target);
			range[1] = searchlRange(nums, mid + 1, l, target);
			return range;
		}
		else if (nums[mid] < target)
			return searchRange(nums, mid + 1, l, target);
		else
			return searchRange(nums, f, mid - 1, target);
	}
	vector<int> searchRange(vector<int>& nums, int target) {
		if (target<nums.front() || target>nums.back())
			return vector<int>(2, -1);
		return searchRange(nums, 0, nums.size() - 1, target);
	}
};

int main(void){
	Solution answer;
	vector<int> v,f;
	v.push_back(5);
	v.push_back(5);
	v.push_back(7);
	v.push_back(8);
	v.push_back(8);
	v.push_back(9);
	for (int i = 0; i < v.size(); i++)
		cout << i << " ";
	cout << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
	cout << answer.searchRange(v, 2)[0] << " " << answer.searchRange(v, 2)[1] << endl;
	cout << answer.searchRange(v, 5)[0] << " " << answer.searchRange(v, 5)[1] << endl;
	cout << answer.searchRange(v, 7)[0] << " " << answer.searchRange(v, 7)[1] << endl;
	cout << answer.searchRange(v, 9)[0] << " " << answer.searchRange(v, 9)[1] << endl;
	system("Pause");
	return 0;
}

