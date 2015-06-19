// [LeetCode]Trapping Rain Water.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
Input:[0,1,0,2,1,0,1,3,2,1,2,1]
Output:6
*/
class Solution {
public:
	int trap(vector<int>& height) {
		if (height.empty() || height.size() == 1)
			return 0;
		int left = 0, right = height.size() - 1;
		int water = 0;
		while (left < right){
			if (height[left] < height[right]){
				int i = left + 1;
				while (i < right && height[i] < height[left])
					water += height[left] - height[i++];
				left = i;
			}
			else{
				int i = right - 1;
				while (i > left && height[i] < height[right])
					water+=height[right] - height[i--];
				right = i;
			}
		}
		return water;
	}
};
int main(void){
	Solution answer;
	int a[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	vector<int> ret;
	for (size_t i = 0; i < 12; ++i)
		ret.push_back(a[i]);
	cout << answer.trap(ret) << endl;
	system("Pause");
	return 0;
}
