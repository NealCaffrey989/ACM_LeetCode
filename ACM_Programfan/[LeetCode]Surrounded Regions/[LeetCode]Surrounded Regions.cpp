// [LeetCode]Surrounded Regions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:
X X X X
X O O X
X X O X
X O X X
Output:
X X X X
X X X X
X X X X
X O X X
*/
class Solution {
public:
	void dfs(vector<vector<char>> &board, int x, int y){
		if (x<0 || x>board.size() - 1 || y<0 || y>board[0].size() - 1)
			return;
		if (board[x][y] == 'O'){
			board[x][y] = 'C';
			dfs(board, x + 1, y);
			dfs(board, x - 1, y);
			dfs(board, x, y + 1);
			dfs(board, x, y - 1);
		}
	}
	void solve(vector<vector<char>> &board){
		if (board.empty())
			return;
		int n = board.size();
		int m = board[0].size();
		if (n <= 2 || m <= 2)
			return;
		for (int i = 0; i < n; ++i){
			dfs(board, i, 0);
			dfs(board, i, m - 1);
		}
		for (int j = 0; j < m; ++j){
			dfs(board, 0, j);
			dfs(board, n - 1, j);
		}
		for (size_t i = 0; i < n; ++i){
			for (size_t j = 0; j < m; ++j){
				if (board[i][j] == 'O')
					board[i][j] = 'X';
				if (board[i][j] == 'C')
					board[i][j] = 'O';
			}
		}
	}
};
int main(void){
	Solution answer;
	vector<vector<char>> board{
		{ 'X', 'X', 'X', 'X' },
		{ 'X', 'O', 'O', 'X' },
		{ 'X', 'X', 'O', 'X' },
		{ 'X', 'O', 'X', 'X' },
	};
	answer.solve(board);
	for (size_t i = 0; i < board.size(); ++i){
		for (size_t j = 0; j < board[i].size(); ++j)
			cout << board[i][j] << " ";
		cout << endl;
	}
	system("Pause");
	return 0;
}
