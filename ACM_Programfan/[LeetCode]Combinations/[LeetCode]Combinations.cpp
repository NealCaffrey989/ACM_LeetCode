// [LeetCode]Combinations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:4 2
Output:
[
[2,4],
[3,4],
[2,3],
[1,2],
[1,3],
[1,4],
]
*/
class Solution {
public:
	void findCombine(vector<vector<int>> &ret, vector<int> ans, int start, int n, int k){
		if (k == ans.size()){
			ret.push_back(ans);
			return;
		}
		for (size_t i = start; i <= n; ++i){
			ans.push_back(i);
			findCombine(ret, ans, i + 1, n, k);
			ans.pop_back();
		}
	}
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> ret;
		if (n == 0 || k == 0 || n < k)
			return ret;
		vector<int> ans;		
		findCombine(ret, ans, 1, n, k);
		return ret;
	}
};
int main(void){
	Solution answer;
	vector<vector<int>> ret;
	ret=answer.combine(4, 2);
	for (size_t i = 0; i < ret.size(); ++i){
		for (size_t j = 0; j < ret[i].size(); ++j)
			cout << ret[i][j] << " ";
		cout << endl;
	}
	system("Pause");
	return 0;
}

