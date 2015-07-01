// [LeetCode]Partition List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
/*
Input:1->4->3->2->5->2   3
Output: 1->2->2->4->3->5
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		if (head == NULL)
			return head;
		ListNode *phead = new ListNode(0), *pnew = new ListNode(0);
		ListNode *pnext = head, *pfirst = phead, *psecond = pnew;
		while (pnext!=NULL){
			if (pnext->val >= x){
				psecond->next = pnext;
				psecond = psecond->next;
			}
			else{
				pfirst->next = pnext;
				pfirst = pfirst->next;
			}
			pnext = pnext->next;
		}
		pfirst->next = pnew->next;
		psecond->next = NULL;
		return phead->next;
	}
};
int main(void){
	Solution answer;
	ListNode *phead = new ListNode(1);
	ListNode *pnext = phead;
	int a[] = { 1, 4, 3, 2, 5, 2 };
	for (size_t i = 1; i < 6; ++i){
		ListNode *node = new ListNode(a[i]);
		pnext->next = node;
		pnext = pnext->next;
	}
	ListNode *ret = answer.partition(phead, 3);
//	ListNode *ret = phead;
	while (ret != NULL){
		cout << ret->val << "->";
		ret = ret->next;
	}
	cout << endl;
	system("Pause");
	return 0;
}