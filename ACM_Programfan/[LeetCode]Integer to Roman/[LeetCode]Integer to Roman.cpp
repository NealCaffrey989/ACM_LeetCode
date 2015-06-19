// [LeetCode]Integer to Roman.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
/*
Input: 1
Output: I
*/
class Solution {
public:
	string intToRoman(int num) {
		if (num < 1 || num>3999)
			return "";
		string symbol[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		int value[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		string Roman="";
		for (int i = 0; num != 0; i++){
			while (num >= value[i]){
				Roman += symbol[i];
				num -= value[i];
			}
		}
		return Roman;
	}
};
int main(void){
	Solution answer;
	cout << answer.intToRoman(25) << endl;
	system("Pause");
	return 0;
}

