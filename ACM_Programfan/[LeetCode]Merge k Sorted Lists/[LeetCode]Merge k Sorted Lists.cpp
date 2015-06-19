// [LeetCode]Merge k Sorted Lists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
//#include <heapapi.h>
using namespace std;
/*
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	struct CompareListElement {
		bool operator ()(const ListNode* a, const ListNode* b) const{
			return (a->val > b->val);
		}
	};
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		vector<ListNode*> vecK;
		ListNode* dummyHead = new ListNode(0);
		ListNode* tail = dummyHead;
		for (vector<ListNode *>::size_type i = 0; i < lists.size(); ++i) {
			if (lists[i] != NULL) {
				vecK.push_back(lists[i]);
			}
		}
		std::make_heap(vecK.begin(), vecK.end(), CompareListElement());
		while (!vecK.empty()) {
			tail->next = vecK.front();
			tail = tail->next;
			std::pop_heap(vecK.begin(), vecK.end(), CompareListElement()); 
			vecK.pop_back();
			if (tail->next != NULL) {
				vecK.push_back(tail->next);
				std::push_heap(vecK.begin(), vecK.end(), CompareListElement()); 
			}
		}
		return dummyHead->next;
	}
};

int main(void){
	Solution answer;
	vector<ListNode*> pHead;
	ListNode *pHead1 = new ListNode(2);
/*	ListNode *pNext11 = new ListNode(3);
	pHead1->next = pNext11;
	ListNode *pNext12 = new ListNode(4);
	pNext11->next = pNext12;
*/	ListNode *pHead2 = new ListNode(-1);
/*	ListNode *pNext21 = new ListNode(4);
	pHead2->next = pNext21;
	ListNode *pNext22 = new ListNode(5);
	pNext21->next = pNext22;
*/	ListNode *pHead3 = NULL;
	pHead.push_back(pHead1);
	pHead.push_back(pHead2);
	pHead.push_back(pHead3);
//	pHead.push_back(NULL);
	ListNode *p = answer.mergeKLists(pHead);
	while (p){
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	system("Pause");
	return 0;
}

