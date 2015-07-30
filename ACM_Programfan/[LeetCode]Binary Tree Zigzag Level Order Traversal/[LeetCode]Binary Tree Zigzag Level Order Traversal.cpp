// [LeetCode]Binary Tree Zigzag Level Order Traversal.cpp : Defines the entry point for the console application.
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
[3],
[20,9],
[15,7]
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
	void zigzagLevelOrder(vector<vector<int>>& ret, vector<TreeNode*> node){
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
			if (ret.size() % 2 == 1)
				reverse(val.begin(), val.end());
			ret.push_back(val);
			zigzagLevelOrder(ret, pNode);
		}
	}
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> ret;
		if (root == NULL)
			return ret;
		vector<TreeNode*> node;
		node.push_back(root);
		vector<int> val;
		val.push_back(root->val);
		ret.push_back(val);
		zigzagLevelOrder(ret, node);
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
	TreeNode *node2 = new TreeNode(1);
	node1->left = node2;
	TreeNode *node3 = new TreeNode(2);
	node1->right = node3;
	vector<vector<int>> ret = answer.zigzagLevelOrder(root);
	for (size_t i = 0; i < ret.size(); ++i){
		for (size_t j = 0; j < ret[i].size(); ++j)
			cout << ret[i][j] << " ";
		cout << endl;
	}
	system("Pause");
	return 0;
}

