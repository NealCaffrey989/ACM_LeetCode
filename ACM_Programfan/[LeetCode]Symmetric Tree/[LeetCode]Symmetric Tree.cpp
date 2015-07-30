// [LeetCode]Symmetric Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
/*
Input:{1,2,2,3,#,#3}
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
	bool isSymmetric(TreeNode* p, TreeNode* q){
		if (p == NULL && q == NULL)
			return true;
		if (p&&q&&p->val == q->val)
			return isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
		return false;
	}
	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
			return true;
		return isSymmetric(root->left, root->right);
	}
};
int main(void){
	Solution answer;
	TreeNode *root = new TreeNode(1);
	TreeNode *node = new TreeNode(3);
	root->left = node;
	TreeNode *node1 = new TreeNode(3);
	root->right = node1;
	TreeNode *node2 = new TreeNode(2);
	node->left = node2;
	TreeNode *node3 = new TreeNode(3);
	node1->right = node3;
	cout << answer.isSymmetric(root) << endl;
	system("Pause");
	return 0;
}

