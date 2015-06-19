// [LeetCode]Implement strStr().cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
/*
Input:"a", "a"
Output:0
*/
class Solution {
public:
	int strStr(string haystack, string needle) {
		if (haystack.size() < needle.size())
			return -1;
		if (!needle.size())
			return 0;
		int n = -1;
		for (int i = 0; i <= haystack.size() - needle.size(); i++){
			if (haystack[i] == needle[0]){
				int j = 1;
				for (; j < needle.size(); j++){
					if (haystack[i + j] != needle[j])
						break;
				}
				if (j == needle.size()){
					n = i;
					break;
				}
			}
		}
		return n;
	}
};

int main(void){
	Solution answer;
	string str = "a", s = "a";
	cout << answer.strStr(str, s) << endl;
	cout << answer.strStr("", "") << endl;
	cout << answer.strStr("", s) << endl;
	system("Pause");
	return 0;
}

