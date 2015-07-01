// [LeetCode]Gray Code.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:2
Output:[0,2,3,1]
*/
class Solution {
public:
	vector<int> grayCode(int n) {
		int size = 1 << n;
		vector<int> grayCodes;
		grayCodes.resize(size);
		for (int i = 0; i < size; i++){
			int gCode = i ^ i >> 1;
			grayCodes[i] = gCode;
		}
		return grayCodes;
	}
};
int main(void){
	Solution answer;
	vector<int> ret = answer.grayCode(3);
	for (size_t i = 0; i < ret.size(); ++i)
		cout << ret[i] << " ";
	cout << endl;
	system("Pause");
	return 0;
}

