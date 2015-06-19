// [LeetCode]Simplify Path.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
/*
Input:/home/
Output:/nome
*/
class Solution {
public:
	string simplifyPath(string path) {
		string ans, str;
		vector<string> list;
		stringstream ss(path);
		while (getline(ss, str, '/')){
			if (str.empty() || str == ".")
				continue;
			else if (str == ".."){
				if (!list.empty())
					list.pop_back();
			}
			else
				list.push_back(str);
		}
		for (size_t i = 0; i < list.size(); ++i)
			ans += "/" + list[i];
		if (ans.length() == 0)
			ans = "/";
		return ans;
	}
};
int main(void){
	Solution answer;
	cout << answer.simplifyPath("/home/") << endl;
	cout << answer.simplifyPath("/a/b/../c/d/e/") << endl;
	cout << answer.simplifyPath("") << endl;
	system("Pause");
	return 0;
}

