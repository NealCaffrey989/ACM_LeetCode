// [LeetCode]N-Queens.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Input:4
Output:
[
	[	".Q..",  
		"...Q",	
		"Q...",
		"..Q."],
	[	"..Q.",  
		"Q...",
		"...Q",
		".Q.."]
]
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
	bool solveOne(vector<vector<string>> &res, vector<string> &temp, int n, int index){
		if (index == n){
			res.push_back(temp);
			return true;
		}
		for (int j = 0; j<n; j++){
			temp[index][j] = 'Q';
			if (checkij(temp, index, j)){
				solveOne(res, temp, n, index + 1);
			}
			temp[index][j] = '.';
		}
	}
	vector<vector<string>> solveNQueens(int n){
		vector<vector<string>> res;
		vector<string> temp;
		string strtemp(n, '.');
		temp.insert(temp.end(), n, strtemp);
		for (int i = 0; i < n; i++) {
			temp[0][i] = 'Q';
			solveOne(res, temp, n, 1);
			temp[0][i] = '.';
		}
		return res;
	}
};
int main(void){
	Solution answer;
	vector<vector<string>>ret = answer.solveNQueens(4);
	for (auto i = 0; i < ret.size(); ++i){
		for (auto j = 0; j < ret[i].size(); ++j)
			cout << ret[i][j] << endl;
	}
	system("Pause");
	return 0;
}

