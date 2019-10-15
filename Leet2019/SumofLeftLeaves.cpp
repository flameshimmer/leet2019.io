#include "stdafx.h"
//Find the sum of all left leaves in a given binary tree.
//
//Example:
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//
//There are two left leaves in the binary tree, 
//with values 9 and 15 respectively. Return 24.

namespace Solution2019
{
	namespace SumofLeftLeaves
	{
		void helper(TreeNode* node, bool isLeft, int& sum) {
			if (!node) { return; }
			if (!node->left && !node->right && isLeft) { sum += node->val; }
			helper(node->left, true, sum);
			helper(node->right, false, sum);
		}

		int sumOfLeftLeaves(TreeNode* root) {
			int result = 0;
			helper(root, false, result);
			return result;
		}

		int sumOfLeftLeavesAnother(TreeNode* root) {
			if (!root) { return 0; }
			if (root->left && !root->left->left && !root->left->right) {
				return root->left->val + sumOfLeftLeaves(root->right);
			}
			return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

