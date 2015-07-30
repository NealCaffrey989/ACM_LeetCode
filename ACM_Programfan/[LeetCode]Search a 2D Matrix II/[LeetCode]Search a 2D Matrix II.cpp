// [LeetCode]Search a 2D Matrix II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// [LeetCode]Search a 2D Matrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:
[
	[1,   4,  7, 11, 15],
	[2,   5,  8, 12, 19],
	[3,   6,  9, 16, 22],
	[10, 13, 14, 17, 24],
	[18, 21, 23, 26, 30]
]
5
Output:
true
*/
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty())
			return false;
		size_t row = matrix.size() - 1;
		size_t col = matrix[0].size() - 1;
		int i = 0, j = col;
		while (i <= row && j >= 0){
			if (matrix[i][j] == target)
				return true;
			else if (matrix[i][j] > target)
				j--;
			else
				i++;
		}
		return false;
	}
};
int main(void){
	Solution answer;
	vector < vector<int> >ret = {
		{ 1, 4, 7, 11, 15 },
		{ 2, 5, 8, 12, 19 },
		{ 3, 6, 9, 16, 22 },
		{ 10, 13, 14, 17, 24 },
		{ 18, 21, 23, 26, 30 }
	};
	cout << answer.searchMatrix(ret, 5) << endl;
	cout << answer.searchMatrix(ret, 20) << endl;
	system("Pause");
	return 0;
}

