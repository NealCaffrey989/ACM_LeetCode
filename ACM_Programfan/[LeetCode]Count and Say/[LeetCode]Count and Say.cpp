// [LeetCode]Count and Say.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
Input:5
Output:111221
*/

class Solution {
public:
	string countAndSay(string n) {
		string str = "";
		char s = '-';
		int count = 0;
		for (string::const_iterator iter = n.begin(); iter != n.end(); ++iter){
			if (s == '-'){
				s = *iter;
				count++;
			}
			else if (s == *iter)
				count++;
			else{
				str += '0' + count;
				count = 1;
				str += s;
				s = *iter;
			}
		}
		str += '0' + count;
		str += s;
		return str;
	}
	string countAndSay(int n) {
		if (n <= 0)
			return "";
		string ret = "1";
		while (n-- > 1)
			ret = countAndSay(ret);
		return ret;
	}
};
int main(void){
	Solution answer;
//	cout << answer.countAndSay("11221112") << endl;
	cout << answer.countAndSay(5) << endl;
	cout << answer.countAndSay(1) << endl;
	cout << answer.countAndSay(0) << endl;
	system("Pause");
	return 0;
}

