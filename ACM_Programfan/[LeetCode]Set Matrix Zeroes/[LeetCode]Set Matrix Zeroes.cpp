// [LeetCode]Set Matrix Zeroes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*]
Input:
[[0,1,2],
 [1,2,3],
 [2,3,4]]
Output:
[[0,0,0],
 [0,2,3],
 [0,3,4]]
*/
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		if (matrix.empty())
			return;
		size_t row = matrix.size();
		size_t col = matrix[0].size();
		vector<bool> row0(row, false), col0(col, false);
		for (size_t i = 0; i < row; ++i){
			for (size_t j = 0; j < col; ++j){
				if (matrix[i][j] == 0){
					row0[i] = true;
					col0[j] = true;
				}
			}
		}
		for (size_t i = 0; i < row; ++i){
			for (size_t j = 0; j < col; ++j){
				if (row0[i] == true || col0[j] == true){
					matrix[i][j] = 0;
				}
			}
		}
		return;
	}
};
int main(void){
	Solution answer;
	const int n = 3;
	int a[n][n] = {
		{0,1,2},
		{1,2,3},
		{2,3,4}
	};
	vector<vector<int>>ret;
	for (size_t i = 0; i < n; ++i){
		vector<int> r;
		for (size_t j = 0; j < n; ++j)
			r.push_back(a[i][j]);
		ret.push_back(r);
	}
	answer.setZeroes(ret);
	for (size_t i = 0; i < ret.size(); ++i){
		for (size_t j = 0; j < ret[i].size(); ++j)
			cout << ret[i][j] << " ";
		cout << endl;
	}
	system("Pause");
	return 0;
}

