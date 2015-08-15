// [LeetCode]Isomorphic Strings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;
/*
Input:"egg", "add"
Output:true
*/
class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if (s.size() != t.size())
			return false;
		map<char, char> mp;
		for (size_t i = 0; i < s.size(); ++i){
			if (mp.find(s[i]) == mp.end())
				mp[s[i]] = t[i];
			else if (mp[s[i]] != t[i])
				return false;
		}
		mp.clear();
		for (size_t i = 0; i < t.size(); ++i){
			if (mp.find(t[i]) == mp.end())
				mp[t[i]] = s[i];
			else if (mp[t[i]] != s[i])
				return false;
		}
		return true;
	}
};
int main(void){
	Solution answer;
	cout << answer.isIsomorphic("egg", "add") << endl;
	cout << answer.isIsomorphic("foo", "bar") << endl;
	cout << answer.isIsomorphic("paper", "title") << endl;
	system("Pause");
	return 0;
}