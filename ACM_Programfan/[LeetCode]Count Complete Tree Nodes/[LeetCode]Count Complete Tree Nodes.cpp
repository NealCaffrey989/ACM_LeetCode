// [LeetCode]Count Complete Tree Nodes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:{3,20,9,15,7}
Output:5
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	int countNodes(TreeNode* root) {
		if (root == NULL)
			return 0;
		TreeNode *left = root->left, *right = root->right;
		int leftDep = 1, rightDep = 1;
		while (left != NULL){
			leftDep++;
			left = left->left;
		}
		while (right != NULL){
			rightDep++;
			right = right->right;
		}
		if (leftDep == rightDep)
			return pow(2, rightDep) - 1;
		else
			return countNodes(root->left)+countNodes(root->right)+1;
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
	TreeNode *node4 = new TreeNode(6);
	node1->left = node4;
	cout << answer.countNodes(root) << endl;
	system("Pause");
	return 0;
}

