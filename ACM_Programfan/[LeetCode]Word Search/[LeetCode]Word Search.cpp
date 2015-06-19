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
	bool isValid(vector<vector<char>> board){

	}
	bool findPath(){}
	bool exist(vector<vector<char>>& board, string word) {
		if (word.empty())
			return true;
		if (board.empty())
			return false;
		size_t row = board.size();
		size_t col = board[0].size();
		vector<vector<bool>> sign;
		for (size_t i = 0; i < row; ++i){
			vector<bool> s(col, true);
			sign.push_back(s);
		}
		for (size_t i = 0; i < row; ++i){
			for (size_t j = 0; j < col; ++j){
				if (board[i][j] == word[0]&&findPath(board,word,))
					return true;
			}
		}
		return false;
	}
};
int main(void){
	Solution answer;
	string str[] = { "ABCE","SFCS","ADEE" };
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
