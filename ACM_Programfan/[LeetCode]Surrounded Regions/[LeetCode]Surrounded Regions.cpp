// [LeetCode]Surrounded Regions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
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
	struct Point{
		int h;
		int v;
		Point(int vp, int hp) : v(vp), h(hp) {};
	};
public:
	void solve(vector<vector<char>> &board) {
		if (board.empty()) 
			return;
		int W = board[0].size(), H = board.size();
		int addV[4] = { 1, 0, -1, 0 };
		int addH[4] = { 0, 1, 0, -1 };
		queue<Point> que;
		int i, j = 0;
		for (i = 0; i < W; ++i){
			if (board[0][i] == 'O') 
				que.push(Point(0, i));
			if (H > 1 && board[H - 1][i] == 'O') 
				que.push(Point(H - 1, i)); 
		}
		for (i = 0; i < H; ++i){
			if (board[i][0] == 'O') 
				que.push(Point(i, 0));
			if (W > 1 && board[i][W - 1] == 'O') 
				que.push(Point(i, W - 1)); 
		}
		while (!que.empty()){ 
			Point cur = que.front();
			que.pop();
			board[cur.v][cur.h] = 'Y';
			for (int i = 0; i < 4; i++){
				if ((cur.v + addV[i]) < H
					&& (cur.h + addH[i]) < W
					&& (cur.v + addV[i]) >= 0
					&& (cur.h + addH[i]) >= 0
					&& board[cur.v + addV[i]][cur.h + addH[i]] == 'O')
					que.push(Point(cur.v + addV[i], cur.h + addH[i]));
			}
		}

		for (i = 0; i < H; ++i){
			for (j = 0; j < W; ++j){
				if (board[i][j] == 'O') 
					board[i][j] = 'X';
				if (board[i][j] == 'Y') 
					board[i][j] = 'O';
			}
		}
	}
};
/*
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
};*/
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
