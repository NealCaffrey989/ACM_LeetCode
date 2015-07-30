// [LeetCode]Decode Ways.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:"123456"
Output:3
*/
class Solution {
public:
	int numDecodings(string s) {
		if (s.empty())
			return 0;
		size_t len = s.size();
		vector<int> dp(len + 1, 1);
		for (size_t i = 1; i <= len; i++){
			dp[i] = s[i - 1] != '0' ? dp[i - 1] : 0;
			if (i != 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')))
				dp[i] += dp[i - 2];
		}
		return dp[len];
	}
};
int main(void){
	Solution answer;
	cout << answer.numDecodings("123456") << endl;
	system("Pause");
	return 0;
}

