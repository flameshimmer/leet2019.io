#include "stdafx.h"

//Given a binary tree, find the length of the longest consecutive sequence path.
//The path refers to any sequence of nodes from some starting node to any node in
//the tree along the parent-child connections. The longest consecutive path need
//to be from parent to child (cannot be the reverse).
//
//Example 1:
//Input:
//   1
//    \
//     3
//    / \
//   2   4
//        \
//         5
//Output: 3
//Explanation: Longest consecutive sequence path is 3-4-5, so return 3.
//
//Example 2:
//Input:
//   2
//    \
//     3
//    / 
//   2    
//  / 
// 1
//Output: 2 
//Explanation: Longest consecutive sequence path is 2-3, not 3-2-1, so return 2.

namespace Solution2019
{
	namespace BinaryTreeLongestConsecutiveSequence
	{
		namespace TooSlow {
			void helper(TreeNode* node, int cur, int& result) {
				if (!node) { return; }
				result = max(result, cur);

				if (node->left) {
					helper(node->left, node->val + 1 == node->left->val ? cur + 1 : 1, result);
				}
				if (node->right) {
					helper(node->right, node->val + 1 == node->right->val ? cur + 1 : 1, result);
				}
			}

			int longestConsecutive(TreeNode* root) {
				int result = 0;
				helper(root, 1, result);
				return result;
			}
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

