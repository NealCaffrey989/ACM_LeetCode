// [LeetCode]Longest Palindromic Substring.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
Input: abcfcbd
Output: bcfcb
*/
class Solution {
public:
	string longestPalindrome(string s) {
		string s1;
		s1.resize(2 * s.size() + 2);
		s1[0] = '$';
		s1[1] = '#';
		for (int i = 0; i < s.size(); ++i) {
			s1[(i + 1) << 1] = s[i];
			s1[((i + 1) << 1) + 1] = '#';
		}
		vector<int> p(s1.size(), 0);
		int res = 0, id = 0, first = 0;
		for (int i = 1; i < s1.size(); ++i) {
			if (p[id] + id > i)
				p[i] = min(p[2 * id - i], p[id] + id - i);
			else
				p[i] = 1;
			while (s1[i + p[i]] == s1[i - p[i]])
				++p[i];
			if (i + p[i] > id + p[id])
				id = i;
			res = max(res, p[i]);
			if (res == p[i])
				first = (i - res) / 2;
		}
		return s.substr(first,res-1);
	}
};

int main(void){
	Solution answer;
	cout << answer.longestPalindrome("abcabca") << endl;
	cout << answer.longestPalindrome("abba") << endl;
	cout << answer.longestPalindrome("bbbbb") << endl;
	cout << answer.longestPalindrome("ccd") << endl;
	system("Pause");
	return 0;
}

