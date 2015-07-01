// [LeetCode]Edit Distance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Input:"eeba", "abca"
Output:3
*/
class Solution {
public:
	int minDistance(string word1, string word2) {
		int row = word1.size();
		int col = word2.size();
		vector<vector<int> > f(row, vector<int>(col));
		for (int i = 0; i < row; i++)
			f[i][0] = i;
		for (int i = 0; i < col; i++)
			f[0][i] = i;
		for (int i = 1; i < row; i++)
		for (int j = 1; j < col; j++){
			if (word1[i - 1] == word2[j - 1])
				f[i][j] = f[i - 1][j - 1];
			else
				f[i][j] = f[i - 1][j - 1] + 1;
			f[i][j] = min(f[i][j], min(f[i - 1][j] + 1, f[i][j - 1] + 1));
		}

		return f[row - 1][col - 1];
	}
};
int main(void){
	Solution answer;
	cout << answer.minDistance("eeba", "abca") << endl;
	system("Pause");
	return 0;
}


