// [LeetCode]Sort Colors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:[1,2,1,2,0,0]
Output:[0,0,1,1,2,2]
*/
class Solution {
public:
	void sortColors(vector<int>& nums) {
		if (nums.empty() || nums.size() == 1)
			return;
		int first = -1, last = nums.size(), i = 0;
		while (i<last){
			if (nums[i] == 0 && i != ++first)
				swap(nums[i], nums[first]);
			else if (nums[i] == 2 && i != --last)
				swap(nums[i], nums[last]);
			else
				++i;
		}
	}
};
int main(void){
	Solution answer;
	int a[] = { 1, 2, 1, 2, 0, 0 };
	vector<int> ret;
	for (size_t i = 0; i < 6; ++i)
		ret.push_back(a[i]);
	answer.sortColors(ret);
	for (size_t i = 0; i < ret.size(); ++i)
		cout << ret[i] << " ";
	cout << endl;
	system("Pause");
	return 0;
}

