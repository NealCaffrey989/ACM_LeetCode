// [LeetCode]Copy List with Random Pointer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
/*
Input:{-1, -1}
Output:{-1, -1}
*/
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == NULL)
			return NULL;
		if (head->next == NULL)
			return new RandomListNode(head->label);
		RandomListNode *pnode = head, *pnext = head->next;
		while (pnode != NULL){
			RandomListNode *node = new RandomListNode(pnode->label);
			node->next = pnext;
			pnode->next = node;
			pnode = pnext;
			if (pnode != NULL)
				pnext = pnode->next;
		}
		pnode = head;
		pnext = pnode->next;
		while (pnode){
			if (pnode->random != NULL)
				pnext->random = pnode->random->next;
			pnode = pnext->next;
			if (pnode)
				pnext = pnode->next;
		}
		RandomListNode *pHead = head->next;
		pnode = head;
		pnext = pHead;
		while (pnode){
			pnode->next = pnext->next;
			pnode = pnode->next;
			if (pnode){
				pnext->next = pnode->next;
				pnext = pnext->next;
			}
		}
		return pHead;
	}
};
int main(void){
	Solution answer;
	RandomListNode *root = new RandomListNode(0);
	RandomListNode *node1 = new RandomListNode(1);
	root->next = node1;
	RandomListNode *node2 = new RandomListNode(2);
	node1->next = node2;
	RandomListNode *node3 = new RandomListNode(3);
	node2->next = node3;
	root->random = node2;
	node1->random = node3;
	node3->random = node2;
	RandomListNode *newNode = answer.copyRandomList(root);
	while (root){
		cout << root->label << " ";
		if (root->random)
			cout << root->random->label;
		cout << endl;
		root = root->next;
	}
	system("Pause");
	return 0;
}