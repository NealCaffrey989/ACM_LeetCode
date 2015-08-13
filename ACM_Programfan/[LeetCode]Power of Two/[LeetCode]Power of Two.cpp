// [LeetCode]Power of Two.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
/*
Input:4
Output:true
*/
class Solution {
public:
	bool isPowerOfTwo(int n) {
		return n > 0 && ((n & (n - 1)) == 0);
	}
};
int main(void){
	Solution answer;
	cout << answer.isPowerOfTwo(1) << endl;
	cout << answer.isPowerOfTwo(-1) << endl;
	cout << answer.isPowerOfTwo(0) << endl;
	cout << answer.isPowerOfTwo(5) << endl;
	cout << answer.isPowerOfTwo(4) << endl;
	system("Pause");
	return 0;
}
