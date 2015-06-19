// [LeetCode]Minimum Path Sum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
Input:
[[ 1, 2, 3, 4 ],
[ 4, 3, 2, 1 ],
[ 4, 3, 2, 1 ]]
Output:10
*/
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.empty())
			return 0;
		size_t col = grid.size();
		size_t row = grid[0].size();
		for (size_t i = 0; i < col; ++i){
			for (size_t j = 0; j < row; ++j){
				if (i == 0 && j != 0)
					grid[i][j] = grid[i][j - 1] + grid[i][j];
				else if (i != 0 && j == 0)
					grid[i][j] = grid[i - 1][j] + grid[i][j];
				else if (i != 0 && j != 0)
					grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
			}
		}
		return grid[col - 1][row - 1];
	}
};
int main(void){
	Solution answer;
	int a[3][4] = {
		{ 1, 2, 3, 4 },
		{ 4, 3, 2, 1 },
		{ 4, 3, 2, 1 }
	};
	vector<vector<int>> ret;
	for (size_t i = 0; i < 3; ++i){
		vector<int> r;
		for (size_t j = 0; j < 3; ++j)
			r.push_back(a[i][j]);
		ret.push_back(r);
	}
	cout << answer.minPathSum(ret) << endl;
	system("Pause");
	return 0;
}

