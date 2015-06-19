// [LeetCode]Maximum Subarray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
Input:[−2,1,−3,4,−1,2,1,−5,4]
Output:[4,−1,2,1]   6
*/
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int sum = 0, first = 0, len = 0, maxf = 0, maxlen = 1, max = nums[0];
		for (size_t i = 0; i < nums.size(); ++i){
			sum += nums[i];
			len++;
			if (sum < nums[i]){
				sum = nums[i];
				first = i;
				len = 1;
			}
			if (sum >= max){
				max = sum;
				maxf = first;
				maxlen = len;
			}
		}
		if (maxlen != nums.size()){
			for (size_t i = maxf, j = 0; i < maxf + maxlen; ++i)
				nums[j++] = nums[i];
			nums.erase(nums.begin() + maxlen, nums.end());
		}
		return max;
	}
};
int main(void){
	Solution answer;
	int a[] = { -2, -1, -3, 4, -1, 2, 1, -5, 4 };
	vector<int> ret;
	for (size_t i = 0; i < 2; ++i)
		ret.push_back(a[i]);
	cout << answer.maxSubArray(ret) << endl;
	for (size_t i = 0; i < ret.size(); ++i)
		cout << ret[i] << " ";
	cout << endl;
	system("Pause");
	return 0;
}

