// [LeetCode]Insert Interval.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Input:[1,2],[3,5],[6,7],[8,10],[12,16],   [4,9] 
Output:[1,2],[3,10],[12,16]
*/
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> ret;
		vector<Interval>::const_iterator iter = intervals.begin();
		for (; iter != intervals.end() && (*iter).end < newInterval.start; ++iter)
			ret.push_back(*iter);
		if (iter == intervals.end()){
			ret.push_back(newInterval);
			return ret;
		}
		newInterval.start = min(newInterval.start, (*iter).start);
		for (; iter != intervals.end() && (*iter).start <= newInterval.end; ++iter)
			newInterval.end = max(newInterval.end, (*iter).end);
		ret.push_back(newInterval);
		for (; iter != intervals.end(); ++iter)
			ret.push_back(*iter);
		return ret;
	}
};
int main(void){
	Solution answer;
	int a[][2] = { { 1, 2 }, { 3, 5 }, { 6, 7 }, { 8, 10 }, { 12, 16 } };
	vector<Interval> ret;
	for (size_t i = 0; i < 5; ++i){
		Interval ital(a[i][0], a[i][1]);
		ret.push_back(ital);
	}
	Interval newIn(4, 9);
	vector<Interval> r = answer.insert(ret, newIn);
	for (size_t i = 0; i < r.size(); ++i)
		cout << r[i].start << " " << r[i].end << endl;
	system("Pause");
	return 0;
}