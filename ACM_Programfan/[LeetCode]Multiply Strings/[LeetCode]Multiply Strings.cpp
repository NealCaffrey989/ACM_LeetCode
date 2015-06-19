// [LeetCode]Multiply Strings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
Input:"12345", "2"
Output:24690
*/
class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1.size() == 0)
			return num2;
		else if (num2.size() == 0)
			return num1;
		vector<int> v(num1.size() + num2.size() - 1, 0);
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		for (string::size_type i = 0; i < num2.size(); i++){
			if (num2[i] != '0'){
				for (string::size_type j = 0; j < num1.size(); j++){
					v[i + j] += (num1[j] - '0')*(num2[i] - '0');
				}
			}
		}
		string str="";
		int temp(0);
		for (vector<int>::size_type i = 0; i < v.size(); i++){
			str += '0' + (v[i] + temp) % 10;
			temp = (v[i] + temp) / 10;
		}
		if (temp>0)
			str += '0' +  temp % 10;
		reverse(str.begin(), str.end());
		string::const_iterator iter = str.begin();
		for (; iter != str.end() && *iter == '0'; ++iter);
		if (iter == str.end())
			return "0";
		else
			return str.substr(iter - str.begin(), str.end() - iter);
	}
};

int main(void){
	Solution answer;
	cout << answer.multiply("9999", "0") << endl;
	cout << answer.multiply("12345", "002") << endl;

	system("Pause");
	return 0;
}


