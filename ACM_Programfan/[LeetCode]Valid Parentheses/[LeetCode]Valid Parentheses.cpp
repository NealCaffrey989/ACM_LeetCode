// [LeetCode]Valid Parentheses.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stack>
using namespace std;
/*
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/
class Solution {
public:
	bool isValid(string s) {
		stack<char> sign;
		for (string::const_iterator iter = s.begin(); iter != s.end(); ++iter){
			switch (*iter){
			case '(':
			case '{':
			case '[':sign.push(*iter); break;
			case ')':
				if (sign.size() && sign.top() == '('){
					sign.pop(); break;
				}
			case '}':
				if (sign.size() && sign.top() == '{'){
					sign.pop(); break;
				}
			case ']':
				if (sign.size() && sign.top() == '['){
					sign.pop(); break;
				}
				return false;
			default:break;
			}
		}
		if (sign.size())
			return false;
		else
			return true;
	}
};
int main(void){
	Solution answer;
	cout << answer.isValid("[{()[]}]") << endl;
	system("Pause");
	return 0;
}


