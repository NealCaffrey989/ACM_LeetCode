// [LeetCode]Linked List Cycle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
/*
Input:
Output:
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == 0)
			return false;
		ListNode *node1 = head, *node2 = head;
		while (node2){
			node2 = node2->next;
			if (!node2)
				return false;
			node1 = node1->next;
			node2 = node2->next;
			if (node2 == node1)
				return true;
		}
		return false;
	}
};
int main(void){
	Solution answer;
	ListNode* root = new ListNode(0);
	ListNode* node1 = new ListNode(1);
	root->next = node1;
	ListNode* node2 = new ListNode(2);
	node1->next = node2;
	ListNode* node3 = new ListNode(3);
	node2->next = node3;
	cout << answer.hasCycle(root) << endl;
	node3->next = node1;
	cout << answer.hasCycle(root) << endl;
	system("Pause");
	return 0;
}