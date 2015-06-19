// [LeetCode]3Sum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Input:{-1 0 1 2 -1 -4}
Output:(-1, 0, 1)    (-1, -1, 2)
*/
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector< vector<int> > ret;
		if (nums.size() <= 2)
			return ret;
		sort(nums.begin(),nums.end());
		for (int i = 0; i < nums.size() - 2; ++i){
			if (i >0 && nums[i] == nums[i - 1])
				continue;
			int n = nums.size() - 1, j = i + 1;
			while (j < n){
				if (j > i + 1 && nums[j] == nums[j - 1]){
					j++;
					continue;
				}
				if (n > nums.size() - 1 && nums[n] == nums[n + 1]){
					n--;
					continue;
				}
				if ((nums[i] + nums[j] + nums[n]) == 0){
					vector<int> v;
					v.push_back(nums[i]);
					v.push_back(nums[j]);
					v.push_back(nums[n]);
					ret.push_back(v);
					j++;
					n--;
				}
				else if ((nums[i] + nums[j] + nums[n]) > 0)
					n--;
				else
					j++;
			}
		}
		return ret;
	}
};

int main(void){
	Solution answer;
	int a[] = { -1, 0, 1, 2, -1, -1 };
	vector<int> nums;
	for (int i = 0; i < 6; i++)
		nums.push_back(a[i]);
	vector< vector<int> > ans = answer.threeSum(nums);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
	system("Pause");
	return 0;
}

