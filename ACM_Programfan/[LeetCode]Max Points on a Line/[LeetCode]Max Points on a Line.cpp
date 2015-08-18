// [LeetCode]Max Points on a Line.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
/*
Input:
Output:
*/
struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};
class Solution {
public:
	int maxPoints(vector<Point>& points) {
		if (points.empty() || points.size() <= 2)
			return points.size();
		unordered_map<double, int> umap;
		int maxP = 0;
		for (size_t i = 0; i < points.size() - 1; ++i){
			for (size_t j = i + 1; j < points.size(); ++j){
				double p = std::numeric_limits<double>::infinity();
				if (points[j].x != points[i].x)
					p = (points[j].y - points[i].y) / (points[j].x - points[i].x);
				if (umap[p] == 0)
					umap[p]++;
				umap[p]++;
				cout << p << " " << umap[p] << endl;
				maxP = max(maxP, umap[p]);
			}
		}
		return maxP + 1;
	}
};
int main(void){
	Solution answer;
	vector<Point> points{ Point(1, 2), Point(2, 3), Point(1, 1), Point(2, 2), Point(3, 4) };
	cout << answer.maxPoints(points) << endl;
	system("Pause");
	return 0;
}

