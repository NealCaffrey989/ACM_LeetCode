// [LeetCode]Product of Array Except Self.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:[1,2,3,4]
Output:[24,12,8,6]
*/
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> res(nums.size(), 1);
		if (nums.empty())
			return res;
		for (size_t i = 1; i < nums.size(); ++i)
			res[i] = res[i - 1] * nums[i - 1];
		int right = 1;
		for (int i = nums.size() - 2; i >= 0; --i){
			right *= nums[i + 1];
			res[i] = res[i] * right;
		}
		return res;
	}
};
int main(void){
	Solution answer;
	vector<int> nums{ 1, 2, 3, 4 };
	nums = answer.productExceptSelf(nums);
	for (size_t i = 0; i < nums.size(); ++i)
		cout << nums[i] << " ";
	cout << endl;
	system("Pause");
	return 0;
}