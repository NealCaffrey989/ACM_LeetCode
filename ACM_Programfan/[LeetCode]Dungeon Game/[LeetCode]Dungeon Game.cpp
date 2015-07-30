// [LeetCode]Dungeon Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Input:
[	[-2 -3 3]
	[-5 -10 1]
	[10 30 -5]
]
Output:7
*/
class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		if (dungeon.empty() || dungeon[0].empty())
			return 1;
		size_t row = dungeon.size();
		size_t col = dungeon[0].size();
		for (int i = row - 1; i >= 0; --i){
			for (int j = col - 1; j >= 0; --j){
				if (i == row - 1 && j == col - 1)
					dungeon[i][j] = max(0 - dungeon[i][j], 0);
				else if (i == row - 1)
					dungeon[i][j] = max(dungeon[i][j + 1] - dungeon[i][j], 0);
				else if (j == col - 1)
					dungeon[i][j] = max(dungeon[i + 1][j] - dungeon[i][j], 0);
				else
					dungeon[i][j] = max(min(dungeon[i + 1][j], dungeon[i][j + 1]) - dungeon[i][j], 0);
			}
		}
		return dungeon[0][0] + 1;
	}
};
int main(void){
	Solution answer;
	vector<vector<int>> blood = {
		{ -2, -3, 3 },
		{ -5, -10, 1 },
		{ 7, -3, -5 },
	};
	cout << answer.calculateMinimumHP(blood) << endl;
	system("Pause");
	return 0;
}


