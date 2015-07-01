// [LeetCode]Minimum Window Substring.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
Input:"ADOBECODEBANC"  "ABC"
Output:"BANC"
*/
class Solution {
public:
	string minWindow(string s, string t) {
		int begin = 0;
		int end = 0;
		int minbegin = 0;
		int minend = 0;
		int minSize = INT_MAX;
		vector<int> needFind(128, 0);
		vector<int> Found(128, 0);
		for (int i = 0; i < t.size(); i++)
			needFind[t[i]] ++;
		Found[s[0]] ++;
		int count = t.size();
		if (needFind[s[0]] >= Found[s[0]])
			count--;
		while (true){
			if (count == 0){
				while (Found[s[begin]] > needFind[s[begin]]){
					Found[s[begin]] --;
					begin++;
				}
				int size = end - begin + 1;
				if (size < minSize){
					minbegin = begin;
					minend = end;
					minSize = size;
				}
			}
			if (end < s.size()){
				end++;
				Found[s[end]] ++;
				if (needFind[s[end]] >= Found[s[end]])
					count--;
			}
			else
				break;
		}
		if (minSize != INT_MAX)
			return s.substr(minbegin, minSize);
		else
			return "";
	}
}; 
int main(void){
	Solution answer;
	cout << answer.minWindow("ADOBECODEBANC","ABC") << endl;
	system("Pause");
	return 0;
}

