// [LeetCode]Valid Anagram.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
Input:"anagram", "nagaram"
Output:true
*/
class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.empty() || t.empty()){
			if (s.empty() && t.empty())
				return true;
			else
				return false;
		}
		vector<int> count(26, 0);
		for (size_t i = 0; i < s.size(); i++)
			count[s[i] - 'a']++;
		for (size_t i = 0; i < t.size(); i++)
			count[t[i] - 'a']--;
		for (size_t i = 0; i < 26; i++)
		if (count[i] != 0)
			return false;
		return true;
	}
};
int main(void){
	Solution answer;
	cout << answer.isAnagram("anagram", "nagaram") << endl;
	cout << answer.isAnagram("", "nagaram") << endl;
	cout << answer.isAnagram("", "") << endl;
	cout << answer.isAnagram("car", "rat") << endl;
	system("Pause");
	return 0;
}

