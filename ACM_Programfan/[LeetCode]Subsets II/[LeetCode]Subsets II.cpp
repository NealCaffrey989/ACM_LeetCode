// [LeetCode]Subsets II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Input:[1,2,2]
Output:
[
	[2],
	[1],
	[1,2,2],
	[2,2],
	[1,2],
	[]
]
*/
class Solution {
public:
	void findSubsetsWithDup(vector<vector<int>>& ret, vector<int> ans, vector<int> nums, int k){
		ret.push_back(ans);
		for (size_t i = k; i < nums.size(); ++i){
			if (i != k && nums[i] == nums[i - 1])
				continue;
			ans.push_back(nums[i]);
			findSubsetsWithDup(ret, ans, nums, i + 1);
			ans.pop_back();
		}
	}
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> ret;
		if (nums.empty())
			return ret;
		sort(nums.begin(), nums.end());
		vector<int> ans;
		findSubsetsWithDup(ret, ans, nums, 0);
		return ret;
	}
};
int main(void){
	Solution answer;
	int a[] = { 1, 2, 2 };
	vector<int> nums;
	for (size_t i = 0; i < 3; ++i)
		nums.push_back(a[i]);
	vector<vector<int>> ret = answer.subsetsWithDup(nums);
	for (size_t i = 0; i < ret.size(); ++i){
		for (size_t j = 0; j < ret[i].size(); ++j)
			cout << ret[i][j] << " ";
		cout << endl;
	}
	system("Pause");
	return 0;
}