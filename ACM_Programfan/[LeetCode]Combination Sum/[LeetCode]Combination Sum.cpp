// [LeetCode]Combination Sum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
/*
Input:[2,3,6,7]  7
Output:[7] [2, 2, 3] 
*/
class Solution {
public:
	void makeCombination(vector<vector<int> > &ans, vector<int> &candidates, vector<int> &tmp, int target, int cur){
		for (size_t i = cur; i < candidates.size(); ++i){
			if (0 == target) {
				ans.push_back(tmp);
				return;
			}
			if (candidates[i] <= target){
				tmp.push_back(candidates[i]);
				makeCombination(ans, candidates, tmp, target - candidates[i], i);
				tmp.pop_back();
			}
			if (candidates[i] > target){
				return;
			}
		}
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector< vector<int> > ret;
		sort(candidates.begin(), candidates.end());
		if (candidates.empty() || target < candidates[0])
			return ret;
		vector<int> v;
		makeCombination(ret, candidates, v, target, 0);
		return ret;	
	}
};
int main(void){
	Solution answer;
	int a[] = { 3, 7 };
//	int a[] = { 1, 2 };
	vector<int> v;
	for (size_t i = 0; i < 2; ++i)
		v.push_back(a[i]);
	vector< vector<int> > com = answer.combinationSum(v, 17);
	for (size_t i = 0; i < com.size(); ++i){
		for (size_t j = 0; j < com[i].size(); ++j)
			cout << com[i][j] << " ";
		cout << endl;
	}
	system("Pause");
	return 0;
}

