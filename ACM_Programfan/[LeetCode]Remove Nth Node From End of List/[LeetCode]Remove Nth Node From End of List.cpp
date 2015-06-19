// [LeetCode]Remove Nth Node From End of List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == NULL || n == 0)
			return head;
		ListNode *pf, *pl, *temp = NULL;
		pf = pl = head;
		int i = 0;
		for (; i < n - 1; ++i){
			if (pl->next)
				pl = pl->next;
			else
				return head;
		}
		while (pl->next){
			temp = pf;
			pl = pl->next;
			pf = pf->next;
		}
		if (temp == NULL){
			head = pf->next;
			delete pf;
		}
		else{
			temp->next = pf->next;
			delete pf;
		}
		return head;
	}
};
int main(void){
	Solution answer;
	ListNode *pHead1 = new ListNode(2);
	ListNode *pNext11 = new ListNode(4);
	pHead1->next = pNext11;
	ListNode *pNext12 = new ListNode(3);
	pNext11->next = pNext12;
	ListNode *p = answer.removeNthFromEnd(pHead1, 2);
	while (p){
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	system("Pause");
	return 0;
}

