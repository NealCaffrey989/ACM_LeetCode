// [LeetCode]Pow(x, n).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
/*
Input:
Output:
*/
class Solution {
public:
	double myPow(double x, int n) {
		if (x == 0)
			return 0;
		if (n == 0)
			return 1.0;
		double half = myPow(x, n / 2);
		if (n % 2 == 0)
			return half*half;
		else if (n > 0)
			return half*half*x;
		else
			return half*half / x;
	}
};
int main(void){
	Solution answer;
	cout << answer.myPow(5, 1) << endl;
	cout << answer.myPow(5, 0) << endl;
	cout << answer.myPow(5, -2) << endl;
	cout << answer.myPow(0, 1) << endl;
	cout << answer.myPow(0, -1) << endl;
	system("Pause");
	return 0;
}

