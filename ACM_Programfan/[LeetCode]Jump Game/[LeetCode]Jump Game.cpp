// [LeetCode]Jump Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:[2,3,1,1,4]
Output:true
*/
class Solution {
public:
	bool canJump(vector<int>& nums) {
		size_t n = nums.size();
		if (n == 0 || n == 1)
			return true;
		int maxstep = nums[0];
		for (int i = 1; i < n; i++){
			if (maxstep == 0)
				return false;
			maxstep--;
			if (maxstep < nums[i]){
				maxstep = nums[i];
			}
			if (maxstep + i >= n - 1)
				return true;
		}
		return false;
	}
};
int main(void){
	Solution answer;
	int a[] = {2, 3, 1, 1, 4 };
//	int a[] = {3, 2, 1, 0, 4 };
	vector<int> ret;
	for (size_t i = 0; i < 5; ++i)
		ret.push_back(a[i]);
	cout << answer.canJump(ret) << endl;
	system("Pause");
	return 0;
}

