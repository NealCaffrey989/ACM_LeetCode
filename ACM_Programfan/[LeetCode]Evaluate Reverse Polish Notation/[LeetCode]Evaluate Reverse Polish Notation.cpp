// [LeetCode]Evaluate Reverse Polish Notation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
Input:["2", "1", "+", "3", "*"]
Output:9
*/
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		if (tokens.empty())
			return 0;
		stack<int> nums;
		for (size_t i = 0; i < tokens.size(); ++i){
			if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
				int num2 = nums.top();
				nums.pop();
				int num1 = nums.top();
				nums.pop();
				switch(tokens[i][0]){
					case '+':num1 = num1 + num2; break;
					case '-':num1 = num1 - num2; break;
					case '*':num1 = num1 * num2; break;
					case '/':num1 = num1 / num2; break;
				}
				nums.push(num1);
			}
			else{
				int num = 0; 
				size_t j = 0;
				int sign = 1;
				if (tokens[i][0] == '-'){
					sign = -1;
					j++;
				}
				else if (tokens[i][0] == '+')
					j++;
				for (; j < tokens[i].size();++j)
					num = num * 10 + tokens[i][j] - '0';					
				nums.push(sign*num);
			}
		}
		return nums.top();
	}
};
int main(void){
	Solution answer;
	string a[] = { "2", "1", "+", "-3", "*" };
	vector<string> ans;
	for (size_t i = 0; i < 5; ++i)
		ans.push_back(a[i]);
	cout << answer.evalRPN(ans) << endl;
	system("Pause");
	return 0;
}