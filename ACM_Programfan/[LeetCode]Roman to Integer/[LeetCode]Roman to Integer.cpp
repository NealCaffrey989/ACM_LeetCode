// [LeetCode]Roman to Integer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
/*
Input: MDCLXVI
Output: 1666
*/
class Solution {
public:
	int toNumber(char ch) {
		switch (ch) {
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
		default:return 0;
		}
	}
	int romanToInt(string s) {
		int num = 0;
		int n = s.size();
		for (int i = 0; i < n; ++i){
			if (i < n - 1 && toNumber(s[i]) < toNumber(s[i + 1])){
				num += toNumber(s[i + 1]) - toNumber(s[i]);
				++i;
			}
			else
				num += toNumber(s[i]);
		}
		return num;
	}
};
int main(void){
	Solution answer;
	cout << answer.romanToInt("MDCLXVI") << endl;
	system("Pause");
	return 0;
}

