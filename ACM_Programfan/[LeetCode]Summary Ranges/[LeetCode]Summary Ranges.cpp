// [LeetCode]Summary Ranges.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Input:[0,1,2,4,5,7]
Output:
*/
class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> summary;
		if (nums.empty())
			return summary;
		const string sign = "->";
		string str;
		int first;
		for (size_t i = 0; i < nums.size(); ++i){
			if (i == 0 || str.empty()){
				str += to_string(nums[i]);
				first = 0;
				continue;
			}
			if (nums[i] != nums[i - 1] + 1){
				if (nums[i - 1] != nums[first])
					str += sign + to_string(nums[i - 1]);
				summary.push_back(str);
				str = "" + to_string(nums[i]);
				first = i;
			}
		}
		if (!str.empty()){
			if (nums[nums.size() - 1] != nums[first])
				str += sign + to_string(nums[nums.size() - 1]);
			summary.push_back(str);
		}
		return summary;
	}
};
int main(void){
	Solution answer;
	vector<int> nums{ 0, 1, 2, 4, 5, 7, 8 };
	vector<string> str = answer.summaryRanges(nums);
	for (size_t i = 0; i < str.size(); ++i)
		cout << str[i] << " ";
	cout << endl;
	system("Pause");
	return 0;
}