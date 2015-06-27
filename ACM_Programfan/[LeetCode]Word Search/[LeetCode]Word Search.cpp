// [LeetCode]Word Search.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Input:
[
["ABCE"],
["SFCS"],
["ADEE"]
]
"ABCCED"
"SEE"
"ABCB"
Output:
true
true
false
*/
class Solution {
public:
	bool findPath(vector<vector<char>> board, string word, int x, int y, int index){
		if (index == word.size() - 1)
			return true;
		char ctmp = board[x][y];
		board[x][y] = '#';
		size_t row = board.size();
		size_t col = board[0].size();
		if (x - 1 >= 0 && board[x - 1][y] == word[index + 1] && findPath(board, word, x - 1, y, index + 1))
			return true;
		if (x + 1 < row && board[x + 1][y] == word[index + 1] && findPath(board, word, x + 1, y, index + 1))
			return true;
		if (y - 1 >= 0 && board[x][y - 1] == word[index + 1] && findPath(board, word, x, y - 1, index + 1))
			return true;
		if (y + 1 < col && board[x][y + 1] == word[index + 1] && findPath(board, word, x, y + 1, index + 1))
			return true;
		board[x][y] = ctmp;
		return false;
	}
	bool exist(vector<vector<char>>& board, string word) {
		if (word.empty())
			return true;
		if (board.empty())
			return false;
		size_t row = board.size();
		size_t col = board[0].size();
		for (size_t i = 0; i < row; ++i){
			for (size_t j = 0; j < col; ++j){
				if (board[i][j] == word[0] && findPath(board, word, i, j, 0))
					return true;
			}
		}
		return false;
	}
};
int main(void){
	Solution answer;
	char str[4][4] = { 'A', 'B', 'C', 'E', 'S', 'F', 'C', 'S', 'A', 'D', 'E', 'E'};
	vector<vector<char>> ret;
	for (size_t i = 0; i < 4; ++i){
		vector<char> r;
		for (size_t j = 0; j < 4; ++j)
			r.push_back(str[i][j]);
		ret.push_back(r);
	}
	cout << answer.exist(ret, "ABCCED") << endl;
	cout << answer.exist(ret, "SEE") << endl;
	cout << answer.exist(ret, "ABCB") << endl;
	system("Pause");
	return 0;
}
