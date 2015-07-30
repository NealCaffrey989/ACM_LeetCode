// [LeetCode]Distinct Subsequences.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Input:"rabbbit","rabit"
Output:3
*/
class Solution {
public:
	int numDistinct(string s, string t) {
		if (s.empty() || t.empty())
			return 0;
		size_t row = s.size();
		size_t col = t.size();
		vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
		dp[0][0] = 1;
		for (size_t i = 1; i <= row; i++){
			for (size_t j = 0; j <= col; j++) {
				if (j == 0){
					dp[i][j] = 1;
					continue;
				}
				dp[i][j] = dp[i - 1][j];
				if (s[i - 1] == t[j - 1])
					dp[i][j] += dp[i - 1][j - 1];
			}
		}
		return dp[row][col];
	}
};
int main(void){
	Solution answer;
	cout << answer.numDistinct("rabbbit","rabit") << endl;
	cout << answer.numDistinct("a", "b") << endl;
	system("Pause");
	return 0;
}
