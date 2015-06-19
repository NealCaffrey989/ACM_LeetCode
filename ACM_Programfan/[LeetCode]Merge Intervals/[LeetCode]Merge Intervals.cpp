// [LeetCode]Merge Intervals.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Input:[1,3],[2,6],[8,10],[15,18]
Output:[1,6],[8,10],[15,18]
*/
 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

class Solution {
public:
	static bool comp(Interval a, Interval b){
		return a.start < b.start;
	}
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> ret;
		if (intervals.empty())
			return ret;
		sort(intervals.begin(), intervals.end(), comp);
		ret.push_back(intervals[0]);
		for (size_t i = 1; i < intervals.size(); ++i){
			Interval inter=ret.back();
			if (intervals[i].start > inter.end)
				ret.push_back(intervals[i]);
			else 	if (inter.end < intervals[i].end)
				inter.end = intervals[i].end;
		}
		return ret;
	}
};
int main(void){
	Solution answer;
	int a[][2] = { { 1, 7 }, { 2, 6 }, { 8, 10 }, { 15, 18 } };
	vector<Interval> ret;
	for (size_t i = 0; i < 4; ++i){
		Interval ital(a[i][0], a[i][1]);
		ret.push_back(ital);
	}
	vector<Interval> r = answer.merge(ret);
	for (size_t i = 0; i < r.size(); ++i)
		cout << r[i].start << " " << r[i].end << endl;
	system("Pause");
	return 0;
}
