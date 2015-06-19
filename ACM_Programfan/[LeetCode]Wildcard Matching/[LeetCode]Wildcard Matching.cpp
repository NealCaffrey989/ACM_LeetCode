// [LeetCode]Wildcard Matching.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
/*
Input:
Output:
isMatch("aa","a") ¡ú false
isMatch("aa","aa") ¡ú true
isMatch("aaa","aa") ¡ú false
isMatch("aa", "*") ¡ú true
isMatch("aa", "a*") ¡ú true
isMatch("ab", "?*") ¡ú true
isMatch("aab", "c*a*b") ¡ú false
*/

/*
class Solution {
public:
	bool isMatch(string s, string p){
		if (p.empty()) 
			return s.empty();
		string::const_iterator pter = p.begin(), ster = s.begin();
		if (*pter == '*'){
			while (pter != p.end() && *pter == '*')
				++pter;
			while (pter != p.end() && ster != s.end()){
				if (isMatch(s.substr(ster - s.begin()), p.substr(pter - p.begin())))
					return true;
				++ster;
			}
			if (pter == p.end())
				return true;
			else if (ster == s.end())
				return false;
		}
		else if ((ster != s.end() && *pter == '?') || *pter == *ster)
			return isMatch(s.substr(1), p.substr(1));
		return false;
	}
};*/

class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.empty()) 
			return s.empty();
		string::const_iterator pter = p.begin(), ster = s.begin();
		string::const_iterator star_p, star_s;
		bool sign = false;
		while (ster!=s.end()){
			if (pter == p.end()){
				if (sign){
					ster = ++star_s;
					pter = star_p;
				}
				else
					break;
			}
			else if (*pter == '?' || *pter == *ster)
				++pter, ++ster;
			else if (*pter == '*'){
				while (pter != p.end() && (*pter == '*' || *pter == '?')){
					if (*pter == '?'){
						++pter;
						++ster;
						if (ster == s.end())
							break;
					}
					else
						++pter;
				}
				if (pter==p.end()) 
					return true;
				star_p = pter;
				star_s = ster;
				sign = true;
			}
			else if ((*pter != *ster || *pter!='?') && sign){
				ster = ++star_s;
				pter = star_p; 
			}
			else
				return false;
		}
		if (ster != s.end())
			return false;
		while (pter!=p.end())
			if (*pter++ != '*')
				return false;
		return true;
	}
};
int main(void){
	Solution answer;
	cout << answer.isMatch("aaa", "aa") << endl;
	cout << answer.isMatch("aa", "*?*?*?") << endl;
	cout << answer.isMatch("aab", "c*a*b") << endl;

	cout << answer.isMatch("", "") << endl;
	cout << answer.isMatch("aa", "*a") << endl;
	cout << answer.isMatch("aa", "aa") << endl;
	cout << answer.isMatch("aa", "*?*") << endl;
	cout << answer.isMatch("aa", "*?") << endl;
	cout << answer.isMatch("aa", "aa*************") << endl;
	cout << answer.isMatch("aa", "?a") << endl;
	cout << answer.isMatch("abefcdgiescdfimde", "ab**********cd?i*de") << endl;
	system("Pause");
	return 0;
}