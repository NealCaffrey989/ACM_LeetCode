// [LeetCode]Spiral Matrix II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:3
Output:
[
	[ 1, 2, 3 ],
	[ 8, 9, 4 ],
	[ 7, 6, 5 ]
]
*/
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector < vector<int> >ret;
		if (n <= 0)
			return ret;
		ret.resize(n);
		for (size_t i = 0; i < n; ++i)
			ret[i].resize(n);
		int up = 0, left = 0, down = n - 1, right = n - 1;
		int num = 1;
		while (up <= down&&left <= right){
			for (int i = up, j = left; j <= right; ++j)
				ret[i][j] = num++;
			for (int i = up + 1, j = right; i <= down;++i)
				ret[i][j] = num++;
			for (int i = down, j = right - 1; j >= left; --j)
				ret[i][j] = num++;
			for (int i = down - 1, j = left; i > up; --i)
				ret[i][j] = num++;
			up++, down--, left++, right--;
		}
		return ret;
	}
};
int main(void){
	Solution answer;
	vector<vector<int>>ret = answer.generateMatrix(3);
	for (size_t i = 0; i < ret.size(); ++i){
		for (size_t j = 0; j < ret[i].size(); ++j)
			cout << ret[i][j] << " ";
		cout << endl;
	}
	system("Pause");
	return 0;
}

