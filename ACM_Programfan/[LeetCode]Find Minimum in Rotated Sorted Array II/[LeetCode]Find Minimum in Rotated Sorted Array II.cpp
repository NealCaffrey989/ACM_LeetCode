// [LeetCode]Find Minimum in Rotated Sorted Array II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:[4 5 6 7 0 1 2]
Output:0
*/
class Solution {
public:
	int findMin(vector<int>& nums) {
		if (nums.empty())
			return 0;
		if (nums.size() == 1)
			return nums[0];
		int n = nums.size();
		int low = 0, high = n - 1;
		while (low < high && nums[low] >= nums[high]){
			int mid = low + (high - low) / 2;
			if (nums[mid] < nums[low]) 
				high = mid;
			else if (nums[mid] == nums[low])
				low++;
			else
				low = mid + 1;
		}
		return nums[low];
	}
};
int main(void){
	Solution answer;
	int a[] = { 3, 3, 3, 0, 3, 3, 3, 3 };
	vector<int> ans;
	for (size_t i = 0; i < 8; ++i)
		ans.push_back(a[i]);
	cout << answer.findMin(ans) << endl;
	system("Pause");
	return 0;
}

