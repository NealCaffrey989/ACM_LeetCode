// [LeetCode]Maximum Product Subarray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Input:[2,3,-2,4]
Output:6
*/
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.empty())
			return 0;
		size_t n = nums.size();
		int maxnum=nums[0];
		int minnum = nums[0];
		int globle = nums[0];
		for (size_t i = 1; i < n; ++i){
			int temp = maxnum;
			maxnum = max(max(maxnum*nums[i], minnum*nums[i]), nums[i]);
			minnum = min(min(temp*nums[i], minnum*nums[i]), nums[i]);
			globle = max(globle, maxnum);
		}
		return globle;
	}
};
int main(void){
	Solution answer;
	int a[] = { 2, 3, -2, 4 };
	vector<int> nums;
	for (size_t i = 0; i < 4; ++i)
		nums.push_back(a[i]);
	cout << answer.maxProduct(nums) << endl;
	system("Pause");
	return 0;
}