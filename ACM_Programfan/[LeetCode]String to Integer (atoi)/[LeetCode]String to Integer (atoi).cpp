// [LeetCode]String to Integer (atoi).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
/*
Input: -123
Output: -123
*/
class Solution {
public:
	int atoi(string str) {
		if (str.size() == 0)
			return  0;
		bool sign = false;
		long long num = 0;
		string::const_iterator iter = str.begin();
		while (iter != str.end() && *iter == ' ')
			++iter;
		if (iter == str.end())
			return 0;
		if (*iter == '+' || *iter == '-'){
			if (*iter == '-')
				sign = true;
			iter++;
		}
		while (iter != str.end()){
			if (*iter >= '0'&&*iter <= '9'){
				num = num * 10 + *iter - '0';
				if (num > 2147483648){
					num = 2147483648;
					break;
				}
			}
			else
				break;
			++iter;
		}
		if (sign == true)
			num = 0 - num;
		else if (num == 2147483648)
			num--;
		return num;
	}
};
int main(void){
	Solution answer;
	cout << answer.atoi("abcabca") << endl;
	cout << answer.atoi("123") << endl;
	cout << answer.atoi("-123") << endl;
	cout << answer.atoi("2147483648") << endl;
	cout << answer.atoi("-2147483648") << endl;
	system("Pause");
	return 0;
}

