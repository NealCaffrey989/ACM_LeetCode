// [LeetCode]Binary Tree Inorder Traversal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:{1,#,2,3}
Output:[1,3,2]
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	void inorderTraversal(vector<int> &ret, TreeNode* node){
		if (node->left != NULL)
			inorderTraversal(ret, node->left);
		ret.push_back(node->val);
		if (node->right != NULL)
			inorderTraversal(ret, node->right);
	}
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ret;
		if (root == NULL)
			return ret;
		inorderTraversal(ret, root);
		return ret;
	}
};
int main(void){
	Solution answer;
	TreeNode *root = new TreeNode(1);
	TreeNode *node = new TreeNode(2);
	root->right = node;
	TreeNode *node1 = new TreeNode(3);
	node->left = node1;
	vector<int> ret = answer.inorderTraversal(root);
	for (size_t i = 0; i < ret.size(); ++i)
		cout << ret[i] << " ";
	cout << endl;
	system("Pause");
	return 0;
}
