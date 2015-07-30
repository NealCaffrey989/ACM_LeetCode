// [LeetCode]Binary Tree Maximum Path Sum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
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
	int maxPathSum(TreeNode* root) {
		if (root == NULL)
			return 0;
		int maxNum = root->val;
		maxPathSum(root, maxNum);
		return maxNum;
	}
	int maxPathSum(TreeNode* root, int& maxNum) {
		if (root == NULL)
			return 0;
		int left = maxPathSum(root->left, maxNum);
		int right = maxPathSum(root->right, maxNum);
		int sum = root->val;
		if (left > 0)
			sum += left;
		if (right > 0)
			sum += right;
		if (sum > maxNum)
			maxNum = sum;
		return max(root->val, root->val + max(left, right));
	}
};
int main(void){
	Solution answer;
	TreeNode *root = new TreeNode(1);
	TreeNode *node = new TreeNode(-5);
	root->left = node;
	TreeNode *node1 = new TreeNode(3);
	root->right = node1;
	TreeNode *node2 = new TreeNode(2);
	node1->left = node2;
	TreeNode *node3 = new TreeNode(2);
	node1->right = node3;
	cout << answer.maxPathSum(root) << endl;
	system("Pause");
	return 0;
}