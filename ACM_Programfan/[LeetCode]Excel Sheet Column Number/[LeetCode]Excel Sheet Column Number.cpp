// [LeetCode]Excel Sheet Column Number.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
/*
Input:"AA"
Output:27
*/
class Solution {
public:
	int titleToNumber(string s) {
		int n = 0;
		const int Num_Domain = 26;
		for (size_t i = 0; i < s.size(); ++i){
			if (isupper(s[i]))
				n = n*Num_Domain + s[i] - 'A' + 1;
			else
				break;
		}
		return n;
	}
};
int main(void){
	Solution answer;
	cout << answer.titleToNumber("A") << endl;
	cout << answer.titleToNumber("a") << endl;
	cout << answer.titleToNumber("AB") << endl; 
	cout << answer.titleToNumber("Z") << endl; 
	system("Pause");
	return 0;
}
