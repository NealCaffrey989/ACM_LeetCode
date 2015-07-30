// [LeetCode]Maximal Square.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Input:
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Output:4
*/
class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) 
			return 0;
		int M = matrix.size(), N = matrix[0].size(), res = 0;
		vector<vector<int>> dp(M, vector<int>(N, 0));
		for (size_t i = 0; i < max(N, M); ++i){
			if (i < N&&matrix[0][i] == '1'){
				dp[0][i] = 1;
				res = 1;
			}
			if (i < M&&matrix[i][0] == '1'){
				dp[i][0] = 1;
				res = 1;
			}
		}
		for (size_t i = 1; i < M; ++i){
			for (size_t j = 1; j < N; ++j)
				if (matrix[i][j] == '1'){
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
					res = max(res, dp[i][j]);
				}
		}
		return res*res;
	}
};
int main(void){
	Solution answer;
	vector<vector<char>> ret = {
		{ '1', '0', '1', '0', '0' },
		{ '1', '0', '1', '1', '1' },
		{ '1', '1', '1', '1', '1' },
		{ '1', '0', '0', '1', '0' }
	};
	cout << answer.maximalSquare(ret) << endl;
	system("Pause");
	return 0;
}