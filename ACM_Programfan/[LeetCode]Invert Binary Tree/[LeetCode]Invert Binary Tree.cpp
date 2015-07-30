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
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL)
			return root;
		TreeNode* phead = root, *pnode;
		pnode = phead->left;
		phead->left = phead->right;
		phead->right = pnode;
		invertTree(phead->left);
		invertTree(phead->right);
		return phead;
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
	answer.invertTree(root);
	while (root != NULL){
		cout << root->val << endl;
		root = root->right;
	}
	system("Pause");
	return 0;
}