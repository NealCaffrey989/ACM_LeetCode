// [LeetCode]Valid Number.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
/*
Input:
Output:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
*/
class Solution {
public:
	bool isNumber(string s) {
		enum InputType{invalid, space, sign, digit, dot, eE, len};
		int trans[][len] =	{
			-1, 0, 1, 2, 3, -1,
			-1, -1, -1, 2, 3, -1,
			-1, 4, -1, 2, 6, 5,
			-1, -1, -1, 6, -1, -1,
			-1, 4, -1, -1, -1, -1,
			-1, -1, 7, 8, -1, -1,
			-1, 4, -1, 6, -1, 5,
			-1, -1, -1, 8, -1, -1,
			-1, 4, -1, 8, -1, -1,
		};
		int state = 0;
		string::const_iterator iter = s.begin();
		while (iter != s.end()){
			InputType inputType = invalid;
			if (*iter == ' ')
				inputType = space;
			else if (*iter == '+' || *iter == '-')
				inputType = sign;
			else if (isdigit(*iter))
				inputType = digit;
			else if (*iter == '.')
				inputType = dot;
			else if (*iter == 'e' || *iter == 'E')
				inputType = eE;
			state = trans[state][inputType];
			if (state == -1)
				return false;
			iter++;
		}
		return state == 2 || state == 4 || state == 6 || state == 8;
	}
};
int main(void){
	Solution answer;
	cout << answer.isNumber("0") << endl;
	cout << answer.isNumber("0.1") << endl;
	cout << answer.isNumber("abc") << endl;
	cout << answer.isNumber("0 a") << endl;
	cout << answer.isNumber("1e") << endl;
	cout << answer.isNumber("2e10") << endl;
	system("Pause");
	return 0;
}

