// [LeetCode]Letter Combinations of a Phone Number.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Input: 23
Output: ad ae af bd be bf cd cecf
*/
class Solution {
public:
	string getString(char s){
		switch (s){
		case '0':return ""; break;
		case '2':return "abc"; break;
		case '3':return "def"; break;
		case '4':return "ghi"; break;
		case '5':return "jkl"; break;
		case '6':return "mno"; break;
		case '7':return "pqrs"; break;
		case '8':return "tuv"; break;
		case '9':return "wxyz"; break;
		default:return ""; break;
		}
	}
	vector<string> letterCombinations(string digits) {
		vector<string> letter;
		int n = letter.size();
		string strf = getString(digits[0]);
		for (int i = 0; i < strf.size(); i++){
			string s = "";
			s += strf[i];
			letter.push_back(s);
		}
		for (int i = 1; i < digits.size(); i++){
			string strl = getString(digits[i]);
			n = letter.size();
			for (int j = 0; j < n; j++){
				strf = letter[j];
				for (int z = 0; z < strl.size(); z++){
					letter.push_back(strf + strl[z]);
				}
			}
			letter.erase(letter.begin(), letter.begin() + n);
		}
		return letter;
	}
};
int main(void){
	Solution answer;
	for (int i = 0; i < answer.letterCombinations("234").size();i++)
		cout << answer.letterCombinations("234")[i] << endl;
	system("Pause");
	return 0;
}

