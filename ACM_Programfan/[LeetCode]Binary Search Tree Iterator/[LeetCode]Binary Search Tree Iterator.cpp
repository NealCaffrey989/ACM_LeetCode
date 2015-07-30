// [LeetCode]Binary Search Tree Iterator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
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
class BSTIterator {
private:
	vector<TreeNode*> elem;
	int index;
public:
	BSTIterator(TreeNode *root) {
		treeToList(root, elem);
		index = 0;
	}
	bool hasNext() {
		return index < elem.size();
	}
	int next() {
		return elem[index++]->val;
	}
private:
	static void treeToList(TreeNode* root, vector<TreeNode*>& Elem){
		if (!root)
			return;
		BSTIterator::treeToList(root->left, Elem);
		Elem.push_back(root);
		BSTIterator::treeToList(root->right, Elem);
	}
};
int main(void){
	TreeNode *root = new TreeNode(1);
	TreeNode *node = new TreeNode(2);
	root->right = node;
	TreeNode *node1 = new TreeNode(3);
	node->left = node1;
	BSTIterator i = BSTIterator(root);
	while (i.hasNext())
		cout << i.next() << endl;
	system("Pause");
	return 0;
}