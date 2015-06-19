// [LeetCode]Plus One.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:123456789
Output:123456790
*/

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		size_t len = digits.size();
		const int up = 1;
		while (len--){
			if (digits[len] + up > 9)
				digits[len] = 0;
			else{
				digits[len] += up;
				return digits;
			}
		}
		digits.insert(digits.begin(), up);
		return digits;
	}
};

int main(void){
	Solution answer;
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int> digits;
	for (size_t i = 0; i < 9; ++i)
		digits.push_back(a[i]);
	vector<int> ret=answer.plusOne(digits);
	for (size_t i = 0; i < ret.size(); ++i)
		cout << ret[i] << " ";
	cout << endl;
	system("Pause");
	return 0;
}

