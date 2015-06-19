// [LeetCode]Merge Two Sorted Lists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
/*
Input: (1 -> 2 -> 3) + (2 -> 3 -> 4)
Output: 1 -> 2 -> 2 -> 3 -> 3 -> 4
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;
		ListNode *p1, *p2, *pHead, *pNext;
		p1 = l1, p2 = l2, pHead = pNext = new ListNode(0);
		while (p1 != NULL&&p2 != NULL){
			if (p1->val <= p2->val){
				pNext->next = p1;
				p1 = p1->next;
			}
			else{
				pNext->next = p2;
				p2 = p2->next;
			}
			pNext = pNext->next;
		}
		while (p1 != NULL){
			pNext->next = p1;
			p1 = p1->next;
			pNext = pNext->next;
		}
		while (p2 != NULL){
			pNext->next = p2;
			p2 = p2->next;
			pNext = pNext->next;
		}
		return pHead->next;
	}
};
int main(void){
	Solution answer;
	ListNode *pHead1 = new ListNode(2);
	ListNode *pNext11 = new ListNode(4);
	pHead1->next = pNext11;
	ListNode *pNext12 = new ListNode(3);
	pNext11->next = pNext12;
	ListNode *pHead2 = new ListNode(5);
	ListNode *pNext21 = new ListNode(6);
	pHead2->next = pNext21;
	ListNode *pNext22 = new ListNode(4);
	pNext21->next = pNext22;
	ListNode *p = answer.mergeTwoLists(pHead1, pHead2);
	while (p){
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	system("Pause");
	return 0;
}

