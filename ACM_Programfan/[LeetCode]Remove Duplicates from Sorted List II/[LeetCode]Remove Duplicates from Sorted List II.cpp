// [LeetCode]Remove Duplicates from Sorted List II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
/*
Input:1->1->2->3->3
Output:2
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *phead = new ListNode(0), *psecond = phead;
		ListNode *pfirst = head, *pnext = pfirst->next;
		while (pnext != NULL){
			if (pfirst->val == pnext->val){
				while (pnext != NULL && pfirst->val == pnext->val)
					pnext = pnext->next;
				if (pnext == NULL){
					psecond->next = pnext;
					return phead->next;
				}
				pfirst = pnext;
			}
			else{
				psecond->next = pfirst;
				pfirst = pfirst->next;
				psecond = psecond->next;
			}
			pnext = pfirst->next;
		}
		psecond->next = pfirst;
		return phead->next;
	}
};
int main(void){
	Solution answer;
	ListNode* phead = new ListNode(1);
	ListNode* node1 = new ListNode(1);
	phead->next = node1;
	ListNode* node2 = new ListNode(2);
	node1->next = node2;
	ListNode* node3 = new ListNode(3);
	node2->next = node3;
	ListNode* node4 = new ListNode(3);
	node3->next = node4;
	ListNode* ret = answer.deleteDuplicates(phead);
	while (ret != NULL){
		cout << ret->val << "->";
		ret = ret->next;
	}
	cout << endl;
	system("Pause");
	return 0;
}

