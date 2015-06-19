// [LeetCode]Length of Last Word.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
/*
Input:"Hello World"
Output:5
*/
class Solution {
public:
	int lengthOfLastWord(string s) {
		if (s.empty())
			return 0;
		reverse(s.begin(), s.end());
		string::const_iterator iter = s.begin();
		while (*iter == ' ')
			iter++;
		s = s.substr(iter-s.begin(), s.end()-iter);
		string::const_iterator finditer = find(s.begin(), s.end(), ' ');
		return finditer - s.begin();
	}
};

int main(void){
	Solution answer;
	cout << answer.lengthOfLastWord("") << endl;
	cout << answer.lengthOfLastWord("H   6     ") << endl;
	cout << answer.lengthOfLastWord("Hello World") << endl;

	system("Pause");
	return 0;
}

