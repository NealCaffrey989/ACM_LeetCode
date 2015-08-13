// [LeetCode]Single Number II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:[1, 2, 3, 4, 2, 2, 3, 3, 1, 1]
Output:4
*/
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ones = 0, twos = 0, xthrees = 0;
		for (size_t i = 0; i < nums.size(); ++i) {
			twos |= (ones & nums[i]);
			ones ^= nums[i];
			xthrees = ~(ones & twos);
			ones &= xthrees;
			twos &= xthrees;
		}
		return ones;
	}
};
int main(void){
	Solution answer;
	vector<int> nums{ 1, 2, 3, 4, 2, 2, 3, 3, 1, 1 };
	cout << answer.singleNumber(nums) << endl;
	system("Pause");
	return 0;
}

