// [LeetCode]Spiral Matrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:
[
[1, 2, 3],
[4, 5, 6],
[7, 8, 9]
]
Output:
[1, 2, 3, 6, 9, 8, 7, 4, 5]
*/
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ret;
		if (matrix.empty())
			return ret;
		int up = 0, down = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
		while (left <= right&&up <= down){
			int i, j;
			for (i = up, j = left; j <= right; j++)
				ret.push_back(matrix[i][j]);
			if (up == down)
				return ret;
			for (i = up + 1, j = right; i <= down; i++)
				ret.push_back(matrix[i][j]);
			if (left == right)
				return ret;
			for (i = down, j = right - 1; j >= left; j--)
				ret.push_back(matrix[i][j]);
			if (up == down)
				return ret;
			for (i = down - 1, j = left; i > up; i--)
				ret.push_back(matrix[i][j]);
			if (left == right)
				return ret;
			left++, right--, up++, down--;
		}
		return ret;
	}
};
int main(void){
	Solution answer;
	int a[7][7] = {
		{ 1, 2, 3, 4, 5, 6, 7 },
		{ 24, 25, 26, 27, 28, 29, 8 },
		{ 23, 40, 41, 42, 43, 30, 9 },
		{ 22, 39, 48, 49, 44, 31, 10 },
		{ 21, 38, 47, 46, 45, 32, 11 },
		{ 20, 37, 36, 35, 34, 33, 12 },
		{ 19, 18, 17, 16, 15, 14, 13 }
	};
	vector<vector<int>>ret;
	for (size_t i = 0; i < 1; ++i){
		vector<int>v;
		for (size_t j = 0; j < 7; ++j)
			v.push_back(a[i][j]);
		ret.push_back(v);
	}
	vector<int> v = answer.spiralOrder(ret);
	for (size_t i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	system("Pause");
	return 0;
}

