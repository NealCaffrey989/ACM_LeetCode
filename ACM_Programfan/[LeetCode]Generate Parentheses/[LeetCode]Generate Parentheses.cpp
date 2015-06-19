// [LeetCode]Generate Parentheses.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Input: 2
Output: ()() (())
*/
class Solution {
public:
	void unguarded_generate(vector<string> &result, string curr, int m, int n){
		if (m == 0 && n == 0){
			result.push_back(curr);
		}
		else{
			if (m != 0){
				cout << curr << endl;
				unguarded_generate(result, curr + "(", m - 1, n);
			}
			if (m < n && n != 0){
				cout << curr << endl;
				unguarded_generate(result, curr + ")", m, n - 1);
			}
		}
	}

	vector<string> generateParenthesis(int n) {
		vector<string> ret;
		if (n > 0){
			unguarded_generate(ret, string(), n, n);
		}
		return ret;
	}
};

vector<string> generateParenthesis(int n) {
	vector<string> result;
	vector<string> temp;
	int count = 0;
	string newComb;
	result.push_back("()");
	if (n == 1) 
		return result;
	for (int k = 1; k < n; k++) {
		for (int i = 0; i < result.size(); i++) {
			count = 0;
			newComb = result[i];
			newComb.insert(newComb.begin(), ')');
			newComb.insert(newComb.begin(), '(');
			temp.push_back(newComb);
            for (int j = 0; j < result[0].size(); j++) {
				if (result[i][j] == '(') 
					count++;				
				else
					count--;
				if (!count) {
					newComb = result[i];
					newComb.insert(newComb.begin() + j, ')');
					newComb.insert(newComb.begin(), '(');
					temp.push_back(newComb);
				}
			}
		}
		result = temp;
		temp.clear();
	}
	return result;
}


void generate(vector< vector<int> > &pNum,vector<int> &num, int m,int n){
	if (m == 0 && 0 == n)
		pNum.push_back(num);
	else{
		if (m != 0){
			num.push_back(1);
			generate(pNum, num, m - 1, n);
		}
		if (n != 0){
			num.push_back(0);
			generate(pNum, num, m, n - 1);
		}
	}	
}
vector< vector<int> > generateNum(int m,int n){
	vector< vector<int> > result;
	if (n > 0){
		generate(result, vector<int>(), m, n-m);
	}
	return result;
}
int main(void){
	Solution answer;
	vector<string> v = generateParenthesis(3);
	for (int i = 0; i < v.size();i++)
		cout << v[i] << endl;
	vector< vector<int> > v1 = generateNum(1,6);
	for (int i = 0; i < v1.size(); i++){
		for (int j = 0; j < v1[i].size(); j++){
//			cout << v1[i][j] << endl;
		}
	}
	system("Pause");
	return 0;
}

