// [LeetCode]Delete Node in a Linked List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
/*
Input:1-2-3-4 3
Output:1-2-4
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	void deleteNode(ListNode* node) {
		if (node == 0)
			return;
		node->val = node->next->val;
		ListNode *del = node->next;
		node->next = del->next;
		delete del;
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
	answer.deleteNode(node3);
	while (root){
		cout << root->val << "->";
		root = root->next;
	}
	cout << endl;
	system("Pause");
	return 0;
}