// [LeetCode]Compare Version Numbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
/*
Input:"0.1", "1.1"
Output:-1
*/
class Solution {
public:
	vector<int> getVersion(string version){
		stringstream ios(version);
		vector<int> dights;
		string temp;
		while (getline(ios, temp, '.')){
			stringstream is;
			is<<temp;
			int tmep;
			is >> tmep;
			dights.push_back(tmep);
		}
		return dights;
	}
	int compareVersion(string version1, string version2) {
		enum{ Less = -1, Equal, Larger };
		if (version1.empty() || version2.empty()){
			if (version1.empty() && version2.empty())
				return Equal;
			else if (version1.empty())
				return Less;
			else
				return Larger;
		}
		vector<int> vers1 = getVersion(version1);
		vector<int> vers2 = getVersion(version2);
		size_t i = 0;
		for (; i < vers1.size() && i < vers2.size(); ++i){
			if (vers1[i] > vers2[i])
				return Larger;
			else if (vers1[i] < vers2[i])
				return Less;
		}
		if (i == vers1.size() && i == vers2.size())
			return Equal;
		while (i < vers1.size()){
			if (vers1[i++] != 0)
				return Larger;
		}
		while (i < vers2.size()){
			if (vers2[i++] != 0)
				return Less;
		}
		return Equal;
	}
};
int main(void){
	Solution answer;
	cout << answer.compareVersion("0.1", "1.1") << endl;
	cout << answer.compareVersion("1.2", "1.1") << endl;
	cout << answer.compareVersion("1.1.1", "1.1") << endl;
	cout << answer.compareVersion("1.2", "1.2.0") << endl;
	cout << answer.compareVersion("1.2", "1.20") << endl;
	cout << answer.compareVersion("1.2", "13.37") << endl;
	system("Pause");
	return 0;
}

