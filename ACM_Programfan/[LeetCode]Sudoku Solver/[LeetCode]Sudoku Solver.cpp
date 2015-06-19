// [LeetCode]Sudoku Solver.cpp : Defines the entry point for the console application.
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
{ '5', '3', '4', '6', '7', '8', '9', '1', '2' },
{ '6', '7', '2', '1', '9', '5', '3', '4', '8' },
{ '1', '9', '8', '3', '4', '2', '5', '6', '7' },
{ '8', '5', '9', '7', '6', '1', '4', '2', '3' },
{ '4', '2', '6', '8', '5', '3', '7', '9', '1' },
{ '7', '1', '3', '9', '2', '4', '8', '5', '6' },
{ '9', '6', '1', '5', '3', '7', '2', '8', '4' },
{ '2', '8', '7', '4', '1', '9', '6', '3', '5' },
{ '3', '4', '5', '2', '8', '6', '1', '7', '9' },
*/
class Solution {
public:
	bool isValid(vector<vector<char>>& board, size_t i, size_t j){
		for (size_t x = 0; x < 9; ++x){
			if (board[x][j] == board[i][j] && x != i)
				return false;
		}
		for (size_t y = 0; y < 9; ++y){
			if (board[i][y] == board[i][j] && y != j)
				return false;
		}
		for (size_t x = 3 * (i / 3); x < 3 * (i / 3) + 3; ++x){
			for (size_t y = 3 * (j / 3); y < 3 * (j / 3) + 3; ++y){
				if (board[x][y] == board[i][j] && x != i && y != j)
					return false;
			}
		}
		return true;
	}
	bool makeSolveSudoku(vector<vector<char>>& board) {
		for (size_t i = 0; i < 9; ++i){
			for (size_t j = 0; j < 9; ++j){
				if (board[i][j] == '.'){
					for (int k = 1; k <= 9; ++k){
						board[i][j] = k + '0';
						if (isValid(board, i, j) && makeSolveSudoku(board))
							return true;
						board[i][j] = '.';
					}
					return false;
				}
			}
		}
		return true;
	}
	void solveSudoku(vector<vector<char>>& board) {
		makeSolveSudoku(board);
	}
};

int main(void){
	Solution answer;
	char a[9][9] = { 
		{ '5', '3', '.',  '.',  '7', '.',  '.',  '.',  '.'  },
		{ '6', '.',  '.',  '1', '9', '5', '.',  '.',  '.'  },
		{ '.',  '9', '8', '.',  '.',  '.',  '.',  '6', '.'  },
		{ '8', '.',  '.',  '.',  '6', '.',  '.',  '.',  '3' },
		{ '4', '.',  '.',  '8', '.',  '3', '.',  '.',  '1' },
		{ '7', '.',  '.',  '.',  '2', '.',  '.',  '.',  '6' },
		{ '.',  '6', '.',  '.',  '.',  '.',  '2', '8', '.'  },
		{ '.',  '.',  '.',  '4', '1', '9', '.',  '.',  '5' },
		{ '.',  '.',  '.',  '.',  '8', '.',  '.',  '7', '9' },
	};
	vector< vector<char> > v;
	for (size_t i = 0; i < 9; ++i){
		vector<char> it;
		for (size_t j = 0; j < 9; ++j)
			it.push_back(a[i][j]);
		v.push_back(it);
	}
	answer.solveSudoku(v);
	for (size_t i = 0; i < 9; ++i){
		for (size_t j = 0; j < 9; ++j)
			cout << v[i][j] << " ";
		cout << endl;
	}

	system("Pause");
	return 0;
}

