// [HihoCoder][1037] Êý×ÖÈý½ÇÐÎ.cpp : Defines the entry point for the console application.
//
/*
Input:
5
2
6 4
1 2 8
4 0 9 6
6 5 5 3 6
Output:
28
*/
#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int findMaxAward(vector< vector<int> > ret){
	if (ret.empty())
		return 0;
	int n = ret.size();
	vector<int> record(n, 0);
	record[0] = ret[0][0];
	for (int i = 1; i < n; ++i){
		record[i] = record[i - 1] + ret[i][i];
		for (int j = i - 1; j > 0; --j)
			record[j] = max(record[j - 1] + ret[i][j], record[j] + ret[i][j]);
		record[0] = record[0] + ret[i][0];
	}
	int award = 0;
	for (int i = 0; i < n; ++i){
		if (award < record[i])
			award = record[i];
	}	
	return award;
}
void DigitalTriangle(void){
	int dataNum;
	cin >> dataNum;
	vector< vector<int> > ret;
	for (size_t i = 1; i <= dataNum;++i){
		vector<int> row(i);
		for (size_t j = 0; j < i; ++j)
			cin >> row[j];
		ret.push_back(row);
	}
	cout << findMaxAward(ret) << endl;
}
int main(void){
	DigitalTriangle();
	system("Pause");
	return 0;
}

