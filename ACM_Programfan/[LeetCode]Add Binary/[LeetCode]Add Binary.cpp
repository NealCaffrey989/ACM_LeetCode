// [LeetCode]Add Binary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*
Input:11 1
Output:100
*/
class Solution {
public:
	string addBinary(string a, string b) {
		if (a.empty())
			return b;
		if (b.empty())
			return a;
		int itera = a.size()-1, iterb = b.size()-1;
		string c;
		int up = 0;
		while (itera >= 0 && iterb >= 0) {
			int num = a[itera] + b[iterb] - 2 * '0' + up;
			up = num / 2;
			num = num % 2;
			c = (char)('0' + num) + c;
			itera--;
			iterb--;
		}
		while (itera >= 0){
			int num = a[itera] - '0' + up;
			up = num / 2;
			num = num % 2;
			c = (char)('0' + num) + c;
			itera--;
		}
		while (iterb >= 0){
			int num = b[iterb] - '0' + up;
			up = num / 2;
			num = num % 2;
			c = (char)('0' + num) + c;
			iterb--;
		}
		if (up != 0)
			c = (char)('0' + up) + c;
		return c;
	}
};
int main(void){
	Solution answer;
	cout << answer.addBinary("11", "1") << endl;
	system("Pause");
	return 0;
}

