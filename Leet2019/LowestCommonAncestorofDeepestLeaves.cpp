#include "stdafx.h"
//Given a rooted binary tree, return the lowest common ancestor of its deepest leaves.
//
//Recall that:
//The node of a binary tree is a leaf if and only if it has no children
//The depth of the root of the tree is 0, and if the depth of a node is d, 
//the depth of each of its children is d+1.
//The lowest common ancestor of a set S of nodes is the node A with the largest 
//depth such that every node in S is in the subtree with root A.
// 
//Example 1:
//Input: root = [1,2,3]
//Output: [1,2,3]
//Explanation: 
//The deepest leaves are the nodes with values 2 and 3.
//The lowest common ancestor of these leaves is the node with value 1.
//The answer returned is a TreeNode object (not an array) with serialization "[1,2,3]".
//
//Example 2:
//Input: root = [1,2,3,4]
//Output: [4]
//
//Example 3:
//Input: root = [1,2,3,4,5]
//Output: [2,4,5]
// 
//Constraints:
//The given tree will have between 1 and 1000 nodes.
//Each node of the tree will have a distinct value between 1 and 1000.

namespace Solution2019
{
	namespace LowestCommonAncestorofDeepestLeaves
	{
		pair<TreeNode*, int> helper(TreeNode* node) {
			if (!node) { return { nullptr, 0 }; }

			pair<TreeNode*, int> left = helper(node->left);
			pair<TreeNode*, int> right = helper(node->right);
			if (left.second > right.second) {
				return { left.first, left.second + 1 };
			}
			else if (left.second < right.second) {
				return { right.first, right.second + 1 };
			}
			return { node, left.second + 1 };
		}

		TreeNode* lcaDeepestLeaves(TreeNode* root) {
			return helper(root).first;
		}

		namespace Another {
			int helper(TreeNode* node, int depth, int& deepest, TreeNode*& result) {
				deepest = max(deepest, depth);
				if (!node) { return depth; }

				int left = helper(node->left, depth + 1, deepest, result);
				int right = helper(node->right, depth + 1, deepest, result);
				if (left == deepest && right == deepest) {
					result = node;
				}
				return max(left, right);
			}

			TreeNode* lcaDeepestLeaves(TreeNode* root) {
				int deepest = 0;
				TreeNode* result = nullptr;
				helper(root, 0, deepest, result);
				return result;
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

