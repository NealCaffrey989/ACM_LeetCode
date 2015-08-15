// [LeetCode]Number of 1 Bits.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdint.h>
using namespace std;
/*
Input:
Output:
*/
class Solution {
public:
	int hammingWeight(uint32_t n) {
		int sum = 0;
		while (n){
			if (n & -n)
				sum++;
			n = n & (n - 1);
		}
		return sum;
	}
};
int main(void){
	Solution answer;
	uint32_t n = 11;
	cout << answer.hammingWeight(n) << endl;
	system("Pause");
	return 0;
}