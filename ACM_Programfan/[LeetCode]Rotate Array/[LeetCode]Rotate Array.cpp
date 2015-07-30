// [LeetCode]Rotate Array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Input:[1,2,3,4,5,6,7], 3
Output:[5,6,7,1,2,3,4]
*/
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int n = nums.size();
		k = k%n;
		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin() + k);
		reverse(nums.begin() +k, nums.end());
	}
};
int main(void){
	Solution answer;
	int a[] = { 1, 2, 3, 4, 5, 6, 7 };
	vector<int> ret;
	for (size_t i = 0; i < 7; ++i)
		ret.push_back(a[i]);
	answer.rotate(ret, 10);
	for (size_t i = 0; i < ret.size(); ++i)
		cout << ret[i] << " ";
	cout << endl;
	system("Pause");
	return 0;
}


