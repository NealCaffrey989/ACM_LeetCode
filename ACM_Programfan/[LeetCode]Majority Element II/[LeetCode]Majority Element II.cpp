// [LeetCode]Majority Element II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:[3, 3, 1, 0, 0, 0, 0, 3, 3 ]
Output:[0, 3]
*/
class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		int k = 3;
		vector<int> val(k), cnt(k, 0);
		for (int i = 0; i < nums.size(); ++i) {
			bool flag = true;
			for (int j = 0; j < k; ++j)  {
				if (val[j] == nums[i] && cnt[j] > 0) {
					val[j] = nums[i];
					++cnt[j];
					flag = false;
					break;
				}
			}
			if (flag) {
				for (int j = 0; j < k; ++j) {
					if (cnt[j] == 0) {
						val[j] = nums[i];
						++cnt[j];
						break;
					}
				}
			}
			if (cnt[k - 1] == 1) {
				for (int kk = 0; kk < k; ++kk) {
					--cnt[kk];
				}
			}
		}
		vector<int> res;
		for (int i = 0; i < k; ++i) if (cnt[i] > 0) {
			int c = 0;
			for (auto n : nums) if (val[i] == n) ++c;
			if (c > nums.size() / k) res.push_back(val[i]);
		}
		return res;
	}
};
int main(void){
	Solution answer;
	int a[] = { 6,6,6,7,7 };
	vector<int> ans;
	for (size_t i = 0; i < 5; ++i)
		ans.push_back(a[i]);
	vector<int> ret = answer.majorityElement(ans);
	for (size_t i = 0; i < ret.size(); ++i)
		cout << ret[i] << " ";
	cout << endl;
	system("Pause");
	return 0;
}

