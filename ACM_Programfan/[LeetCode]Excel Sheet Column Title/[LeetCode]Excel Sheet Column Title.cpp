// [LeetCode]Excel Sheet Column Title.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
/*
Input:27
Output:"AA"
*/
class Solution {
public:
	string convertToTitle(int n) {
		string str;
		if (n < 1)
			return str;
		const int Num_Domain = 26;
		while (n){
			str += (char)((n - 1) % Num_Domain + 'A');
			n = (n - 1) / Num_Domain;
		}
		reverse(str.begin(), str.end());
		return str;
	}
};
int main(void){
	Solution answer;
	cout << answer.convertToTitle(1) << endl;
	cout << answer.convertToTitle(0) << endl; 
	cout << answer.convertToTitle(-1) << endl;
	cout << answer.convertToTitle(26) << endl;
	cout << answer.convertToTitle(28) << endl;
	system("Pause");
	return 0;
}

