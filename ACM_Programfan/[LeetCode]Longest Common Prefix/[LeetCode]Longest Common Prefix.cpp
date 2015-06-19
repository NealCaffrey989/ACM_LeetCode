// [LeetCode]Longest Common Prefix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Input: asdfgh asdert asdeer
Output: asd
*/
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)
			return "";
		string str = strs[0];
		for (int i = 1; i < strs.size(); i++){
			if (strs[i].size() == 0 || str.size() == 0)
				return "";
			int n = (str.size()<strs[i].size() ? str.size() : strs[i].size());
			int j = 0;
			for (; j < n; j++){
				if (str[j] != strs[i][j])
					break;
			};
			str = str.substr(0, j);
		}
		return str;
	}
};
int main(void){
	Solution answer;
	vector<string> s;
	s.push_back("asdfgh");
	s.push_back("asdz");
	cout << answer.longestCommonPrefix(s) << endl;
	system("Pause");
	return 0;
}

