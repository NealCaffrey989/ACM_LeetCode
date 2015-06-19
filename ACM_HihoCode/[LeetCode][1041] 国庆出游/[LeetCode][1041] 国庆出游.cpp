// [HihoCoder][1041] ¹úÇì³öÓÎ.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/*
Input:
2
7
1 2
1 3
2 4
2 5
3 6
3 7
3
3 7 2
7
1 2
1 3
2 4
2 5
3 6
3 7
3
3 2 7
Output:
yes
no
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

string canTravel(vector< vector<int> > roads, map<int, int> order, int k){
	if (roads.empty())
		return "NO";
	map<int, int> travel;
	travel[0] = 1;
	int city = 0, citynum = roads.size();
	while (travel.size() != citynum){
		for (int i = 0; i < citynum; ++i){
			if (roads[city][i]>0 && order[i] <= k){
				cout << i << endl;
				if (travel.find(i) == travel.end())
					travel[i] = 1;
				else
					travel[i]++;
				if (roads[city][i] > 1){
					roads[city][i] = 0;
					roads[i][city] = 0;
				}
				else{
					roads[city][i] = 1;
					roads[i][city] = 1;
				}
				if (order[i] == k)
					k++;
				city = i;
			}
		}
		return "NO";
	}
	return "YES";
}

void NationalDayTravel(void){
	int dataNum;
	cin >> dataNum;
	while (dataNum--){
		int cityNum;
		cin >> cityNum;
		vector< vector<int> > Roads;
		for (int i = 0; i < cityNum; ++i){
			vector<int> road(cityNum, -1);
			Roads.push_back(road);
		}
		while (--cityNum){
			int i = 0, j = 0;
			cin >> i >> j;
			Roads[i - 1][j - 1] = 1;
			Roads[j - 1][i - 1] = 1;
		}
		int orderNum;
		cin >> orderNum;
		map<int, int> Order;
		for (int i = 1; i <= orderNum; ++i){
			int order;
			cin >> order;
			Order[order - 1]=i;
		}
		cout << canTravel(Roads,Order,1) << endl;
	}
}
int main(void){
	NationalDayTravel();
	system("Pause");
	return 0;
}

