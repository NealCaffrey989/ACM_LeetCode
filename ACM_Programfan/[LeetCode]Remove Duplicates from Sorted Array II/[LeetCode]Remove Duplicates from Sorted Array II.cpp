// [LeetCode]Remove Duplicates from Sorted Array II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty())
			return 0;
		map<int, int> numsMap;
		int count = 0, flag=0;
		for (size_t i = 0; i < nums.size(); ++i){
			if (++numsMap[nums[i]] <= 2){
				count++;
				nums[flag++] = nums[i];
			}
		}
		nums.erase(nums.begin() + count, nums.end());
		return count;
	}
};
int main(void){
	Solution answer;
	int a[] = {1, 1, 1, 2, 2, 3};
	vector<int> ret;
	for (size_t i = 0; i < 6; ++i)
		ret.push_back(a[i]);
	cout << answer.removeDuplicates(ret) << endl;
	for (size_t i = 0; i < ret.size(); ++i)
		cout << ret[i] << " ";
	cout << endl;
	system("Pause");
	return 0;
}

