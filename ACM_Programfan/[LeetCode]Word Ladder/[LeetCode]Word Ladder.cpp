// [LeetCode]Word Ladder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <unordered_set>
#include <queue>
#include <set>
using namespace std;
/*
Input:"hit", "cog", ["hot","dot","dog","lot","log"]
Output:5
*/
class Solution {
public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
		if (beginWord.empty() || endWord.empty())
			return 0;
		if (beginWord.size() != endWord.size())
			return 0;
		if (beginWord.compare(endWord) == 0)
			return 1;

		size_t size = beginWord.size();
		queue<string> cur, next;
		cur.push(beginWord);
		int length = 2;

		while (!cur.empty()){
			string org = cur.front();
			cur.pop();
			for (size_t i = 0; i< size; ++i){
				string tmp = org;
				for (char j = 'a'; j <= 'z'; j++){
					if (tmp[i] == j)
						continue;
					if (tmp.compare(endWord) == 0)
						return length;
					tmp[i] = j;
					if (wordDict.find(tmp) != wordDict.end()){
						next.push(tmp);
						wordDict.erase(wordDict.find(tmp));
					}
				}
			}
			if (cur.empty() && !next.empty()){
				swap(cur, next);
				length++;
			}
		}
		return 0;
	}
}; 
int main(void){
	Solution answer;
	unordered_set<string> wordDict{ "hot", "dot", "dog", "lot", "log" };
	cout << answer.ladderLength("hit", "cog", wordDict) << endl;
	system("Pause");
	return 0;
}