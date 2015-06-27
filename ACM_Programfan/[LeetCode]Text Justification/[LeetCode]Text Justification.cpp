// [LeetCode]Text Justification.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Input:["This", "is", "an", "example", "of", "text", "justification."] 16
Output:
[
"This    is    an",
"example  of text",
"justification.  "
]
*/
class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> str;
		if (maxWidth <= 0 || words.empty())
			return str;
		vector<string> cstr;
		int cnum = 0;
		for (size_t i = 0; i < words.size(); ++i){
			if (cnum+words.size()+1<=maxWidth)
		}
	}
};
int main(void){
	Solution answer;
	system("Pause");
	return 0;
}

