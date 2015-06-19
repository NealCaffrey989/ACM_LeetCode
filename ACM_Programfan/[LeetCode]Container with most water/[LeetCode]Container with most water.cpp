// [LeetCode]Container with most water.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/
class Solution {
public:
	int maxArea(vector<int> &height) {
		int capability = 0;
		size_t left = 0, right = height.size() - 1;
		while (left < right){
			const int water = min(height[left], height[right]) * (right - left);
			if (water > capability)
				capability = water;
			if (height[left] < height[right])
				++left;
			else
				--right;
		}
		return capability;
	}
};
int main(void){
	Solution answer;
	vector<int> height;
	height.push_back(1);
	height.push_back(4);
	height.push_back(7);
	cout << answer.maxArea(height) << endl;
	system("Pause");
	return 0;
}

