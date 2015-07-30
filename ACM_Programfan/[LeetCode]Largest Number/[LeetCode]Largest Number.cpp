// [LeetCode]Largest Number.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
Input:[3, 30, 34, 5, 9]
Output:9534330
*/
class Solution {
public:
	string largestNumber(vector<int> &num) {
		vector<string> strs;
		for_each(num.begin(), num.end(), [&](int i) {
			strs.push_back(to_string(i));
		});
		sort(strs.begin(), strs.end(), [&](const string& a, const string& b) {
			return (a + b) > (b + a);
		});
		string ans = "";
		for_each(strs.begin(), strs.end(), [&](string& i) {
			if (ans == "" && i == "0") return;
			ans += i;
		});
		return ans == "" ? "0" : ans;
	}
};
int main(void){
	Solution answer;
	int a[] = { 3, 30, 34, 5, 9 };
	vector<int> nums;
	for (size_t i = 0; i < 5; ++i)
		nums.push_back(a[i]);
	cout << answer.largestNumber(nums) << endl;
	system("Pause");
	return 0;
}
