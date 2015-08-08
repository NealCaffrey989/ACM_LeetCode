// [LeetCode]Pascal's Triangle II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:3
Output:
[1,3,3,1],
*/
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> ret;
		if (rowIndex < 0)
			return ret;
		ret.resize(rowIndex + 1, 1);
		for (int i = 0; i <= rowIndex; ++i){
			for (int j = i - 1; j >= 1; --j)
				ret[j] = ret[j] + ret[j - 1];
		}
		return ret;
	}
};
int main(void){
	Solution answer;
	for (int z = 0; z < 5; ++z){
		vector<int> ret = answer.getRow(z);
		for (size_t i = 0; i < ret.size(); ++i)
			cout << ret[i] << " ";
		cout << endl;
	}
	system("Pause");
	return 0;
}

