// [LeetCode]Unique Binary Search Trees II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:{1,#,2,3}
Output:[1,3,2]
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<TreeNode*> generateTrees(int first, int last){
		vector<TreeNode*> roots;
		if (first > last){
			roots.push_back(NULL);
			return roots;
		}
		for (size_t i = first; i <= last; ++i){
			vector<TreeNode *> left = generateTrees(first, i - 1);
			vector<TreeNode *> right = generateTrees(i + 1, last);
			for (size_t j = 0; j < left.size(); ++j){
				for (size_t k = 0; k < right.size(); ++k){
					TreeNode* node = new TreeNode(i);
					node->left = left[j];
					node->right = right[k];
					roots.push_back(node);
				}
			}
		}
		return roots;
	}
	vector<TreeNode*> generateTrees(int n) {
		return generateTrees(1, n);
	}
};
int main(void){
	Solution answer;
	vector<TreeNode*> ret = answer.generateTrees(3);
	for (size_t i = 0; i < ret.size(); ++i){
		TreeNode* node = ret[i];
		cout << node->val << " ";
		if (node->left != NULL)
			cout << node->left->val << " ";
		else
			cout << "#" << " ";
		if (node->right != NULL)
			cout << node->right->val << " ";
		else
			cout << "#" << " ";
		cout << endl;
	}	
	system("Pause");
	return 0;
}

