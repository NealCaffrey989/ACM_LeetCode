// [LeetCode]Subsets.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
Input:
[1,2,3]
Output:
[
[3],
[1],
[2],
[1,2,3],
[1,3],
[2,3],
[1,2],
[]
]
*/
class Solution {
public:
	void fingSubsets(vector<vector<int>> &ret, vector<int> ans, vector<int> nums, int z){
		ret.push_back(ans);
		for (size_t i = z; i < nums.size(); ++i){
			ans.push_back(nums[i]);
			fingSubsets(ret, ans, nums, i + 1);
			ans.pop_back();
		}
	}
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> ret;
		if (nums.empty())
			return ret;
		sort(nums.begin(), nums.end());
		vector<int> ans;
		fingSubsets(ret, ans, nums, 0);
		return ret;
	}
};
int main(void){
	Solution answer;
	const int n = 3;
	int a[] = { 1, 2, 3 };
	vector<int> nums;
	for (size_t i = 0; i < n; ++i)
		nums.push_back(a[i]);
	vector<vector<int>> ret = answer.subsets(nums);
	for (size_t i = 0; i < ret.size(); ++i){
		for (size_t j = 0; j < ret[i].size(); ++j)
			cout << ret[i][j] << " ";
		cout << endl;
	}
	system("Pause");
	return 0;
}
