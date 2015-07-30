// [LeetCode]Same Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
/*
Input:{1,#,2,3} {1,#,1,3}
Output:false
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL)
			return true;
		if (p&&q&&p->val == q->val)
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		return false;
	}
};
int main(void){
	Solution answer;
	TreeNode *root1 = new TreeNode(1);
	TreeNode *root2 = new TreeNode(2);
	TreeNode *node = new TreeNode(1);
	root1->left = node;
	root2->left = node;
	TreeNode *node1 = new TreeNode(3);
	root1->right = node1;
	root2->right = node1;
	TreeNode *node2 = new TreeNode(2);
	node1->left = node2;
	cout << answer.isSameTree(root1, root2) << endl;
	system("Pause");
	return 0;
}