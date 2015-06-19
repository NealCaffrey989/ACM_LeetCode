// [LeetCode]Unique Paths II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:
[[ 0, 0, 1, 0 ],
 [ 0, 0, 1, 0 ],
 [ 0, 0, 0, 0 ]]
Output:3
*/
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.empty())
			return 0;
		size_t col = obstacleGrid.size();
		size_t row = obstacleGrid[0].size();
		for (size_t i = 0; i < col; ++i){
			for (size_t j = 0; j < row; ++j){
				if (obstacleGrid[i][j] == 1)
					obstacleGrid[i][j] = 0;
				else if (i == 0 && j == 0)
					obstacleGrid[i][j] = 1;
				else if (i == 0 && j != 0)
					obstacleGrid[i][j] = obstacleGrid[i][j - 1];
				else if (j == 0 && i != 0)
					obstacleGrid[i][j] = obstacleGrid[i - 1][j];
				else
					obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
			}
		}
		return obstacleGrid[col-1][row - 1];
	}
};
int main(void){
	Solution answer;
	int a[3][4] = { 
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 0 }
	};
	vector<vector<int>> ret;
	for (size_t i = 0; i < 3; ++i){
		vector<int> r;		
		for (size_t j = 0; j < 3; ++j)
			r.push_back(a[i][j]);
		ret.push_back(r);
	}
	cout << answer.uniquePathsWithObstacles(ret) << endl;
	system("Pause");
	return 0;
}

