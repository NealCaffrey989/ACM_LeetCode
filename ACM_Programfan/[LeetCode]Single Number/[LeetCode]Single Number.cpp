// [LeetCode]Single Number.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:
Output:
*/
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		if (nums.empty())
			return 0;
		if (nums.size() == 1)
			return nums[0];
		int ret = nums[0];
		for (size_t i = 1; i < nums.size(); ++i)
			ret = ret^nums[i];
		return ret;
	}
};
int main(void){
	Solution answer;
	int a[] = { 1, 2, 2, 1, 3, 4, 5, 4, 3 };
	vector<int> ret;
	for (size_t i = 0; i < 9; ++i)
		ret.push_back(a[i]);
	cout << answer.singleNumber(ret) << endl;
	system("Pause");
	return 0;
}

