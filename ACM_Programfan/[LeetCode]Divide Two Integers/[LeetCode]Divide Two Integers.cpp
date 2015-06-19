// [LeetCode]Divide Two Integers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <limits.h>
using namespace std;
/*
Input:5,-5
Output:-1
*/
class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == 0 || dividend > INT_MAX || dividend < INT_MIN)
			return INT_MAX;

		long long res = 0;
		int flag = 1;
		if ((dividend<0 && divisor>0) || (dividend>0 && divisor<0))
			flag = -1;

		long long divid = abs((long long)dividend);
		long long divi = abs((long long)divisor);
		long long temp = 0;
		if (divid < divi)
			return 0;
		while (divi <= divid){
			long long cnt = 1;
			temp = divi;

			while ((temp <<= 1) <= divid){
				cnt <<= 1;
			}
			res += cnt;
			divid -= (temp >> 1);

		}
		res = (res*flag);
		if (res >= INT_MAX)
			return INT_MAX;
		else if (res <= INT_MIN)
			return INT_MIN;
		return res;
	}
/*	int divide(int dividend, int divisor) {
		if (divisor == 0)
			return INT_MAX;
		int sign = 1;
		if ((dividend <= 0 && divisor >= 0) || (dividend >= 0 && divisor <= 0))
			sign = -1;
		if (dividend <= 0)
			dividend = 0 - dividend;
		if (divisor <= 0)
			divisor = 0 - divisor;
		int i = 0;
		while (divisor*i <= dividend)
			i++; 
		return (i-1)*sign;
	}*/
};

int main(void){
	Solution answer;
	cout << answer.divide(INT_MIN, -1) << endl;
	cout << answer.divide(INT_MIN, 1) << endl;
//	cout << answer.divide(5, -3) << endl;
//	cout << answer.divide(5, 0) << endl;
//	cout << answer.divide(-5, -5) << endl;
//	cout << answer.divide(-5, 6) << endl;
	system("Pause");
	return 0;
}