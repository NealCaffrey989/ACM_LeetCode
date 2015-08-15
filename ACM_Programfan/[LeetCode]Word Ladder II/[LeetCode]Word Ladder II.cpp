// [LeetCode]Word Ladder II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <string>
using namespace std;
/*
Input:"hit", "cog", ["hot","dot","dog","lot","log"]
Output:
[
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
*/
class Solution {
public:
	vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict){
		vector<vector<string>> result;
		unordered_map<string, vector<string>> prevMap;
		for (auto iter = dict.begin(); iter != dict.end(); ++iter)
			prevMap[*iter] = vector<string>();
		vector<unordered_set<string>> candidates(2);
		int current = 0;
		int previous = 1;
		candidates[current].insert(start);
		while (true){
			current = !current;
			previous = !previous;
			for (auto iter = candidates[previous].begin(); iter != candidates[previous].end(); ++iter)
				dict.erase(*iter);
			candidates[current].clear();

			for (auto iter = candidates[previous].begin(); iter != candidates[previous].end(); ++iter){
				for (size_t pos = 0; pos < iter->size(); ++pos){
					string word = *iter;
					for (int i = 'a'; i <= 'z'; ++i){
						if (word[pos] == i)continue;
						word[pos] = i;
						if (dict.count(word) > 0){
							prevMap[word].push_back(*iter);
							candidates[current].insert(word);
						}
					}
				}
			}
			if (candidates[current].size() == 0)
				return result;
			if (candidates[current].count(end)) break;
		}
		vector<string> path;
		GeneratePath(result, prevMap, path, end);
		return result;
	}

private:
	void GeneratePath(vector<vector<string>>& result, unordered_map<string, vector<string>> &prevMap, vector<string>& path, const string& word){
		if (prevMap[word].size() == 0){
			path.push_back(word);
			vector<string> curPath = path;
			reverse(curPath.begin(), curPath.end());
			result.push_back(curPath);
			path.pop_back();
			return;
		}
		path.push_back(word);
		for (auto iter = prevMap[word].begin(); iter != prevMap[word].end(); ++iter)
			GeneratePath(result, prevMap, path, *iter);
		path.pop_back();
	}
};
int main(void){
	Solution answer;
	unordered_set<string> wordDict{ "hot", "dot", "dog", "lot", "log" };
	vector<vector<string> > ret = answer.findLadders("hit", "cog", wordDict);
	for (size_t i = 0; i < ret.size(); ++i){
		for (size_t j = 0; j < ret[i].size(); ++j)
			cout << ret[i][j] << " ";
		cout << endl;
	}
	system("Pause");
	return 0;
}