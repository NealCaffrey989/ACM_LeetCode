// [LeetCode]Binary Tree Postorder Traversal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:{3,9,20,#,#,15,7}
Output:{3,9,20,15,7};
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	void postorderTraversal(TreeNode* root, vector<int>& ret) {
		if (root->left != NULL)
			postorderTraversal(root->left, ret);
		if (root->right != NULL)
			postorderTraversal(root->right, ret);
		ret.push_back(root->val);
	}
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ret;
		if (root == NULL)
			return ret;
		postorderTraversal(root, ret);
		return ret;
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
	node1->right = node3;
	vector<int> ret = answer.postorderTraversal(root);
	for (size_t i = 0; i < ret.size(); ++i)
		cout << ret[i] << " ";
	cout << endl;
	system("Pause");
	return 0;
}