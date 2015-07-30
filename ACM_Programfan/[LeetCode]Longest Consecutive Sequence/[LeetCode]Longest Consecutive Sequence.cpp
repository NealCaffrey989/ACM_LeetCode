// [LeetCode]Longest Consecutive Sequence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
/*
Input:
Output:
*/
class Solution {
public:
	int findBound(set<int>& flag, int n, bool asc){
		int ans = 0;
		set<int>::iterator iter;
		while ((iter = flag.find(n)) != flag.end()){
			flag.erase(iter);
			ans++;
			if (asc) 
				n--; 
			else 
				n++;
		}
		return ans;
	}
	int longestConsecutive(vector<int> &num) {
		set<int> flag;
		int ans = 0;
		flag.clear();
		for (int i = 0; i < num.size(); i++)
			flag.insert(num[i]);
		for (int i = 0; i < num.size(); i++)
			ans = max(findBound(flag, num[i], true) + findBound(flag, num[i] + 1, false), ans);
		return ans;
	}
};
int main(void){
	Solution answer;
	vector<int> ans{ 100, 4, 200, 1, 3, 2 };
	cout << answer.longestConsecutive(ans) << endl;
	system("Pause");
	return 0;
}

