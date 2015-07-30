// [LeetCode]Flatten Binary Tree to Linked List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
/*
Input:{3,9,20,#,#,15}
Output:{3,#,9,#,#,#,20,#,#,#,#,#,#,#,15}
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	void makeflatten(TreeNode* &root) {
		TreeNode* pnext = root->right;
		if (root->left != NULL){
			root->right = root->left;
			root->left = NULL;
			root = root->right;
			makeflatten(root);
		}
		if (pnext != NULL){
			root->right = pnext;
			root = root->right;
			makeflatten(root);
		}
	}
	void flatten(TreeNode* root){
		if (root == NULL)
			return;
		TreeNode* phead = root;
		makeflatten(phead);
	}
};
int main(void){
	Solution answer;
	TreeNode *root = new TreeNode(1);
	TreeNode *node = new TreeNode(2);
	root->left = node;
	TreeNode *node1 = new TreeNode(3);
	root->right = node1;
	TreeNode *node2 = new TreeNode(4);
	node->left = node2;
	TreeNode *node3 = new TreeNode(5);
	node2->right = node3;
	answer.flatten(root);
	while (root != NULL){
		cout << root->val;
		if (root->left == NULL)
			cout << endl;
		root = root->right;
	}
	system("Pause");
	return 0;
}