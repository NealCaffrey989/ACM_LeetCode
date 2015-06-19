// [LeetCode]Combination Sum II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Input:[10,1,2,7,6,1,5] and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
Output:
*/
class Solution {
public:
	void makeCombination2(vector<vector<int>>& ret, vector<int>& candidates, vector<int>& v, int target, int cur){
		if (target == 0){
			ret.push_back(v);
			return;
		}
		int rep = -1;
		for (size_t i = cur; i < candidates.size(); ++i){
			if (rep == candidates[i])
				continue;
			if (target >= candidates[i]){
				rep = candidates[i];
				v.push_back(candidates[i]);
				makeCombination2(ret, candidates, v, target - candidates[i], i + 1);
				v.pop_back();
			}
			else
				return;
		}
	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> ret;
		sort(candidates.begin(), candidates.end());
		if (candidates.empty() || target < candidates[0])
			return ret;
		vector<int> v;
		makeCombination2(ret, candidates, v, target, 0);
		return ret;
	}
};
int main(void){
	Solution answer;
//	int a[] = { 10, 1, 2, 7, 6, 1, 5 };
	int a[] = { 2, 2, 2, 2, 2, 2, 2 };
	vector<int> v;
	for (size_t i = 0; i < 7; ++i)
		v.push_back(a[i]);
	vector< vector<int> > com = answer.combinationSum2(v, 8);
	for (size_t i = 0; i < com.size(); ++i){
		for (size_t j = 0; j < com[i].size(); ++j)
			cout << com[i][j] << " ";
		cout << endl;
	}
	system("Pause");
	return 0;
}
