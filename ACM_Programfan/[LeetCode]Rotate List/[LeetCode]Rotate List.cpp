// [LeetCode]Rotate List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
/*
Input:1->2->3->4->5->NULL 2
Output:4->5->1->2->3->NULL
*/
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL || k <= 0)
			return head;
		ListNode* phead = head;
		ListNode* left, *right;
		int len = 1;
		left = right = head;
		while (right->next != NULL && len <= k){
			right = right->next;
			len++;
		}
		if (len <= k){
			k = len - k%len;
			while (--k)
				left = left->next;
		}
		else{
			while (right->next != NULL){
				right = right->next;
				left = left->next;
			}
		}
		right->next = phead;
		phead = left->next;
		left->next = NULL;
		return phead;
	}
};
int main(void){
	Solution answer;
	ListNode* phead = new ListNode(1);
	ListNode* p = phead;
	for (int i = 1; i < 5; ++i){
		ListNode* node = new ListNode(i + 1);
		p->next = node;
		p = p->next;
	}
//	ListNode* ans = answer.rotateRight(phead, -1);
	ListNode* ans = answer.rotateRight(phead, 5);
	while (ans != NULL){
		cout << ans->val << "->";
		ans = ans->next;
	}
	cout << endl;
	system("Pause");
	return 0;
}

