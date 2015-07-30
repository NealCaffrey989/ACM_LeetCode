// [LeetCode]Scramble String.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*
Input:rgate rgeat
Output:true
*/
class Solution {
public:
	bool isContainSameChars(string s1, string s2){
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		if (s1 == s2)
			return true;
		else
			return false;
	}
	bool isScramble(string s1, string s2) {
		if (!isContainSameChars(s1, s2))
			return false;
		if (s1 == s2)
			return true;
		for (int split = 1; split < s1.length(); split++){
			string s11 = s1.substr(0, split);
			string s12 = s1.substr(split);
			string s21 = s2.substr(0, split);
			string s22 = s2.substr(split);
			if (isScramble(s11, s21) && isScramble(s12, s22)) 
				return true;
			s21 = s2.substr(0, s2.length() - split);
			s22 = s2.substr(s2.length() - split);
			if (isScramble(s11, s22) && isScramble(s12, s21)) 
				return true;
		}
		return false;
	}
};
int main(void){
	Solution answer;
	cout << answer.isScramble("rgeat", "rgate") << endl;
	system("Pause");
	return 0;
}

