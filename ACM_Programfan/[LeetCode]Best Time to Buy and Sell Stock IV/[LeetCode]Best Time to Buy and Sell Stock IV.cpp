// [LeetCode]Best Time to Buy and Sell Stock IV.cpp : Defines the entry point for the console application.
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
	int maxProfit(int k, vector<int> &prices) {
		if (prices.empty()) return 0;
		if (k >= prices.size()) return solveMaxProfit(prices);
		vector<int> g(k + 1,0);
		vector<int> l(k + 1, 0);
		for (int i = 0; i < prices.size() - 1; ++i) {
			int diff = prices[i + 1] - prices[i];
			for (int j = k; j >= 1; --j) {
				l[j] = max(g[j - 1] + max(diff, 0), l[j] + diff);
				g[j] = max(g[j], l[j]);
			}
		}
		return g[k];
	}
	int solveMaxProfit(vector<int> &prices) {
		int res = 0;
		for (int i = 1; i < prices.size(); ++i) {
			if (prices[i] - prices[i - 1] > 0)
				res += prices[i] - prices[i - 1];
		}
		return res;
	}
};
int main(void){
	Solution answer;
	int a[] = { 1, 2, 1, 5, 7, 4 };
	vector<int> nums;
	for (size_t i = 0; i < 6; ++i)
		nums.push_back(a[i]);
	cout << answer.maxProfit(3,nums) << endl;
	system("Pause");
	return 0;
}