// [LeetCode]Two Sum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;
/*
Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/
class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		int i, sum;
		vector<int> results;
		map<int, int> hmap;
		for (i = 0; i<numbers.size(); i++){
			if (!hmap.count(numbers[i])){
				hmap.insert(pair<int, int>(numbers[i], i));
			}
			if (hmap.count(target - numbers[i])){
				int n = hmap[target - numbers[i]];
				if (n<i){
					results.push_back(n + 1);
					results.push_back(i + 1);
					return results;
				}
			}
		}
		return results;
	}
};
int main(void){
	Solution answer;
	vector<int> v;
	v.push_back(2);
	v.push_back(7);
	v.push_back(11);
	v.push_back(15);
	for (int i = 0; i < answer.twoSum(v, 9).size();i++)
		cout << answer.twoSum(v, 9)[i] << endl;
	system("Pause");
	return 0;
}

