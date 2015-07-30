// [LeetCode]House Robber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Input:[3, 2, 1, 5, 6, 4]
Output:5
*/
class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.empty())
			return 0;
		size_t n = nums.size();
		vector<int> cost(n);
		for (size_t i = 0; i < n; ++i){
			if (i == 0)
				cost[i] = nums[i];
			else if (i == 1)
				cost[i] = max(nums[i], cost[i - 1]);
			else
				cost[i] = max(nums[i] + cost[i - 2], cost[i - 1]);
		}
		return cost[n - 1];
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


