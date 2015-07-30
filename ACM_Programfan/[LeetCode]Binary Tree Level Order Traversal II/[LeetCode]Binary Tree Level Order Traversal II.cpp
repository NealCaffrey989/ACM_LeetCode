// [LeetCode]Binary Tree Level Order Traversal II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Input:{3,9,20,#,#,15,7}
Output:
[
  [15,7],
  [9,20],
  [3]
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
	void levelOrderBottom(vector<vector<int>>& ret, vector<TreeNode*> node){
		vector<TreeNode*> pNode;
		vector<int> val;
		for (size_t i = 0; i < node.size(); ++i){
			if (node[i]->left != NULL){
				pNode.push_back(node[i]->left);
				val.push_back(node[i]->left->val);
			}
			if (node[i]->right != NULL){
				pNode.push_back(node[i]->right);
				val.push_back(node[i]->right->val);
			}
		}
		if (!pNode.empty()){
			ret.push_back(val);
			levelOrderBottom(ret, pNode);
		}
	}
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> ret;
		if (root == NULL)
			return ret;
		vector<TreeNode*> node;
		node.push_back(root);
		vector<int> val;
		val.push_back(root->val);
		ret.push_back(val);
		levelOrderBottom(ret, node);
		reverse(ret.begin(), ret.end());
		return ret;
	}
};
int main(void){
	Solution answer;
	TreeNode *root = new TreeNode(3);
	TreeNode *node = new TreeNode(9);
	root->left = node;
	TreeNode *node1 = new TreeNode(20);
	root->right = node1;
	TreeNode *node2 = new TreeNode(11);
	node1->left = node2;
	TreeNode *node3 = new TreeNode(15);
	node1->right = node3;
	vector<vector<int>> ret = answer.levelOrderBottom(root);
	for (size_t i = 0; i < ret.size(); ++i){
		for (size_t j = 0; j < ret[i].size(); ++j)
			cout << ret[i][j] << " ";
		cout << endl;
	}
	system("Pause");
	return 0;
}