// [LeetCode]Minimum Size Subarray Sum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Input:[2,3,1,2,4,3],7
Output:2
*/
class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		if (nums.empty())
			return 0;
		int sum = 0, len = nums.size(), start = 0;
		bool flag = false;
		for (int end = 0; end < nums.size(); ++end) {
			sum += nums[end];
			while (sum >= s) {
				flag = true;
				len = min(len, end - start + 1);
				sum -= nums[start++];
			}
		}
		return flag ? len : 0;
	}
};
int main(void){
	Solution answer;
	vector<int> nums{ 2, 3, 1, 2, 4, 3 };
	cout << answer.minSubArrayLen(7, nums) << endl;
	system("Pause");
	return 0;
}