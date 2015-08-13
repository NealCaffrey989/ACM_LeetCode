// [LeetCode]Count Primes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:
Output:
*/
class Solution {
public:
	int countPrimes(int n) {
		if (n < 2)
			return 0;
		vector<bool> rec(n + 1, false);
		int removed = 0;
		for (int i = 2; (i*i) <= n; i++){
			if (!rec[i]){
				for (int j = 2 * i; j < n; j += i){
					if (!rec[j]){
						rec[j] = true;
						removed++;
					}
				}
			}
		}
		return n - 2 - removed;
	}
};
int main(void){
	Solution answer;
	cout << answer.countPrimes(23) << endl;
	cout << answer.countPrimes(2) << endl;
	cout << answer.countPrimes(1) << endl;
	system("Pause");
	return 0;
}