// [LeetCode]Permutation Sequence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Input:3 2
Output:132
*/
class Solution {
public:
	string getPermutation(int n, int k) {
		vector<int> num;
		int perm_sum = 1;
		for (int i = 0; i < n; ++i){
			num.push_back(i + 1);
			perm_sum *= (i + 1);
		}
		string ret;
		--k;
		for (int i = 0; i < n; ++i){
			perm_sum = perm_sum / (n - i);
			int selected = k / perm_sum;
			ret.push_back(num[selected] + '0');
			num.erase(num.begin() + selected);
			k = k % perm_sum;
		}
		return ret;
	}
};
int main(void){
	Solution answer;
	cout << answer.getPermutation(3, 2) << endl;;
	system("Pause");
	return 0;
}

