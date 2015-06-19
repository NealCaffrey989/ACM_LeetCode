// [LeetCode]Longest Substring Without Repeating Characters.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;
/*
Input: s=abcabcbb
Output: abc
*/
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		map<char, int> str_map;
		int maxlen = 0, flag = -1;
		for (int i = 0; i < s.size(); i++){
			if (!str_map.count(s[i])){
				str_map.insert(make_pair(s[i], -1));
			}
		}
		for (int i = 0; i < s.size(); i++){
			if (str_map[s[i]]>flag)
				flag = str_map[s[i]];
			if (i - flag > maxlen)
				maxlen = i - flag;
			str_map[s[i]] = i;
		}
		return maxlen;
	}
};


int main(void){
	Solution answer;
	cout << answer.lengthOfLongestSubstring("abcabca") << endl;
	cout << answer.lengthOfLongestSubstring("abba") << endl;
	cout << answer.lengthOfLongestSubstring("bbbbb") << endl;
	system("Pause");
	return 0;
}

