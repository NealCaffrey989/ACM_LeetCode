// [LeetCode]Palindrome Partitioning II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Input:"aab"
Output:1
*/
/*
class Solution {
public:
	int minCut(string s) {
		int len = s.size();
		vector<int> D(len + 1);
		vector<vector<bool>> P(len, vector<bool>(len, false));
		for (int i = 0; i <= len; i++)
			D[i] = len - i;
		for (int i = len - 1; i >= 0; i--){
			for (int j = i; j < len; j++){
				if (s[i] == s[j] && (j - i<2 || P[i + 1][j - 1])){
					P[i][j] = true;
					D[i] = min(D[i], D[j + 1] + 1);
				}
			}
		}
		return D[0] - 1;
	}
};*/
class Solution {
public:
	int minCut(string s) {
		int min = INT_MAX;
		DFS(s, 0, 0, min);
		return min;
	}
	void DFS(string &s, int start, int depth, int& min)  {
		if (start == s.size())  {
			if (min> depth - 1)
				min = depth - 1;
			return;
		}
		for (int i = s.size() - 1; i >= start; i--) {
			if (isPalindrome(s, start, i)) 
				DFS(s, i + 1, depth + 1, min);
		}
	}
	bool isPalindrome(string &s, int start, int end) {
		while (start< end) {
			if (s[start] != s[end])
				return false;
			start++; end--;
		}
		return true;
	}
};
int main(void){
	Solution answer;
	cout << answer.minCut("aab") << endl;
	system("Pause");
	return 0;
}