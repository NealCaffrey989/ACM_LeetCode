// [LeetCode]Best Time to Buy and Sell Stock III.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Input:[1, 2, 1, 5, 7, 4]
Output:7
*/
class Solution {
public:
	int maxProfit(vector<int> &prices) {
		int size = prices.size();
		if (size <= 1) 
			return 0;
		vector<int> leftRes(size, 0);
		int lastMin = prices[0];
		for (int i = 1; i<size; i++) {
			if (prices[i]<lastMin) 
				lastMin = prices[i];
			leftRes[i] = max(prices[i] - lastMin, leftRes[i - 1]);
		}
		vector<int> rightRes(size, 0);
		int res = leftRes[size - 1];
		int lastMax = prices[size - 1];
		for (int i = size - 2; i >= 0; i--) {
			if (prices[i]>lastMax) 
				lastMax = prices[i];
			rightRes[i] = max(lastMax - prices[i], rightRes[i + 1]);
			res = max(res, rightRes[i] + leftRes[i]);
		}
		return res;
	}
};
/*
public int maxProfit(int[] prices) {
	if (prices == null || prices.length == 0)
		return 0;
	int[] local = new int[3];
	int[] global = new int[3];
	for (int i = 0; i<prices.length - 1; i++)
	{
		int diff = prices[i + 1] - prices[i];
		for (int j = 2; j >= 1; j--)
		{
			local[j] = Math.max(global[j - 1] + (diff>0 ? diff : 0), local[j] + diff);
			global[j] = Math.max(local[j], global[j]);
		}
	}
	return global[2];
}*/
int main(void){
	Solution answer;
	int a[] = { 1, 2, 1, 5, 7, 4 };
	vector<int> nums;
	for (size_t i = 0; i < 6; ++i)
		nums.push_back(a[i]);
	cout << answer.maxProfit(nums) << endl;
	system("Pause");
	return 0;
}
