// [LeetCode]Find Peak Element.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:[ 1, 2, 3, 4, 5, 4, 3, 2]
Output:4
*/
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int low = 0;
		int high = nums.size() - 1;
		while (low < high){
			int mid = low + (high - low) / 2;
			if (nums[mid] > nums[mid + 1])
				high = mid;
			else
				low = mid + 1;
		}
		return low;
	}
};
int main(void){
	Solution answer;
	int a[] = { 1, 2, 3, 4, 5, 4, 3, 2 };
	vector<int> nums;
	for (size_t i = 0; i < 8; ++i)
		nums.push_back(a[i]);
	cout << answer.findPeakElement(nums) << endl;
	system("Pause");
	return 0;
}

