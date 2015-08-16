// [LeetCode]Happy Number.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <set>
using namespace std;
/*
Input:19
Output:true
*/
class Solution {
public:
	bool isHappy(int n) {
		if (n <= 0)
			return false;
		set<int> res;
		while (n != 1){
			int sum = 0;
			while (n != 0){
				int x = n % 10;
				sum += x*x;
				n /= 10;
			}
			if (res.find(sum) != res.end())
				return false;
			res.insert(sum);
			n = sum;
		}
		return true;
	}
};
int main(void){
	Solution answer;
	cout << answer.isHappy(19) << endl;
	cout << answer.isHappy(7) << endl;
	cout << answer.isHappy(2) << endl;
	system("Pause");
	return 0;
}