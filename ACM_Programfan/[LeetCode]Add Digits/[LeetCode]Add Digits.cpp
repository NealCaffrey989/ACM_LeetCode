// [LeetCode]Add Digits.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
/*
Input:11
Output:2
*/
class Solution {
public:
	int addDigits(int num) {
		if (num <= 0)
			return 0;
		return num % 9 == 0 ? 9 : num % 9;
	}
};
int main(void){
	Solution answer;
	cout << answer.addDigits(11) << endl;
	cout << answer.addDigits(-1) << endl;
	cout << answer.addDigits(0) << endl;
	cout << answer.addDigits(9) << endl;
	cout << answer.addDigits(123) << endl;
	system("Pause");
	return 0;
}