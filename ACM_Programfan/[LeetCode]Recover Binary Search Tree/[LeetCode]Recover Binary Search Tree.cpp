// [LeetCode]Recover Binary Search Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
/*
Input:{1,#,2,3}
Output:true
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	void findTwoNodes(TreeNode *root, TreeNode *&n1, TreeNode *&n2, TreeNode *&prev){
		if (root == NULL) 
			return;
		findTwoNodes(root->left, n1, n2, prev);
		if (prev != NULL && prev->val > root->val){
			n2 = root;
			if (n1 == NULL)
				n1 = prev;
		}
		prev = root;
		findTwoNodes(root->right, n1, n2, prev);
	}
	void recoverTree(TreeNode *root) {
		TreeNode *n1 = NULL;
		TreeNode *n2 = NULL;
		TreeNode *prev = NULL;
		findTwoNodes(root, n1, n2, prev);
		if (n1 != NULL && n2 != NULL){
			int tmp = n2->val;
			n2->val = n1->val;
			n1->val = tmp;
		}
	}
};
	bool isValidBST(TreeNode *root) {
		if (!root)
			return true;
		if (root->left) {
			TreeNode *p = root->left;
			while (p->right)
				p = p->right;
			if (p->val >= root->val)
				return false;
		}
		if (root->right){
			TreeNode *p = root->right;
			while (p->left)
				p = p->left;
			if (p->val <= root->val)
				return false;
		}
		return isValidBST(root->left) && isValidBST(root->right);
	}
int main(void){
	Solution answer;
	TreeNode *root = new TreeNode(1);
	TreeNode *node = new TreeNode(0);
	root->left = node;
	TreeNode *node1 = new TreeNode(2);
	root->right = node1;
	TreeNode *node2 = new TreeNode(3);
	node1->left = node2;
	answer.recoverTree(root);
	cout << root->val << endl;
	cout << root->left->val << endl;
	cout << root->right->val << endl;
	system("Pause");
	return 0;
}

