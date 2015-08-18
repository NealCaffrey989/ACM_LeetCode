// [LeetCode]Sliding Window Maximum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
/*
Input:[1,3,-1,-3,5,3,6,7], 3
Output:[3,3,5,5,6,7]
*/
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> res;
		if (nums.size() < k) 
			return res;
		deque<int> q;
		for (int i = 0; i < nums.size(); ++i){
			if (!q.empty() && q.front() == i - k)
				q.pop_front();
			while (!q.empty() && nums[q.back()] < nums[i])
				q.pop_back();
			q.push_back(i);
			if (i >= k - 1) 
				res.push_back(nums[q.front()]);
			for (size_t j = 0; j < q.size(); ++j)
				cout << q[j] << " ";
			cout << endl;
		}
		return res;
	}
};
int main(void){
	Solution answer;
	vector<int> nums{ 1, 3, -1, -3, 5, 3, 6, 7 };
	vector<int> ret = answer.maxSlidingWindow(nums, 3);
	for (size_t i = 0; i < ret.size(); ++i)
		cout << ret[i] << " ";
	cout << endl;
	system("Pause");
	return 0;
}