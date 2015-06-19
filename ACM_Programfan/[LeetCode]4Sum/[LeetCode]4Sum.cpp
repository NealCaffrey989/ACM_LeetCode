// [LeetCode]4Sum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Input:{1 0 -1 0 -2 2},  0
Output:(-1,  0, 0, 1) (-2, -1, 1, 2) (-2,  0, 0, 2)
*/
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector< vector<int> > ret;
		if (nums.size() < 4)
			return ret;
		sort(nums.begin(), nums.end());
		for (size_t i = 0; i < nums.size() - 3; ++i){
			if (i != 0 && nums[i] == nums[i - 1])
				continue;
			for (size_t j = i + 1; j < nums.size() - 2; ++j){
				if (j != i + 1 && nums[j] == nums[j - 1])
					continue;
				size_t l = j + 1, k = nums.size() - 1;
				while (l < k){
					if (l != j + 1 && nums[l] == nums[l - 1]){
						l++;
						continue;
					}
					if (k != nums.size() - 1 && nums[k] == nums[k + 1]){
						k--;
						continue;
					}
					int sum = nums[i] + nums[j] + nums[l] + nums[k];
					if (sum == target){
						vector<int> v;
						v.push_back(nums[i]);
						v.push_back(nums[j]);
						v.push_back(nums[l]);
						v.push_back(nums[k]);
						ret.push_back(v);
						l++;
						k--;
					}
					else if (sum < target)
						l++;
					else
						k--;
				}
			}
		}
		return ret;
	}
};

int main(void){
	Solution answer;
//	int a[]= { 1, 0, -1, 0, -2, 2 };
	int a[] = { 0, 0, 0, 0 };
	vector<int> v;
	for (size_t i = 0; i < 4; ++i)
		v.push_back(a[i]);
	vector<vector<int>> ret = answer.fourSum(v, 0);
	for (size_t i = 0; i < ret.size(); ++i)
		cout << ret[i][0] << " " << ret[i][1] << " " << ret[i][2] << " " << ret[i][3] << endl;
	system("Pause");
	return 0;
}