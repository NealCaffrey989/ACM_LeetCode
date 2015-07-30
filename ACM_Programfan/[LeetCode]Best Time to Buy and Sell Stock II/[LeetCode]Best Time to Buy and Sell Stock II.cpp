// [LeetCode]Best Time to Buy and Sell Stock II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:[1, 2, 1, 5, 6, 4]
Output:6
*/
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty() || prices.size() == 1)
			return 0;
		int sum = 0;
		for (size_t i = 1; i < prices.size(); ++i){
			if (prices[i] - prices[i - 1]>0)
				sum += prices[i] - prices[i - 1];
		}
		return sum;
	}
};
int main(void){
	Solution answer;
	int a[] = { 1, 2, 1, 5, 6, 4 };
	vector<int> nums;
	for (size_t i = 0; i < 6; ++i)
		nums.push_back(a[i]);
	cout << answer.maxProfit(nums) << endl;
	system("Pause");
	return 0;
}

