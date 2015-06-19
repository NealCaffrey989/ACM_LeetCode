// [LeetCode]Remove Element.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Input:[1, 1, 2, 3, 4, 5, 6, 6, 7, 7], 1
Output:[2, 3, 4, 5, 6, 6, 7, 7]
*/
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.empty())
			return 0;
		sort(nums.begin(), nums.end());
		int n = nums.size(), len=n;
		int flag = -1;
		for (int i = 0, j = 0; i < n; i++){
			if (nums[i] == val){
				len--;
				if (flag==-1)
					flag = i;
			}
		}
		if (len != n)
		for (size_t i = 0; i < n - len;++i)
			nums.erase(nums.begin() + flag);
		return len;
	}
};

int main(void){
	Solution answer;
	int a[] = { 1, 1, 2, 3, 4, 5, 6, 6, 7, 7 };
	vector<int> ret;
	for (size_t i = 0; i < 10; ++i)
		ret.push_back(a[i]);
	cout << answer.removeElement(ret, 1) << endl;
	for (size_t i = 0; i < ret.size();++i)
		cout << ret[i] << " ";
	cout << endl;
	system("Pause");
	return 0;
}

