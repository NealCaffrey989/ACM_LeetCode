// [LeetCode]Convert Sorted List to Binary Search Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// [LeetCode]Invert Binary Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:{3,9,20,#,#,15,7}
Output:{3,20,9,15,7}
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head,int len) {
		if (len <= 0)
			return NULL;
		int mid = 1 + (len - 1) / 2, k = mid;
		ListNode* pnext = head;
		while (--k)
			pnext = pnext->next;
		TreeNode* root = new TreeNode(pnext->val);
		root->left = sortedListToBST(head, mid - 1);
		root->right = sortedListToBST(pnext->next, len - mid);
		return root;
	}
	TreeNode* sortedListToBST(ListNode* head) {
		if (head == NULL)
			return NULL;
		int len = 0;
		ListNode* pnext = head;
		while (pnext){
			len++;
			pnext = pnext->next;
		}
		pnext = head;
		return sortedListToBST(pnext, len);
	}
};
int main(void){
	Solution answer;
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	ListNode* pHead = new ListNode(1), *pNext=pHead;
	for (size_t i = 1; i < 8; ++i){
		ListNode* pNode = new ListNode(a[i]);
		pNext->next = pNode;
		pNext = pNext->next;
	}
	TreeNode *root = answer.sortedListToBST(pHead);
	while (root != NULL){
		cout << root->val << " ";
		if (root->left)
			cout << root->left->val << " ";
		if (root->right)
			cout << root->right->val << " ";
		cout<< endl;
		root = root->right;
	}
	system("Pause");
	return 0;
}

