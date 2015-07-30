// [LeetCode]Path Sum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;
/*
Input:{3,9,20,#,#,15,7} 12
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
	bool hasPathSum(TreeNode* root, int target, int sum) {
		if (root->left == NULL && root->right == NULL){
			if (sum == target)
				return true;
		}
		bool left = false, right = false;
		if (root->left != NULL)
			left = hasPathSum(root->left, target + root->left->val, sum);
		if (root->right != NULL)
			right = hasPathSum(root->right, target + root->right->val, sum);
		return left || right;
	}
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == NULL)
				return false;
		return hasPathSum(root, root->val, sum);
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
	cout << answer.hasPathSum(root, 7) << endl;
	system("Pause");
	return 0;
}