// [LeetCode]Contains Duplicate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;
/*
Input:[1,2,2,3]
Output:false
*/
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		if (nums.empty())
			return false;
		map<int, int> num_map;
		for (size_t i = 0; i < nums.size(); ++i){
			if (num_map[nums[i]] == 0)
				num_map[nums[i]]++;
			else
				return true;
		}
		return false;
	}
};
int main(void){
	Solution answer;
	int a[] = { 1, 2, 3, 4, 5 };
	vector<int> ans;
	for (size_t i = 0; i < 5; ++i)
		ans.push_back(a[i]);
	cout << answer.containsDuplicate(ans) << endl;
	system("Pause");
	return 0;
}