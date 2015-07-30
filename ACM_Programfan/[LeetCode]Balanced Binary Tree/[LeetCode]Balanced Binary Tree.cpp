// [LeetCode]Balanced Binary Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;
/*
Input:{3,9,20,#,#,15,7}
Output:false
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
class Solution {
public:
	bool isBalanced(TreeNode* root, int& dep) {
		if (root == NULL){
			if (dep==0)
				return true;
		}
	}
	bool isBalanced(TreeNode* root) {
		if (root == NULL)
			return true;
		int dep;
		return isBalanced(root,dep);
	}
};
*/
class Solution {
public:
	int checkBalance(TreeNode *root){
		if (root == NULL)
			return 0;
		int leftDep = checkBalance(root->left);
		if (leftDep == -1)
			return -1;
		int rightDep = checkBalance(root->right);
		if (rightDep == -1)
			return -1;
		cout << root->val << " " << leftDep << " " << rightDep << endl;
		int depdiff = abs(leftDep - rightDep);
		if (depdiff > 1)
			return -1;
		return max(leftDep, rightDep) + 1;
	}
	bool isBalanced(TreeNode *root) {
		if (checkBalance(root) == -1)
			return false;
		return true;
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
	node1->left = node2;
	TreeNode *node3 = new TreeNode(5);
	node1->right = node3;
	cout << answer.isBalanced(root) << endl;
	system("Pause");
	return 0;
}

