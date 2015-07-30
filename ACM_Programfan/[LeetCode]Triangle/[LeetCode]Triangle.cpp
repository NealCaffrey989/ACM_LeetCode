// [LeetCode]Triangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Input:
[
[2],
[3,4],
[6,5,7],
[4,1,8,3]
]
Output:11
*/
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		if (triangle.empty())
			return 0;
		if (triangle.size() == 1)
			return triangle.back().back();
		size_t n = triangle.size();
		vector<int> nums(n);
		nums[0] = triangle[0][0];
		int minimum = nums[0];
		for (int i = 1; i < n ; ++i){
			for (int j = i; j >= 0; --j){
				if (j == i){
					nums[j] = nums[j - 1] + triangle[i][j];
					minimum = nums[j];
				}
				else if (j == 0)
					nums[j] = triangle[i][j] + nums[j];
				else
					nums[j] = min(nums[j - 1], nums[j]) + triangle[i][j];
				if (nums[j] < minimum)
					minimum = nums[j];
			}
		}
		return minimum;
	}
};
int main(void){
	Solution answer;
	int a[4][4] = {
		{ -1, 0, 0, 0 },
		{ -3, -2, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	};
	vector<vector<int>> ret;
	for (size_t i = 0; i < 4; ++i){
		vector<int> num;
		for (size_t j = 0; j <= i; ++j)
			num.push_back(a[i][j]);
		ret.push_back(num);
	}
	cout << answer.minimumTotal(ret) << endl;
	system("Pause");
	return 0;
}

