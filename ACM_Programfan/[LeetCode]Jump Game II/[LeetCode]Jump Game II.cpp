// [LeetCode]Jump Game II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Input:
Output:
*//*
class Solution {
public:
	int jump(vector<int>& nums) {
		int n = nums.size();
		if (n==0 || n == 1)
			return n;

	}
};*/

class Solution {
public:
	int jump(vector<int>& nums) {
		int n = nums.size();
		int ret = 0;
		int last = 0;  
		int curr = 0;
		for (int i = 0; i < n; ++i) {
			if (i>curr)
				return -1;
			if (i > last) {
				last = curr;
				++ret;
			}
			curr = max(curr, i + nums[i]);
		}
		return ret;
	}
};


int main(void){
	Solution answer;
	int a[] = { 2, 3, 1, 1, 4 };
//	int a[] = { 1, 2 };
//	int a[] = { 3, 2, 1, 0, 4 };
	vector<int> ret;
	for (size_t i = 0; i < 5; ++i)
		ret.push_back(a[i]);
	cout << answer.jump(ret) << endl;
	system("Pause");
	return 0;
}

