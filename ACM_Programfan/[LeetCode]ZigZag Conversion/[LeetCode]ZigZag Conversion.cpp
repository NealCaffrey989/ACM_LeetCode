// [LeetCode]ZigZag Conversion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
/*
Input: convert("PAYPALISHIRING", 3) 
Output: "PAHNAPLSIIGYIR".
*/
class Solution {
public:
	string convert(string s, int nRows) {
		if (nRows <= 1 || s.size() == 0)
			return s;
		string str;
		for (int i = 0; i < s.size() && i < nRows; i++){
			int j = i, x = 1;
			while (j < s.size()){
				str += s[j];
				if (i == 0 || i == nRows - 1)
					j += 2 * nRows - 2;
				else{
					if (x & 0x1)
						j += 2 * (nRows - i - 1);
					else
						j += 2 * i;
					x++;
				}
			}
		}
		return str;
	}
};

int main(void){
	Solution answer;
	cout << answer.convert("abcabca",4) << endl;
	cout << answer.convert("abba",2) << endl;
	cout << answer.convert("PAYPALISHIRING", 3) << endl;
	system("Pause");
	return 0;
}

