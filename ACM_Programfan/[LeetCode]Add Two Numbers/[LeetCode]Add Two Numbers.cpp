// [LeetCode]Add Two Numbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
/*
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/
/**
* Definition for singly-linked list.
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;
		ListNode *l3 = NULL, *node;
		ListNode *pHead1 = l1, *pHead2 = l2, *pHead3 = l3;
		int up = 0;
		while (pHead1 != NULL && pHead2 != NULL){
			node = new ListNode(pHead1->val + pHead2->val + up);
			up = node->val / 10;
			node->val = node->val % 10;
			if (l3 == NULL){
				l3 = pHead3 = node;
			}
			else{
				pHead3->next = node;
				pHead3 = pHead3->next;
			}
			pHead1 = pHead1->next;
			pHead2 = pHead2->next;
		}
		while (pHead1 != NULL){
			node = new ListNode(pHead1->val + up);
			up = node->val / 10;
			node->val = node->val % 10;
			pHead3->next = node;
			pHead1 = pHead1->next;
			pHead3 = pHead3->next;
		}
		while (pHead2 != NULL){
			node = new ListNode(pHead2->val + up);
			up = node->val / 10;
			node->val = node->val % 10;
			pHead3->next = node;
			pHead2 = pHead2->next;
			pHead3 = pHead3->next;
		}
		if (up > 0){
			node = new ListNode(up);
			pHead3->next = node;
		}
		return l3;
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
	ListNode *p = answer.addTwoNumbers(pHead1, pHead2);
	while (p){
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	system("Pause");
	return 0;
}