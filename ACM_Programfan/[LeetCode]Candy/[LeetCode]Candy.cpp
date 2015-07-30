// [LeetCode]Candy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:[4,3,2,1,5]
Output:12
*/
class Solution {
public:
	int candy(vector<int>& ratings) {
		if (ratings.empty())
			return 0;
		int sum = 0, n = ratings.size();
		vector<int> cands(n,1);
		for (size_t i = 1; i < n; ++i){
			if (ratings[i]>ratings[i - 1])
				cands[i] = cands[i - 1] + 1;
		}
		for (size_t i = n - 1; i > 0; --i){
			if (ratings[i] < ratings[i - 1] && cands[i] >= cands[i - 1])
				cands[i - 1] = cands[i] + 1;
		}
		for (size_t i = 0; i < n; ++i)
			sum += cands[i];
		return sum;
	}
};
int main(void){
	Solution answer;
	int a[] = { 1,1,1,1,1 };
	vector<int> ratings;
	for (size_t i = 0; i < 5; ++i)
		ratings.push_back(a[i]);
	cout << answer.candy(ratings) << endl;
	system("Pause");
	return 0;
}