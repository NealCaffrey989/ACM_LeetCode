// [LeetCode]Reverse Integer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
/*
Input: -123
Output: -321
*/
class Solution {
public:
	int reverse(int x) {
		bool sign = x > 0 ? false : true;
		int temp = x > 0 ? x : 0 - x;
		long long y = 0;
		while (temp){
			y = y * 10 + temp % 10;
			temp = temp / 10;
		}
		if (y > 2147483647 || (0 - y > 2147483648))
			return 0;
		if (sign == true)
			y = 0 - y;
		return y;
	}
};

int main(void){
	Solution answer;
	cout << answer.reverse(123) << endl;
	cout << answer.reverse(-123) << endl;
	cout << answer.reverse(2147483647) << endl;
	cout << answer.reverse(2147483648) << endl;
	cout << answer.reverse(-2147483647) << endl;
	system("Pause");
	return 0;
}

