// [LeetCode]Palindrome Partitioning.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Input:"aab"
Output:
[
["aa","b"],
["a","a","b"]
]
*/
class Solution {
public:
	void dps(vector<vector<string>>& ret, vector<string> str){

	}
	vector<vector<string>> partition(string s) {
		vector<vector<string>> ret;
		if (s.empty())
			return ret;
		vector<string> str;
		dps(ret, str);
	}
};
int main(void){
	Solution answer;
	string str("aab");
	vector<vector<string>> ret=answer.partition(str);
	system("Pause");
	return 0;
}


