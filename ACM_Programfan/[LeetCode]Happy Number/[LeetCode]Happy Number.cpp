// [LeetCode]Happy Number.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
/*
Input:19
Output:true
*/
class Solution {
public:
	bool isHappy(int n) {
		while (n >= 10){
			int sum = 0;

		}
		if (n == 1)
			return true;
		else
			return false;
	}
};
int main(void){
	Solution answer;
	cout << answer.isHappy(19) << endl;
	system("Pause");
	return 0;
}