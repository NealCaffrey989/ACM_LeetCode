// [LeetCode]Best Time to Buy and Sell Stock.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Input:
Output:
*/
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty() || prices.size() == 1)
			return 0;
		int n = prices.size();
		vector<int> cost(n);
		cost[0] = 0;
		int lowprices = prices[0];
		for (size_t i = 1; i < n; ++i){
			if (prices[i] < lowprices)
				lowprices = prices[i];
			cost[i] = max(cost[i - 1], prices[i] - lowprices);
		}
		return cost.back();
	}
};
int main(void){
	Solution answer;
	int a[] = { 3, 2, 1, 1, 1, 1 };
	vector<int> nums;
	for (size_t i = 0; i < 6; ++i)
		nums.push_back(a[i]);
	cout << answer.maxProfit(nums) << endl;
	system("Pause");
	return 0;
}

