// [LeetCode]Combination Sum III.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:3,9
Output:[[1,2,6], [1,3,5], [2,3,4]]
*/
class Solution {
public:
	void combinationSum3(vector<vector<int>>& ret, vector<int> ans, int i, int k, int n) {
		if (k == ans.size() && n == 0){
			ret.push_back(ans);
			return;
		}
		else if (k == ans.size() || n == 0)			
			return;
		for (; i <= (9>n ? n : 9); ++i){
			ans.push_back(i);
			combinationSum3(ret, ans, i + 1, k, n - i);
			ans.pop_back();
		}
	}
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> ret;
		vector<int> ans;
		combinationSum3(ret, ans, 1, k, n);
		return ret;
	}
};
int main(void){
	Solution answer;
	vector<vector<int>>ret = answer.combinationSum3(3, 9);
	for (size_t i = 0; i < ret.size(); ++i){
		for (size_t j = 0; j < ret[i].size(); ++j)
			cout << ret[i][j] << " ";
		cout << endl;
	}
	system("Pause");
	return 0;
}

