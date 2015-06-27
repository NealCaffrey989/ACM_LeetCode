// [LeetCode]N-Queens II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Input:4
Output:2
*/
class Solution {
public:
	bool checkij(vector<string> &temp, int i, int j){
		for (int ii = i - 1, jleft = j - 1; ii >= 0 && jleft >= 0; ii--, jleft--){
			if (temp[ii][jleft] == 'Q')
				return false;
		}
		for (int ii = i - 1, jright = j + 1; ii >= 0 && jright<temp.size(); ii--, jright++){
			if (temp[ii][jright] == 'Q')
				return false;
		}
		for (int k = 0; k<temp.size(); k++){
			if (k != j&&temp[i][k] == 'Q')
				return false;
			if (k != i&&temp[k][j] == 'Q')
				return false;
		}
		return true;
	}
	bool solveOne(int &res, vector<string> &temp, int n, int index){
		if (index == n){
			res++;
			return true;
		}
		for (int j = 0; j<n; j++){
			temp[index][j] = 'Q';
			if (checkij(temp, index, j))
				solveOne(res, temp, n, index + 1);
			temp[index][j] = '.';
		}
	}
	int totalNQueens(int n) {
		int res = 0;
		vector<string> temp;
		string strtemp(n, '.');
		temp.insert(temp.end(), n, strtemp);
		for (int i = 0; i<n; i++){
			temp[0][i] = 'Q';
			solveOne(res, temp, n, 1);
			temp[0][i] = '.';
		}
		return res;
	}
};
int main(void){
	Solution answer;
	cout << answer.totalNQueens(4) << endl;
	system("Pause");
	return 0;
}

