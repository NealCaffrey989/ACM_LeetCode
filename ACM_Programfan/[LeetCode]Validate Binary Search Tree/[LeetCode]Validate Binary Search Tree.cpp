// [LeetCode]Validate Binary Search Tree.cpp : Defines the entry point for the console application.
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
	bool isValidBST(TreeNode *root, TreeNode *&pre){
		if (root == NULL)
			return true;
		if (!isValidBST(root->left, pre))
			return false;
		if (pre != NULL && root->val <= pre->val)
			return false;
		pre = root;
		return isValidBST(root->right, pre);
	}
	bool isValidBST(TreeNode* root) {
		TreeNode* pre = NULL;
		return isValidBST(root, pre);
	}
};
/*
class Solution {
public:
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
};*/
int main(void){
	Solution answer;
	TreeNode *root = new TreeNode(1);
	TreeNode *node = new TreeNode(1);
	root->left = node;
	TreeNode *node1 = new TreeNode(3);
	root->right = node1;
	TreeNode *node2 = new TreeNode(2);
	node1->left = node2;
	cout << answer.isValidBST(root) << endl;
	system("Pause");
	return 0;
}