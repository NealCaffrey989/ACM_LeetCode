// [LeetCode]Factorial Trailing Zeroes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
/*
Input:10
Output:2
*/
class Solution {
public:
	int trailingZeroes(int n) {
		int ret = 0;
		while (n){
			ret += n / 5;
			n /= 5;
		}
		return ret;
	}
};
int main(void){
	Solution answer;
	cout << answer.trailingZeroes(5) << endl;
	cout << answer.trailingZeroes(2) << endl;
	cout << answer.trailingZeroes(3) << endl;
	cout << answer.trailingZeroes(-1) << endl;
	system("Pause");
	return 0;
}