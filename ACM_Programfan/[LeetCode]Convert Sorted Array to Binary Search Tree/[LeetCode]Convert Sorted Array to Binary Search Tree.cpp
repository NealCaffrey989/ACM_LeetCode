// [LeetCode]Convert Sorted Array to Binary Search Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*
Input:{1,2,3,4,5,6}
Output:{3,1,4,2,#,5,6}
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums, int first, int last) {
		if (first > last)
			return NULL;
		int mid = first + (last - first) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = sortedArrayToBST(nums, first, mid - 1);
		root->right = sortedArrayToBST(nums, mid + 1, last);
		return root;
	}
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.empty())
			return NULL;
		return sortedArrayToBST(nums, 0, nums.size()-1);
	}
};
int main(void){
	Solution answer;
	vector<int> nums;
	int a[] = { 1, 2, 3, 4, 5, 6, 7 };
	for (size_t i = 0; i < 7; ++i)
		nums.push_back(a[i]);
	TreeNode* ret=answer.sortedArrayToBST(nums);
	while (ret != NULL){
		cout << ret->val << " ";
		if (ret->left != NULL)
			cout << ret->left->val << " ";
		if (ret->right != NULL)
			cout << ret->right->val << " ";
		cout << endl;
		ret = ret->right;
	}
	system("Pause");
	return 0;
}

