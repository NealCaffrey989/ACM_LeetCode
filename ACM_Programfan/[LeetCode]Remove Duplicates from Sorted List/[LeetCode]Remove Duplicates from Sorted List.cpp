// [LeetCode]Remove Duplicates from Sorted List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
/*
Input:1->1->2->3->3
Output:1->2->3
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
		ListNode *phead = head, *pfirst = head, *pnext = pfirst->next;
		while (pnext != NULL){
			pnext = pfirst->next;
			while (pnext != NULL && pfirst->val == pnext->val)
				pnext = pnext->next;
			pfirst->next = pnext;
			pfirst = pfirst->next;
		}
		return phead;
	}
};
int main(void){
	Solution answer;
	ListNode* phead = new ListNode(1);
	ListNode* node1 = new ListNode(1);
	phead->next = node1;
	ListNode* node2 = new ListNode(1);
	node1->next = node2;
	ListNode* node3 = new ListNode(2);
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