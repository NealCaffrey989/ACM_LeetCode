// [LeetCode]Construct Binary Tree from Inorder and Postorder Traversal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Input:{ 1, 2, 3, 4, 5, 6, 7 }, { 3, 2, 5, 4, 1, 6, 7 };
Output:{ 1, 2, 3, 4, 5, 6, 7 }
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	TreeNode* buildTree(vector<int>::const_iterator ifirst, vector<int>::const_iterator ilast, vector<int>::const_iterator pfirst, vector<int>::const_iterator plast) {
		if (ifirst == ilast)
			return NULL;
		if (pfirst == plast)
			return NULL;
		plast--;
		TreeNode* root = new TreeNode(*plast);
		auto iRoot = find(ifirst, ilast, *plast);
		int leftSize = iRoot - ifirst;
		root->left = buildTree(ifirst, iRoot, pfirst, pfirst + leftSize);
		root->right = buildTree(iRoot + 1, ilast, pfirst + leftSize, plast);
		return root;
	}
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (postorder.empty() || inorder.empty() || postorder.size() != inorder.size())
			return NULL;
		return buildTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
	}
};
int main(void){
	Solution answer;
	vector<int> postorder, inorder;
	int a[] = { 3, 5, 4, 2, 7, 6, 1 }, b[] = { 3, 2, 5, 4, 1, 6, 7 };
	for (size_t i = 0; i < 7; ++i){
		postorder.push_back(a[i]);
		inorder.push_back(b[i]);
	}
	TreeNode *root = answer.buildTree(inorder, postorder);
	while (root){
		cout << root->val << " ";
		if (root->left)
			cout << root->left->val << " ";
		if (root->right)
			cout << root->right->val << " ";
		cout << endl;
		root = root->left;
	}
	system("Pause");
	return 0;
}

