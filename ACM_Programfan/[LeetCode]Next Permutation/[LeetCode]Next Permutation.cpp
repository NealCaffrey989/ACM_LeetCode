// [LeetCode]Next Permutation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:1,2,3 
Output:1,3,2
*/
class Solution {
public:
	void nextPermutation(vector<int> &num) {
		int end = num.size() - 1;
		int povit = end;
		while (povit){
			if (num[povit] > num[povit-1]) 
				break;
			povit--;
		}
		if (povit > 0){
			povit--;
			int large = end;
			while (num[large] <= num[povit]) large--;
			swap(num[large], num[povit]);
			reverse(num.begin() + povit + 1, num.end());
		}
		else
			reverse(num.begin(), num.end());
	}
};

int main(void){
	Solution answer;
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(5);
	answer.nextPermutation(v);
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
	system("Pause");
	return 0;
}

