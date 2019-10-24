#include "stdafx.h"
//Given a non-empty binary tree, find the maximum path sum.
//
//For this problem, a path is defined as any sequence of nodes from some starting
//node to any node in the tree along the parent-child connections. The path must 
//contain at least one node and does not need to go through the root.
//
//Example 1:
//Input: [1,2,3]
//
//       1
//      / \
//     2   3
//
//Output: 6
//
//Example 2:
//Input: [-10,9,20,null,null,15,7]
//
//   -10
//   / \
//  9  20
//    /  \
//   15   7
//
//Output: 42

namespace Solution2019
{
	namespace BinaryTreeMaximumPathSum
	{
		int maxToRoot(TreeNode* root, int& result) {
			if (!root) { return 0; }
			int l = max(0, maxToRoot(root->left, result));
			int r = max(0, maxToRoot(root->right, result));
			result = max(result, l + r + root->val);
			return root->val + max(l, r);
		}

		int maxPathSum(TreeNode* root) {
			int result = INT_MIN;
			maxToRoot(root, result);
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

