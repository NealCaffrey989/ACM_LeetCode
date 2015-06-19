// [LeetCode]Regular Expression Matching.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
/*
Input: *.123,23
Output: true
*/
class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		if (s == NULL || p == NULL)
			return false;
		if (*p == '\0')
			return *s == '\0';
		if (*s == *p || (*s != '\0'&&*p == '.'))
			return isMatch(s + 1, p + 1);
		else if (*p == '*'){
			while (*p == '*' || *p == '.')
				p++;
			while (*s != '\0'){
				if (*s == *p)
					break;
				++s;
			}
			return isMatch(s, p);
		}
	}
};
int main(void){
	Solution answer;
	cout << "Regular Expression Matching" << endl;
	cout << answer.isMatch("23", "*.123") << endl;
	cout << answer.isMatch("1123", "*.123") << endl;
	system("Pause");
	return 0;
}

