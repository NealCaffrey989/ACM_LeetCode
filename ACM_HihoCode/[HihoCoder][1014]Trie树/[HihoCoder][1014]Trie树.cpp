// [HihoCoder][1014]TrieÊ÷.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/*
Input:
5
babaab
babbbaaaa
abba
aaaaabaa
babaababb
5
babb
baabaaa
bab
bb
bbabbaab
Output:
1
0
3
0
0
*/
#include <iostream>
#include <string>
using namespace std;

struct ListNode {
	char val;
	int count;
	ListNode *next;
	ListNode *left;
	ListNode(char x) : val(x), count(1), next(NULL), left(NULL) {}
	ListNode() : val(' '), count(0), next(NULL), left(NULL) {}
};
void makeTrieTree(ListNode* trieHead, string str){
	ListNode* pnext = trieHead;
	for (string::const_iterator iter = str.begin(); iter != str.end(); ++iter){
		if (pnext->next == NULL){
			for (; iter != str.end(); ++iter){
				ListNode* p = new ListNode(*iter);
				pnext->next = p;
				pnext = pnext->next;
			}
			break;
		}
		else if (*iter == pnext->next->val){
			pnext->next->count++;
			pnext = pnext->next;
		}
		else{
			pnext = pnext->next;
			while (pnext->left != NULL&&pnext->left->val != *iter){
				pnext = pnext->left;
			}
			if (pnext->left == NULL){
				ListNode* p = new ListNode(*iter);
				pnext->left = p;
				pnext = pnext->left;
				++iter;
				for (; iter != str.end(); ++iter){
					ListNode* p = new ListNode(*iter);
					pnext->next = p;
					pnext = pnext->next;
				}
				break;
			}
			else {//if (pnext->left->val == *iter){
				pnext->left->count++;
				pnext = pnext->left;
			}
		}
	}
}
int findPrefixCharNum(ListNode* trieHead, string str){
	if (str.empty() || trieHead == NULL)
		return 0;
	ListNode* pNext = trieHead;
	string::const_iterator iter = str.begin();
	for (; iter != str.end(); ++iter){
		if (pNext->next == NULL)
			return 0;
		if (pNext->next->val == *iter)
			pNext = pNext->next;
		else{
			pNext = pNext->next;
			while (pNext->left != NULL&&pNext->left->val != *iter)
				pNext = pNext->left;
			if (pNext->left == NULL)
				return 0;
			else
				pNext = pNext->left;
		}
	}
	if (iter == str.end())
		return pNext->count;
	else
		return 0;
}
void TrieTree(void){
	ListNode* trieHead = new ListNode();
	int trieNum = 0;
	cin >> trieNum;
	while (trieNum--){
		string str;
		cin >> str;
		makeTrieTree(trieHead, str);
	}
	int opNum = 0;
	cin >> opNum;
	while (opNum--){
		string op;
		cin >> op;
		cout << findPrefixCharNum(trieHead, op) << endl;
	}
}

int main(void){
	TrieTree();
	system("Pause");
	return 0;
}