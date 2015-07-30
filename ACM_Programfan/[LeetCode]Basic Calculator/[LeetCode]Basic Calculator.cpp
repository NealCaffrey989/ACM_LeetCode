// [LeetCode]Basic Calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stack>
using namespace std;
/*
Input:"(1+(4+5+2)-3)+(6+8)"
Output:23
*/
class Solution {
public:
	int calculate(string s) {
		if (s.empty())
			return 0;
		stack<int> sign;
		sign.push(1);
		int op = 1;
		int sum = 0;
		for (string::const_iterator iter = s.begin(); iter != s.end(); ++iter){
			switch (*iter){
				case '+':op = 1; break;
				case '-':op = -1; break;
				case '(':
					sign.push(sign.top()*op);
					op = 1;
					break;
				case ')':
					sign.pop();
					break;
				default:
					if (isalnum(*iter)){
						int num = *iter - '0';
						while (++iter != s.end() && isalnum(*iter))
							num = num * 10 + *iter - '0';
						sum += op*num*sign.top();
						--iter;
					}
			}
		}
		return sum;
	}
};
int main(void){
	Solution answer;
	cout << answer.calculate("(1+(4+5+2)-3)-(6+8)") << endl;
	system("Pause");
	return 0;
}

