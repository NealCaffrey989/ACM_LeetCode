// [LeetCode]Sum Root to Leaf Numbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Input:{3,9,2,#,#,7,7}
Output:693
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	void sumNumbers(TreeNode* root, int sum, int& target) {
		sum = sum * 10 + root->val;
		if (root->left == NULL && root->right == NULL){
			target += sum;
			return;
		}
		if (root->left != NULL)
			sumNumbers(root->left, sum, target);
		if (root->right != NULL)
			sumNumbers(root->right, sum, target);
	}
	int sumNumbers(TreeNode* root) {
		int sum = 0;
		if (root == NULL)
			return sum;
		sumNumbers(root, 0, sum);
		return sum;
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
	node1->left = node2;
	TreeNode *node3 = new TreeNode(5);
	node2->right = node3;
	cout << answer.sumNumbers(root) << endl;
	system("Pause");
	return 0;
}

