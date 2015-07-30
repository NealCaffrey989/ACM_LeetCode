// [LeetCode]Largest Rectangle in Histogram.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
/*
Input:[2,1,5,6,2,3]
Output:10
*/
class Solution {
public:
	int largestRectangleArea(vector<int>& height) {
		stack<int> stacks;
		int i = 0;
		int maxArea = 0;
		vector<int> h(height.size() + 1);
		for (size_t i = 0; i < height.size(); ++i)
			h[i] = height[i];
		while (i < h.size()){
			if (stacks.empty() || h[stacks.top()] <= h[i])
				stacks.push(i++);
			else {
				int t = stacks.top();
				stacks.pop();
				maxArea = max(maxArea, h[t] * (stacks.empty() ? i : i - stacks.top() - 1));
			}
		}
		return maxArea;
	}
};
int main(void){
	Solution answer;
	vector<int> nums = { 2, 1, 5, 6, 2, 3 };
	cout << answer.largestRectangleArea(nums) << endl;
	system("Pause");
	return 0;
}

