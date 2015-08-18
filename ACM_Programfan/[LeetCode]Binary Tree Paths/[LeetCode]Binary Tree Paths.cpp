// [LeetCode]Binary Tree Paths.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Input:
1
/   \
2     3
\
5
Output:["1->2->5", "1->3"]
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	void addBinaryTreePaths(vector<string>& ret, string str, TreeNode* root){
		if (str.empty())
			str += to_string(root->val);
		else
			str += "->" + to_string(root->val);
		if (root->left!=NULL)
			addBinaryTreePaths(ret, str, root->left);
		if (root->right != NULL)
			addBinaryTreePaths(ret, str, root->right);
		if (!root->left && !root->right)
			ret.push_back(str);
	}
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> ret;
		if (root == NULL)
			return ret;
		string str;
		addBinaryTreePaths(ret, str, root);
		return ret;
	}
};
int main(void){
	Solution answer;
	TreeNode *root = new TreeNode(0);
	TreeNode *node = new TreeNode(1);
	root->left = node;
	TreeNode *node1 = new TreeNode(2);
	root->right = node1;
	TreeNode *node2 = new TreeNode(3);
	node1->left = node2;
	vector<string> ret = answer.binaryTreePaths(root);
	for (size_t i = 0; i < ret.size(); ++i)
		cout << ret[i] << endl;
	system("Pause");
	return 0;
}

