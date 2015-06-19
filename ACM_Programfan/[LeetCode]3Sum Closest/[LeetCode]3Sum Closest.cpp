// [LeetCode]3Sum Closest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Input:{-1 2 1 -4}, 1
Output: 2. (-1 + 2 + 1 = 2)
*/
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int besttarget = 0, diff = INT_MAX;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; i++){
			int j = i + 1, n = nums.size() - 1;
			if (i>0 && nums[i] == nums[i - 1])
				continue;
			while (j < n){
				if (j>i + 1 && nums[j] == nums[j - 1]){
					j++;
					continue;
				}
				if (n<nums.size() - 1 && nums[n] == nums[n + 1]){
					n--;
					continue;
				}
				int sum = nums[i] + nums[j] + nums[n];
				if (abs(sum - target) < diff){
					diff = abs(sum - target);
					besttarget = sum;
				}
				if (sum == target)
					return besttarget;
				else if (sum>target)
					n--;
				else
					j++;
			}
		}
		return besttarget;
	}
};

int main(void){
	Solution answer;
	int a[] = { 1, 1, 1, 1 };
	vector<int> nums;
	for (int i = 0; i < 4; i++)
		nums.push_back(a[i]);
	cout << answer.threeSumClosest(nums, 1);
	
	system("Pause");
	return 0;
}


