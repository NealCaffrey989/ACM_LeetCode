// [LeetCode]Kth Smallest Element in a BST.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// [LeetCode]Invert Binary Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:{13,9,20,7,11} 3
Output:11
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	int calcNodeSize(TreeNode* root){
		if (root == NULL)
			return 0;
		return 1 + calcNodeSize(root->left) + calcNodeSize(root->right);
	}
	int kthSmallest(TreeNode* root, int k) {
		if (root == NULL)
			return 0;
		TreeNode* pnext = root;
		int len = calcNodeSize(root->left);
		if (len + 1 > k)
			return kthSmallest(root->left, k);
		else if (len + 1 == k)
			return root->val;
		else
			return kthSmallest(root->right, k - len - 1);
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
	node->right = node3;
	cout << answer.kthSmallest(root, 3) << endl;
	system("Pause");
	return 0;
}

