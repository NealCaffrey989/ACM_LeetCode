// [LeetCode]Valid Sudoku.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:
{ '5', '3', '.',  '.',  '7', '.',  '.',  '.',  '.'  },
{ '6', '.',  '.',  '1', '9', '5', '.',  '.',  '.'  },
{ '.',  '9', '8', '.',  '.',  '.',  '.',  '6', '.'  },
{ '8', '.',  '.',  '.',  '6', '.',  '.',  '.',  '3' },
{ '4', '.',  '.',  '8', '.',  '3', '.',  '.',  '1' },
{ '7', '.',  '.',  '.',  '2', '.',  '.',  '.',  '6' },
{ '.',  '6', '.',  '.',  '.',  '.',  '2', '8', '.'  },
{ '.',  '.',  '.',  '4', '1', '9', '.',  '.',  '5' },
{ '.',  '.',  '.',  '.',  '8', '.',  '.',  '7', '9' },
Output:
1
*/
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		if (board.size() != 9)
			return false;
		bool row[9][9], col[9][9], subSudo[9][9];
		memset(row, false, sizeof row);
		memset(col, false, sizeof col);
		memset(subSudo, false, sizeof subSudo);
		for (size_t i = 0; i < 9; ++i){
			if (board[i].size() != 9)
				return false;
			for (size_t j = 0; j < 9; ++j){
				if (board[i][j] == '.')
					continue;
				int c = board[i][j] - '1';
				if (row[i][c] || col[j][c] || subSudo[3 * (i / 3) + j / 3][c])
					return false;
				row[i][c] = col[j][c] = subSudo[3 * (i / 3) + j / 3][c] = true;
			}
		}
		return true;
	}
};

int main(void){
	Solution answer;
	vector< vector<char> > v;
	for (size_t i = 0; i < 9; ++i){
		vector<char> it(9,'.');
		v.push_back(it);
	}
	cout << answer.isValidSudoku(v) << endl;
	system("Pause");
	return 0;
}

