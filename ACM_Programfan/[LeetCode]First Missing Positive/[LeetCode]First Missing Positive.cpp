// [LeetCode]First Missing Positive.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Input:[1,2,0]
Output:3
*/
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int k = 1;
		for (size_t i = 0; i < nums.size(); ++i){
			if (nums[i] == k)
				k++;
			else if (nums[i]>k)
				return k;
		}
		return k;
	}
};
int main(void){
	Solution answer;
	int a[] = { 1, 1, 0 };
//	int a[] = { 1, -1, 3 };
	vector<int> ret;
	for (size_t i = 0; i < 3; ++i)
		ret.push_back(a[i]);
	cout << answer.firstMissingPositive(ret) << endl;
	system("Pause");
	return 0;
}

