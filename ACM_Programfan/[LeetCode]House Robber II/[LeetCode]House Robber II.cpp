// [LeetCode]House Robber II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Input:[3, 2, 1, 5, 6, 4]
Output:11
*/
class Solution {
public:
	int rob(vector<int>& nums, int begin, int end) {
		int p = 0, q = 0;
		for (int i = begin; i != end; i = (i + 1) % nums.size()) {
			int tmp = p;
			p = max(p, q + nums[i]);
			q = tmp;
		}
		return p;
	}
	int rob(vector<int>& nums) {
		if (nums.empty())
			return 0;
		if (nums.size() == 1)
			return nums[0];
		return max(rob(nums, 0, nums.size() - 1), rob(nums, 1, 0));
	}
};
int main(void){
	Solution answer;
	int a[] = { 3, 2, 1, 5, 6, 4 };
	vector<int> nums;
	for (size_t i = 0; i < 6; ++i)
		nums.push_back(a[i]);
	cout << answer.rob(nums) << endl;
	system("Pause");
	return 0;
}