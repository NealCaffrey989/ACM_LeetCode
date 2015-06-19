// [LeetCode]Unique Paths.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input: 3 7 
Output:28
*/
class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int> > ans(m, vector<int>(n));
		for (int i = 0; i < m; ++i)
			ans[i][0] = 1;
		for (int j = 0; j < n; ++j)
			ans[0][j] = 1;
		for (int i = 1; i < m; ++i){
			for (int j = 1; j < n; ++j)
				ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
		}
		return ans[m - 1][n - 1];
	}
};
int main(void){
	Solution answer;
	cout << answer.uniquePaths(3, 7) << endl;
	system("Pause");
	return 0;
}

