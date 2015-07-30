// [LeetCode]Gas Station.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:[1,2,3,4,5], [1,1,3,3,4]
Output:1
*/
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int N = gas.size(), startIndex = -1;
		int sum = 0, total = 0;
		for (int i = 0; i < N; i++){
			sum += (gas[i] - cost[i]);
			total += (gas[i] - cost[i]);
			if (sum < 0){
				startIndex = i;
				sum = 0;
			}
		}
		return total >= 0 ? startIndex + 1 : -1;
	}
};
int main(void){
	Solution answer;
	int a[] = { 0, 2, 3, 4, 5 }, b[] = { 1, 1, 3, 3, 4 };
	vector<int> gas;
	vector<int> cost;
	for (size_t i = 0; i < 5; ++i){
		gas.push_back(a[i]);
		cost.push_back(b[i]);
	}
	cout << answer.canCompleteCircuit(gas, cost) << endl;
	system("Pause");
	return 0;
}

