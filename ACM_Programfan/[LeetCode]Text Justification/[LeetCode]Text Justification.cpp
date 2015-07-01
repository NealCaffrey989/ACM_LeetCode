// [LeetCode]Text Justification.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Input:["This", "is", "an", "example", "of", "text", "justification."] 16
Output:
[
"This    is    an",
"example  of text",
"justification.  "
]
*/
class Solution {
public:
	string genNormalLine(vector<string> &words, int L, int start, int end){
		int word_count = end - start + 1;
		string line;
		if (word_count == 1){
			line.append(words[start]);
			line.append(L - line.size(), ' ');
		}
		else{
			int slot_num = word_count - 1;
			int words_size = 0;
			for (int i = start; i <= end; i++)
				words_size += words[i].size();
			int space_num = L - words_size;
			int reminder = space_num % slot_num;
			int quotient = space_num / slot_num;
			line.append(words[start]);
			for (int i = start + 1; i <= end; i++) {
				if (reminder > 0){
					line.append(quotient + 1, ' ');
					reminder--;
				}
				else
					line.append(quotient, ' ');
				line.append(words[i]);
			}
		}
		return line;
	}
	vector<string> fullJustify(vector<string> &words, int L) {
		vector<string> formatted_lines;
		if (words.size() == 0)
			return formatted_lines;
		for (int i = 0; i < words.size();){
			int length = 0;
			int j = i;
			for (; j < words.size(); j++){
				if (j == i)
					length += words[j].size();
				else
					length += (1 + words[j].size());
				if (length > L)
					break;
			}
			if (j == words.size()) {
				string line;
				line.append(words[i]);
				for (int k = i + 1; k < words.size(); k++){
					line.push_back(' ');
					line.append(words[k]);
				}
				if (line.size() < L)
					line.append(L - line.size(), ' ');
				formatted_lines.push_back(line);
			}
			else
				formatted_lines.push_back(genNormalLine(words, L, i, j - 1));
			i = j;
		}
		return formatted_lines;
	};
};
int main(void){
	Solution answer;
	string a[] = { "This", "is", "an", "example", "of", "text", "justification." };
	vector<string>ans;
	for (size_t i = 0; i < 7; ++i)
		ans.push_back(a[i]);
	vector<string>ret = answer.fullJustify(ans, 16);
	for (size_t i = 0; i < ret.size(); ++i)
		cout << ret[i] << endl;
	system("Pause");
	return 0;
}

