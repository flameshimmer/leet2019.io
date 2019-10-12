#include "stdafx.h"
//Given a binary search tree with non-negative values, 
//find the minimum absolute difference between values 
//of any two nodes.
//
//Example:
//
//Input:
//
//   1
//    \
//     3
//    /
//   2
//
//Output:
//1
//
//Explanation:
//The minimum absolute difference is 1, which is the 
//difference between 2 and 1 (or between 2 and 3).
//
//Note: 
//There are at least two nodes in this BST.
namespace Solution2019
{
	namespace MinimumAbsoluteDifferenceinBST
	{
		void inorderTraverse(TreeNode* node, int& lastVal, int& minDiff) {
			if (node->left) { inorderTraverse(node->left, lastVal, minDiff); }
			if (lastVal >= 0) { minDiff = min(minDiff, node->val - lastVal); }
			lastVal = node->val;
			if (node->right) { inorderTraverse(node->right, lastVal, minDiff); }
		}


		int getMinimumDifference(TreeNode* root) {
			int minDiff = INT_MAX;
			int val = -1;
			inorderTraverse(root, val, minDiff);
			return minDiff;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

