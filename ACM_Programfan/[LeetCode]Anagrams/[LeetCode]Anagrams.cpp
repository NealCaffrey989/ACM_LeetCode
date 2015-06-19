// [LeetCode]Anagrams.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
/*
Input:["abc","acb","acd"]
Output:"abc"
*/
class Solution {
public:
	vector<string> anagrams(vector<string>& strs) {
		vector<string> ret;
		if (strs.empty())
			return ret;
		vector<string> ans = strs;
		size_t n = ans.size();
		map<string, int> strmap;
		for (size_t i = 0; i < n; ++i){
			sort(ans[i].begin(), ans[i].end());
			if (strmap.find(ans[i]) == strmap.end())
				strmap[ans[i]] = i;
			else{
				int index = strmap[ans[i]];
				if (index >= 0){
					ret.push_back(strs[index]);
					strmap[ans[i]] = -1;
				}
				ret.push_back(strs[i]);
			}
		}
		return ret;
	}
};
int main(void){
	Solution answer;
	string str[] = { "abc", "acb", "acf" };
	vector<string> strs;
	for (size_t i = 0; i < 3; ++i)
		strs.push_back(str[i]);
	vector<string> ret = answer.anagrams(strs);
	for (size_t i = 0; i < ret.size(); ++i)
		cout << ret[i] << " ";
	cout << endl;
	system("Pause");
	return 0;
}

