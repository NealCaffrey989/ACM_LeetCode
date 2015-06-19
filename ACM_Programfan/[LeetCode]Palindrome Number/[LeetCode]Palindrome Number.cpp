// [LeetCode]Palindrome Number.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
/*
Input: 12321
Output: true
*/
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		if (x == 0)
			return true;
		int base = 1;
		while (x / base >= 10)
			base *= 10;
		while (x){
			int leftDigit = x / base;
			int rightDigit = x % 10;
			if (leftDigit != rightDigit)
				return false;
			x -= base * leftDigit;
			base /= 100;
			x /= 10;
		}
		return true;
	}
};
int main(void){
	Solution answer;
	cout << answer.isPalindrome(12321) << endl;
	cout << answer.isPalindrome(123621) << endl;
	system("Pause");
	return 0;
}

