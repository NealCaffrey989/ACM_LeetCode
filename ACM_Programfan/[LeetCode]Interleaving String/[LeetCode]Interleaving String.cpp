// [LeetCode]Interleaving String.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Input:"aabcc", "dbbca", "aadbbcbcac"
Output:1
*/
class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.size() + s2.size() != s3.size())
			return false;
		vector < vector<bool>> matched(s1.size() + 1, vector<bool>(s2.size() + 1, false));
		matched[0][0] = true;
		for (size_t i = 1; i <= s1.size(); i++){
			if (s3[i - 1] == s1[i - 1])
				matched[i][0] = true;
			else 
				break;
		}
		for (size_t i = 1; i <= s2.size(); i++){
			if (s3[i - 1] == s2[i - 1])
				matched[0][i] = true;
			else 
				break;
		}
		for (size_t i = 1; i <= s1.size(); i++) {
			for (size_t j = 1; j <= s2.size(); j++) {
				if (s1[i - 1] == s3[i + j - 1])
					matched[i][j] = matched[i - 1][j] || matched[i][j];
				if (s2[j - 1] == s3[i + j - 1])
					matched[i][j] = matched[i][j - 1] || matched[i][j];
			}
		}return matched[s1.size()][s2.size()];
	}
};
int main(void){
	Solution answer;
	cout << answer.isInterleave("abb", "bcc","abbbcc") << endl;
	cout << answer.isInterleave("a", "bcde","bacde") << endl;
	cout << answer.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
	system("Pause");
	return 0;
}