// [HihoCoder][1032]最长回文子串.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/*
Input:
3
abababa
aaaabaa
acacdas
Output:
7
5
3
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int LongetPalindromeStringNum(string s) {
	string s1;
	s1.resize(2 * s.size() + 2);
	s1[0] = '$';
	s1[1] = '#';
	for (int i = 0; i < s.size(); ++i) {
		s1[(i + 1) << 1] = s[i];
		s1[((i + 1) << 1) + 1] = '#';
	}
	vector<int> p(s1.size(), 0);
	int res = 0;
	for (int id = 0, i = 1; i < s1.size(); ++i) {
		if (p[id] + id > i) 
			p[i] = min(p[2 * id - i], p[id] + id - i);
		else 
			p[i] = 1;
		while (s1[i + p[i]] == s1[i - p[i]]) 
			++p[i];
		if (i + p[i] > id + p[id]) 
			id = i;
		res = max(res, p[i]);
	}
	return res - 1;
}
void getLongetPalindromeString(void){
	int strNum;
	cin >> strNum;
	while (strNum--){
		string str;
		cin >> str;
		cout << LongetPalindromeStringNum(str) << endl;
	}
}
int main(void){
	getLongetPalindromeString();
	system("Pause");
	return 0;
}