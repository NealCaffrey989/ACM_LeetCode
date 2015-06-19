// [LeetCode]Swap Nodes in Pairs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
/*
Input: 1->2->3->4
Output: 2->1->4->3
*/

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *p, *q, *phead, *pnext=new ListNode(0);
		p = head;
		q = head->next;
		phead = pnext;
		do{
			q = p->next;
			p->next = q->next;
			q->next = p;
			pnext->next = q;
			pnext = p;
			if (p != NULL)
				p = p->next;
		} while (p != NULL&&p->next != NULL);
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
	ListNode *p = answer.swapPairs(pHead);
	while (p){
		cout << p->val << " ";
		p = p->next;
	}
	system("Pause");
	return 0;
}

