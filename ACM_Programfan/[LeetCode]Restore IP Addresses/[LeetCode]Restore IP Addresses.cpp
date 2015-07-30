// [LeetCode]Restore IP Addresses.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Input:"25525511135"
Output:["255.255.11.135", "255.255.111.35"]
*/
class Solution {
public:
	bool check(string ip){
		int value = stoi(ip);
		if (ip[0] == '0')
			return (ip.size() == 1);
		else{
			if (value <= 255)
				return true;
			else
				return false;
		}
	}
	vector<string> restoreIpAddresses(string s) {
		vector<string> ret;
		if (s.size() > 12)
			return ret;
		for (int i = 0; i < s.size(); i++){
			for (int j = i + 1; j < s.size(); j++){
				for (int k = j + 1; k < s.size() - 1; k++){
					string ip1 = s.substr(0, i + 1);
					string ip2 = s.substr(i + 1, j - i);
					string ip3 = s.substr(j + 1, k - j);
					string ip4 = s.substr(k + 1);
					if (check(ip1) && check(ip2) && check(ip3) && check(ip4)){
						string ip = ip1 + "." + ip2 + "." + ip3 + "." + ip4;
						ret.push_back(ip);
					}
				}
			}
		}
		return ret;
	}
};
int main(void){
	Solution answer;
	vector<string> ret = answer.restoreIpAddresses("25525511135");
	for (size_t i = 0; i < ret.size(); ++i)
		cout << ret[i] << endl;
	system("Pause");
	return 0;
}
