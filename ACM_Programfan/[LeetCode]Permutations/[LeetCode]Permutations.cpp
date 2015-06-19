// [LeetCode]Permutations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:[1,2,3]
Output:[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2],[3,2,1].
*/

class Solution {
public:
	void dfs(vector<vector<int>>& ret, vector<int>& num, int cur){
		if (cur == num.size())
			ret.push_back(num);
		else{
			for (size_t i = cur; i < num.size(); ++i){
				swap(num[cur], num[i]);
				dfs(ret, num, cur + 1);
				swap(num[cur], num[i]);
			}
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>>ret;
		if (nums.size() == 0)
			return ret;
		dfs(ret, nums, 0);
		return ret;
	}
};
int main(void){
	Solution answer;
	int a[] = { 1, 2, 3 };
	vector<int> v;
	for (size_t i = 0; i < 3; ++i)
		v.push_back(a[i]);
	vector<vector<int>> ret = answer.permute(v);
	for (size_t i = 0; i < ret.size(); ++i){
		for (size_t j = 0; j < ret[i].size(); ++j)
			cout << ret[i][j] << " ";
		cout << endl;
	}

	system("Pause");
	return 0;
}