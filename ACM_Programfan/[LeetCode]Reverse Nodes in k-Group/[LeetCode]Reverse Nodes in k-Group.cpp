// [LeetCode]Reverse Nodes in k-Group.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
/*
Input: 1->2->3->4->5
Output: 3->2->1->4->5
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool isKLen(ListNode* head, int k){
		if (k <= 0 || head == NULL)
			return false;
		ListNode *phead = head;
		int count = k - 1;
		while (phead->next != NULL&&count){
			phead = phead->next;
			count--;
		}
		if (count == 0)
			return true;
		else
			return false;
	}
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (head == NULL || k <= 1)
			return head;
		ListNode *p, *q, *phead, *pnext = new ListNode(0);
		pnext->next = p = head;
		phead = pnext;
		while (isKLen(p,k)){
			int count = k-1;
			ListNode *qt = pnext->next;
			while (count--){
				q = p->next;
				p->next = q->next;
				q->next = qt;
				qt = q;
			}
			pnext->next = qt;
			pnext = p;
			p = p->next;
		}
		return phead->next;
	}
};


int main(void){
	Solution answer;
	ListNode *pHead = new ListNode(1), *q = pHead;
	for (int i = 1; i < 5; i++){
		ListNode *pNext = new ListNode(i + 1);
		q->next = pNext;
		q = q->next;
	}
	ListNode *p = answer.reverseKGroup(pHead,5);
	while (p){
		cout << p->val << " ";
		p = p->next;
	}
	system("Pause");
	return 0;
}



