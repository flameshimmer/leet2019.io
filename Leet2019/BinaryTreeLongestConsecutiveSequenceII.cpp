#include "stdafx.h"

//Given a binary tree, you need to find the length of Longest Consecutive Path in
//Binary Tree.
//Especially, this path can be either increasing or decreasing. For example,
//[1,2,3,4] and [4,3,2,1] are both considered valid, but the path [1,2,4,3] is
//not valid. On the other hand, the path can be in the child-Parent-child order,
//where not necessarily be parent-child order.
//
//Example 1:
//Input:
//        1
//       / \
//      2   3
//Output: 2
//Explanation: The longest consecutive path is [1, 2] or [2, 1].
// 
//
//Example 2:
//Input:
//        2
//       / \
//      1   3
//Output: 3
//Explanation: The longest consecutive path is [1, 2, 3] or [3, 2, 1].
// 
//
//Note: All the values of tree nodes are in the range of [-1e7, 1e7].

namespace Solution2019
{
	namespace BinaryTreeLongestConsecutiveSequenceII
	{
		int findPath(TreeNode* node, int preVal, int diff) {
			if (!node) { return 0; }
			if (node->val == preVal + diff) {
				return 1 + max(findPath(node->left, node->val, diff), findPath(node->right, node->val, diff));
			}
			else {
				return 0;
			}
		}

		int longestConsecutive(TreeNode* root) {
			if (!root) { return 0; }

			int l1 = findPath(root->left, root->val, -1) + findPath(root->right, root->val, 1) + 1;
			int l2 = findPath(root->left, root->val, 1) + findPath(root->right, root->val, -1) + 1;
			int childMax = max(longestConsecutive(root->left), longestConsecutive(root->right));
			return max(childMax, max(l1, l2));
		}


		namespace Another {
			vector<int> helper(TreeNode* root, int& result) {
				if (!root) { return { 0, 0 }; }

				vector<int> left = helper(root->left, result);
				vector<int> right = helper(root->right, result);
				int v = root->val;
				int l = root->left ? root->left->val : v;
				int r = root->right ? root->right->val : v;

				int inc = max(v == l + 1 ? left[0] : 0, v == r + 1 ? right[0] : 0);
				int dec = max(v == l - 1 ? left[1] : 0, v == r - 1 ? right[1] : 0);
				result = max(result, inc + dec + 1);
				return { inc + 1, dec + 1 };
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

