// [LeetCode]Reverse Linked List II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
/*
Input:1->2->3->4->5->NULL, 2 ,4
Output: 1->4->3->2->5->NULL
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (m >= n || m < 0 || n < 0)
			return head;
		ListNode *phead = new ListNode(0);
		phead->next = head;
		int len = n - m;
		ListNode *pnext = phead;
		while (m-- > 1 && pnext->next != NULL)
			pnext = pnext->next;
		ListNode *first = pnext->next, *last = first->next, *pfhead=first;
		while (len--){
			first->next = last->next;
			last->next = pfhead;
			pfhead = last;
			last = first->next;
		}
		pnext->next = pfhead;
		return phead->next;
	}
};
int main(void){
	Solution answer;
	ListNode *phead = new ListNode(1), *pnext = phead;
	for (size_t i = 2; i < 6; ++i){
		ListNode *pnode = new ListNode(i);
		pnext->next = pnode;
		pnext = pnext->next;
	}
	ListNode *ret = answer.reverseBetween(phead, 2, 4);
	while (ret != NULL){
		cout << ret->val << "->";
		ret = ret->next;
	}
	cout << endl;
	system("Pause");
	return 0;
}