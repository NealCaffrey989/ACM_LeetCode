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
		ret.push_back(1);
		while (rowIndex--){
			vector<int> nums(1,1);
			for (size_t i = 0; i < ret.size() - 1; ++i)
				nums.push_back(ret[i] + ret[i + 1]);
			nums.push_back(1);
			ret = nums;
		}
		return ret;
	}
};
int main(void){
	Solution answer;
	vector<int> ret = answer.getRow(3);
	for (size_t i = 0; i < ret.size(); ++i)
		cout << ret[i] << " ";
	cout << endl;
	system("Pause");
	return 0;
}

