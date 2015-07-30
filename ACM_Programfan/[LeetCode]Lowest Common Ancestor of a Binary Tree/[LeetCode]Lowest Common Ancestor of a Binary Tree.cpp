// [LeetCode]Lowest Common Ancestor of a Binary Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
/*
Input:
Output:
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (nullptr == root || root == p || root == q)
			return root;
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		return !left ? right : !right ? left : root;
	}
};
int main(void){
	Solution answer;
	TreeNode *root = new TreeNode(6);
	TreeNode *node = new TreeNode(2);
	root->left = node;
	TreeNode *node1 = new TreeNode(8);
	root->right = node1;
	TreeNode *node2 = new TreeNode(7);
	node1->left = node2;
	TreeNode *node3 = new TreeNode(9);
	node1->right = node3;
	cout << answer.lowestCommonAncestor(root, node2, node3)->val << endl;
	system("Pause");
	return 0;
}