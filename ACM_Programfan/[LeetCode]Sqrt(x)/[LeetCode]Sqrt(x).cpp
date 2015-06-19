// [LeetCode]Sqrt(x).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
/*
Input:16
Output:4
*/
class Solution {
public:
	int mySqrt(int x) {
		if (x == 0) return 0;
		double last = 0;
		double res = 1;
		while (res != last){
			last = res;
			res = (res + x / res) / 2;
		}
		return int(res);
	}
};
int main(void){
	Solution answer;
	cout << answer.mySqrt(-1) << endl;
	cout << answer.mySqrt(1) << endl;
	cout << answer.mySqrt(17) << endl;
	system("Pause");
	return 0;
}

