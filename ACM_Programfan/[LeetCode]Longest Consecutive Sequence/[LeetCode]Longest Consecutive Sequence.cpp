// [LeetCode]Longest Consecutive Sequence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
/*
Input:[100, 4, 200, 1, 3, 2]
Output:4
*/
class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		if (num.empty())
			return 0;
		map<int, bool> num_map;
		for (vector<int>::const_iterator iter = num.begin(); iter != num.end(); ++iter)
			num_map[*iter] = true;
		int longest = 0;
		for (vector<int>::const_iterator iter = num.begin(); iter != num.end(); ++iter){
			if (!num_map[*iter])
				continue;
			int count = 1;
			num_map[*iter] = false;
			for (int j = *iter + 1; num_map.find(j) != num_map.end(); ++j){
				num_map[j] = false;
				count++;
			}
			for (int j = *iter - 1; num_map.find(j) != num_map.end(); --j){
				num_map[j] = false;
				count++;
			}
			longest = max(longest, count);
		}
		return longest;
	}
};
int main(void){
	Solution answer;
	vector<int> ans{ 100, 4, 200, 1, 3, 2 };
	cout << answer.longestConsecutive(ans) << endl;
	system("Pause");
	return 0;
}

