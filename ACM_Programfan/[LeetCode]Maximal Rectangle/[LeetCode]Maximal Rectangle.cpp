// [LeetCode]Maximal Rectangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
/*
Input:
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Output:6
*/
class Solution {
public:
	int maxAreaInHist(vector<int> height){
		stack<int> stacks;
		int i = 0;
		int maxArea = 0;
		while (i < height.size()){
			if (stacks.empty() || height[stacks.top()] <= height[i])
				stacks.push(i++);
			else {
				int t = stacks.top();
				stacks.pop();
				maxArea = max(maxArea, height[t] * (stacks.empty() ? i : i - stacks.top() - 1));
			}
		}
		return maxArea;
	}
	int maximalRectangle(vector<vector<char>> matrix) {
		int m = matrix.size();
		int n = m == 0 ? 0 : matrix[0].size();
		vector<vector<int>> height(m, vector<int>(n + 1));
		int maxArea = 0;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == '0')
					height[i][j] = 0;
				else
					height[i][j] = i == 0 ? 1 : height[i - 1][j] + 1;
			}
		}
		for (int i = 0; i < m; i++){
			int area = maxAreaInHist(height[i]);
			if (area > maxArea)
				maxArea = area;
		}
		return maxArea;
	}
};
int main(void){
	Solution answer;
	vector<vector<char>> ret = {
		{ '1', '0', '1', '0', '0' },
		{ '1', '0', '1', '1', '1' },
		{ '1', '1', '1', '1', '1' },
		{ '1', '0', '0', '1', '0' }
	};
	cout << answer.maximalRectangle(ret) << endl;
	system("Pause");
	return 1;
}
