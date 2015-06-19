// [LeetCode]Substring with Concatenation of All Words.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
/*
Input:"barfoothefoobarman"  ["foo", "bar"]
Output:[0,9]
*/
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> res;
		if (s.empty() || words.empty() || s.size() < words.size()*words[0].size())
			return res;
		int  searchEnd = s.size() - words.size() * words[0].size();
		size_t wordLen = words[0].size(), wordNum = words.size();
		map<string, int> total, submap;
		for (size_t i = 0; i < wordNum; ++i)
			total[words[i]]++;
		for (size_t i = 0; i <= searchEnd; ++i){
			submap.clear();
			size_t k = 0;
			for (size_t j = i; k < wordNum; j += wordLen, ++k){
				string str = s.substr(j, wordLen);
				if (total.find(str) == total.end())
					break;
				else if (++submap[str]>total[str])
					break;
			}
			if (k == words.size())
				res.push_back(i);
		}
		return res;
	}
};

int main(void){
	Solution answer;
	string s[] = { "foo", "bar" ,"xcx"};
	vector<string> str;
	for (int i = 0; i < 3; ++i)
		str.push_back(s[i]);
	vector<int> v=answer.findSubstring("barfooxcxthefooxcxfoobarman",str);
	for (size_t i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	system("Pause");
	return 0;
}
