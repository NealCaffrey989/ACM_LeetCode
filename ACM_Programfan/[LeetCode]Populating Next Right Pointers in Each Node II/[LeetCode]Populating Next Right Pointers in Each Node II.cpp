// [LeetCode]Populating Next Right Pointers in Each Node II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <queue>
using namespace std;
/*
Input:
1
/  \
2    3
/ \  / \
4  5  6  7
Output:
1 -> NULL
/  \
2 -> 3 -> NULL
/ \  / \
4->5->6->7 -> NULL
*/
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class Solution {
public:
	void connect(TreeLinkNode *root) {
		TreeLinkNode* prev = nullptr;
		TreeLinkNode* next = nullptr;
		while (root != NULL) {
			prev = nullptr;
			next = nullptr;
			while (root){
				if (next == nullptr) 
					next = root->left ? root->left : root->right;
				if (root->left) {
					if (prev) 
						prev->next = root->left;
					prev = root->left;
				}
				if (root->right) {
					if (prev) 
						prev->next = root->right;
					prev = root->right;
				}
				root = root->next;
			}
			root = next;
		}
	}
};
int main(void){
	Solution answer;
	TreeLinkNode *root = new TreeLinkNode(1);
	TreeLinkNode *node = new TreeLinkNode(2);
	root->left = node;
	TreeLinkNode *node1 = new TreeLinkNode(3);
	root->right = node1;
	TreeLinkNode *node2 = new TreeLinkNode(4);
	node->left = node2;
	TreeLinkNode *node3 = new TreeLinkNode(5);
	node1->right = node3;
	answer.connect(root);
	root = root->left->left;
	while (root != NULL){
		cout << root->val << " ";
		root = root->next;
	}
	cout << endl;
	system("Pause");
	return 0;
}


