// [LeetCode]Valid Palindrome.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
/*
Input:"A man, a plan, a canal: Panama"
Output:true
*/
class Solution {
public:
	bool isPalindrome(string s) {
		if (s.empty())
			return true;
		int first = 0, last = s.size() - 1;
		while (first < last){
			while (first < last && !isalnum(s[first]))
				first++;
			while (first < last && !isalnum(s[last]))
				last--;
			if (tolower(s[first]) != tolower(s[last]))
				return false;
			first++;
			last--;
		}
		return true;
	}
};
int main(void){
	Solution answer;
	cout << answer.isPalindrome("A man, a plan, a canal: Panama") << endl;
	cout << answer.isPalindrome("race a car") << endl;
	cout << answer.isPalindrome("ab") << endl;
	system("Pause");
	return 0;
}

