// [LeetCode]Unique Binary Search Trees.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:3
Output:5
*/
class Solution {
public:
	int numTrees(int n) {
		vector<int> nums(n + 1);
		nums[0] = 1;
		for (size_t i = 1; i <= n; ++i){
			if (i < 3)
				nums[i] = i;
			else
				for (int j = 1; j <= i; j++)
					nums[i] += nums[j - 1] * nums[i - j];
		}
		return nums[n];
	}
};
int main(void){
	Solution answer;
	cout << answer.numTrees(3) << endl;
	system("Pause");
	return 0;
}