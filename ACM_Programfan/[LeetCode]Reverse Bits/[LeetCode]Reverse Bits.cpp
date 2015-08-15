// [LeetCode]Reverse Bits.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdint.h>
using namespace std;
/*
Input:43261596
Output:964176192
*/
class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t m = 0;
		for (uint32_t i = 1; i != 0; i <<= 1){
			m <<= 1;
			if (n & 1)
				m |= 1;
			n >>= 1;
		}
		return m;
	}
};
int main(void){
	Solution answer;
	uint32_t n(43261596);
	cout << answer.reverseBits(n) << endl;
	system("Pause");
	return 0;
}