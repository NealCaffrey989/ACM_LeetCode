// [LeetCode]Majority Element.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:[3, 3, 3, 0, 0, 3, 3, 3 ]
Output:3
*/
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int ret = nums[0];
		int count = 1;
		for (int i = 1; i < nums.size(); i++){
			if (nums[i] == ret)
				count++;
			else{
				count--;
				if (count == 0){
					ret = nums[i];
					count = 1;
				}
			}
		}
		return ret;
	}
};
int main(void){
	Solution answer;
	int a[] = { 3, 3, 3, 0, 0, 3, 3, 3 };
	vector<int> ans;
	for (size_t i = 0; i < 8; ++i)
		ans.push_back(a[i]);
	cout << answer.majorityElement(ans) << endl;
	system("Pause");
	return 0;
}

