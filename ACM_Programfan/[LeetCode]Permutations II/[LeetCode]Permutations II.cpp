// [LeetCode]Permutations II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:[1,1,2,]
Output:[1,1,2], [1,2,1], [2,1,1]
*/
class Solution {
public:
	bool noswap(vector<int> &num, int i, int cur) {
		for (int j = cur; j < i; j++) 
			if (num[i] == num[j])
				return true;
		return false;
	}
	void dfs(vector<vector<int>>& ret, vector<int>& num, int cur){
		if (cur == num.size())
			ret.push_back(num);
		else{
			for (size_t i = cur; i < num.size(); ++i){
				if (noswap(num, i, cur))
					continue;
				swap(num[cur], num[i]);
				dfs(ret, num, cur + 1);
				swap(num[cur], num[i]);
			}
		}
	}
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>>ret;
		if (nums.size() == 0)
			return ret;
		dfs(ret, nums, 0);
		return ret;
	}
};
int main(void){
	Solution answer;
	int a[] = { 1, 1, 3 };
	vector<int> v;
	for (size_t i = 0; i < 3; ++i)
		v.push_back(a[i]);
	vector<vector<int>> ret = answer.permuteUnique(v);
	for (size_t i = 0; i < ret.size(); ++i){
		for (size_t j = 0; j < ret[i].size(); ++j)
			cout << ret[i][j] << " ";
		cout << endl;
	}

	system("Pause");
	return 0;
}
