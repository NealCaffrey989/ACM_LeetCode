// [LeetCode]Path Sum II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Input:{3,9,2,#,#,7,7} 12
Output:
[
	[3, 9],
	[3, 2, 7]
]
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	void pathSum(TreeNode* root, vector<vector<int>>& ret, vector<int> ans, int sum) {
		ans.push_back(root->val);
		if (root->left == NULL && root->right == NULL){
			if (sum == 0)
				ret.push_back(ans);
			return ;
		}
		if (root->left != NULL)
			pathSum(root->left, ret, ans, sum - root->left->val);
		if (root->right != NULL)
			pathSum(root->right, ret, ans, sum - root->right->val);
	}
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> ret;
		if (root == NULL)
			return ret;
		vector<int> ans;
		pathSum(root, ret, ans, sum - root->val);
		return ret;
	}
};
int main(void){
	Solution answer;
	TreeNode *root = new TreeNode(-2);
	TreeNode *node = new TreeNode(-3);
	root->left = node;
	TreeNode *node1 = new TreeNode(3);
	root->right = node1;
	TreeNode *node2 = new TreeNode(1);
	node1->left = node2;
	TreeNode *node3 = new TreeNode(2);
	node2->right = node3;
	vector<vector<int>> ret = answer.pathSum(root, -5);
	for (size_t i = 0; i < ret.size(); ++i){
		for (size_t j = 0; j < ret[i].size(); ++j)
			cout << ret[i][j] << " ";
		cout << endl;
	}
	system("Pause");
	return 0;
}

