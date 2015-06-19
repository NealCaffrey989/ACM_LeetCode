// [LeetCode]Search a 2D Matrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:
[
[1,   3,  5,  7],
[10, 11, 16, 20],
[23, 30, 34, 50]
]
3
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
	const int n = 3;
	int a[n][n + 1] = {
		{ 1, 3, 5, 7 },
		{ 10, 11, 16, 20 },
		{ 23, 30, 34, 50 }
	};
	vector < vector<int> >ret;
	for (size_t i = 0; i < n; ++i){
		vector<int> r;
		for (size_t j = 0; j < n+1; ++j)
			r.push_back(a[i][j]);
		ret.push_back(r);
	}
	cout << answer.searchMatrix(ret,3) << endl;
	cout << answer.searchMatrix(ret, 4) << endl;
	system("Pause");
	return 0;
}

