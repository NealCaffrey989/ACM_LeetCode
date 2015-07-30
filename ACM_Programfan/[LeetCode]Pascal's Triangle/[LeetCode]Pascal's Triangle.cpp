// [LeetCode]Pascal's Triangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:5
Output:
[
[1],
[1,1],
[1,2,1],
[1,3,3,1],
[1,4,6,4,1]
]
*/
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ret;
		if (numRows <= 0)
			return ret;
		vector<int> m(1, 1);
		ret.push_back(m);
		while (--numRows){
			vector<int> nums(1,1);
			vector<int> back = ret.back();
			for (size_t i = 0; i < back.size() - 1; ++i)
				nums.push_back(back[i] + back[i + 1]);
			nums.push_back(1);
			ret.push_back(nums);
		}
		return ret;
	}
};
int main(void){
	Solution answer;
	vector<vector<int>> ret = answer.generate(5);
	for (size_t i = 0; i < ret.size(); ++i){
		for (size_t j = 0; j < ret[i].size();++j)
			cout << ret[i][j] << " ";
		cout << endl;
	}
	system("Pause");
	return 0;
}

