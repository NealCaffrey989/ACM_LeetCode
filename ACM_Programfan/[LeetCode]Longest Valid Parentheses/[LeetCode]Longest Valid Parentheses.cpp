// [LeetCode]Longest Valid Parentheses.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;
/*
Input:()()
Output:4
*/
class Solution {
public:
	int longestValidParentheses(string s) {
		if (s.empty())
			return 0;
		stack< pair<char,int> > validStack;
		for (string::const_iterator iter = s.begin(); iter != s.end(); iter++){
			if (*iter == '(')
				validStack.push(make_pair('(',iter - s.begin()));
			else if (*iter == ')'){
				if (!validStack.empty() && validStack.top().first == '('){
					validStack.pop();
				}
				else
					validStack.push(make_pair(*iter,iter - s.begin()));
			}
		}
		if (validStack.empty())
			return s.size();
		int temp = validStack.top().second;
		int max = s.size() - 1 - temp ;
		validStack.pop();
		while (!validStack.empty()){
			if (max < temp - validStack.top().second - 1)
				max = temp - validStack.top().second - 1;
			temp = validStack.top().second;
			validStack.pop();
		}
		if (max < temp)
			return temp;
		return max;
	}
};

int main(void){
	Solution answer;
	cout << answer.longestValidParentheses("(()()))") << endl;
	cout << answer.longestValidParentheses("(()((()())") << endl;
	cout << answer.longestValidParentheses(")()(()") << endl;
	system("Pause");
	return 0;
}

