// [LeetCode]Contains Duplicate II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;
/*
Input:[1,2,2,3], 2
Output:true
*/
class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		if (nums.empty())
			return false;
		map<int, int> num_map;
		for (size_t i = 0; i < nums.size(); ++i){
			if (num_map.count(nums[i]) && i - num_map[nums[i]] <= k)
				return true;
			num_map[nums[i]] = i;
		}
		return false;
	}
};
int main(void){
	Solution answer;
	int a[] = { 1, 2, 1, 4, 3 };
	vector<int> ans;
	for (size_t i = 0; i < 5; ++i)
		ans.push_back(a[i]);
	cout << answer.containsNearbyDuplicate(ans,2) << endl;
	system("Pause");
	return 0;
}

