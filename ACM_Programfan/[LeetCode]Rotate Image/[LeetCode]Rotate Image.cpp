// [LeetCode]Rotate Image.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
Input:
1 2 3
4 5 6
7 8 9
Output:
7 4 1
8 5 2
9 6 3
*/
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		if (matrix.empty())
			return;
		size_t minlen = matrix.size();
		for (size_t i = 0; i < minlen / 2; ++i){
			for (size_t j = i; j < minlen - 1 - i; ++j){
				swap(matrix[i][j], matrix[j][minlen - 1 - i]);
				swap(matrix[i][j], matrix[minlen - 1 - i][minlen - 1 - j]);
				swap(matrix[i][j], matrix[minlen - 1 - j][i]);
			}
		}
	}
};
int main(void){
	Solution answer;
	int a[5][5] = { 
		{ 1, 2, 3, 4, 5 }, 
		{ 6, 7, 8, 9, 10 }, 
		{ 11, 12, 13, 14, 15 },
		{ 16, 17, 18, 19, 20 },
		{ 21, 22, 23, 24, 25 }
	};
	vector<vector<int>> matrix;
	const int n = 5;
	for (int i = 0; i < n; ++i){
		vector<int>v;
		for (int j = 0; j < n; ++j)
			v.push_back(a[i][j]);
		matrix.push_back(v);
	}
	answer.rotate(matrix);
	for (size_t i = 0; i < matrix.size(); ++i){
		for (size_t j = 0; j < matrix[i].size(); ++j)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	system("Pause");
	return 0;
}

