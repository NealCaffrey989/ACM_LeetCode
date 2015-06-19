// [LeetCode]Climbing Stairs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:3
Output:3
*/
class Solution {
public:
	int climbStairs(int n) {
		if (n <= 0)
			return 0;
		switch(n){
			case 1: return 1;
			case 2: return 2;
		}
		vector<int> stairs(n);
		stairs[0] = 1;
		stairs[1] = 2;
		for (size_t i = 2; i < n; ++i)
			stairs[i] = stairs[i - 2]  + stairs[i - 1];
		return stairs[n - 1];
	}
};
int main(void){
	Solution answer;
	cout << answer.climbStairs(3) << endl;
	system("Pause");
	return 0;
}

