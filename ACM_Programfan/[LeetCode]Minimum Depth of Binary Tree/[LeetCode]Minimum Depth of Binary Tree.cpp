// [LeetCode]Minimum Depth of Binary Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;
/*
Input:{3,9,20,#,#,15,7}
Output:2
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	int minDepth(TreeNode* root, int depth, int &mindepth) {
		if (root->left == NULL && root->right == NULL){
			if (depth < mindepth)
				mindepth = depth;
			return depth;
		}
		if (root->left!=NULL)
			minDepth(root->left, depth + 1, mindepth);
		if (root->right!=NULL)
			minDepth(root->right, depth + 1, mindepth);
	}
	int minDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		int mindep = INT_MAX;
		minDepth(root, 1, mindep);
		return mindep;
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
	cout << answer.minDepth(root) << endl;
	system("Pause");
	return 0;
}

