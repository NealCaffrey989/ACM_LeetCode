// [LeetCode]Maximum Depth of Binary Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
/*
Input:{3,9,20,#,#,15,7}
Output:3
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	void maxDepth(TreeNode* root, int depth, int& maxdepth) {
		if (maxdepth < depth)
			maxdepth = depth;
		if (root->left != NULL)
			maxDepth(root->left, depth + 1, maxdepth);
		if (root->right!=NULL)
			maxDepth(root->right, depth + 1, maxdepth);
	}
	int maxDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		int maxdepth = 1;
		maxDepth(root, maxdepth, maxdepth);
		return maxdepth;
	}
};
int main(void){
	Solution answer;
	TreeNode *root = new TreeNode(1);
	TreeNode *node = new TreeNode(2);
	root->left = node;
	TreeNode *node1 = new TreeNode(3);
	root->right = node1;
	TreeNode *node2 = new TreeNode(1);
	node1->left = node2;
	TreeNode *node3 = new TreeNode(2);
	node2->right = node3;
	cout << answer.maxDepth(root) << endl;
	system("Pause");
	return 0;
}