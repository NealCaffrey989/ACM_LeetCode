// [LeetCode]Construct Binary Tree from Preorder and Inorder Traversal.cpp : Defines the entry point for the console application.
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
	TreeNode* buildTree(vector<int>::const_iterator pfirst, vector<int>::const_iterator plast, vector<int>::const_iterator ifirst, vector<int>::const_iterator ilast) {
		if (pfirst == plast)
			return NULL;
		if (ifirst == ilast)
			return NULL;
		TreeNode* root = new TreeNode(*pfirst);
		auto iRoot = find(ifirst, ilast, *pfirst);
		int leftSize = iRoot - ifirst;
		root->left = buildTree(pfirst+1, pfirst+leftSize+1, ifirst, iRoot);
		root->right = buildTree(pfirst + leftSize + 1, plast, iRoot+1, ilast);
		return root;
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty() || inorder.empty() || preorder.size() != inorder.size())
			return NULL;
		return buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
	}
};
int main(void){
	Solution answer;
	vector<int> preorder, inorder;
	int a[] = { 1, 2, 3, 4, 5, 6, 7 }, b[] = { 3, 2, 5, 4, 1, 6, 7 };
	for (size_t i = 0; i < 7; ++i){
		preorder.push_back(a[i]);
		inorder.push_back(b[i]);
	}
	TreeNode *root = answer.buildTree(preorder,inorder);
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