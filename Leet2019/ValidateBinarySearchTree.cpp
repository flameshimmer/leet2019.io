#include "stdafx.h"
//Given a binary tree, determine if it is a valid binary search tree (BST).
//
//Assume a BST is defined as follows:
//
//The left subtree of a node contains only nodes with keys less than the node's key.
//The right subtree of a node contains only nodes with keys greater than the node's key.
//Both the left and right subtrees must also be binary search trees.
//
//Example 1:
//
//    2
//   / \
//  1   3
//
//Input: [2,1,3]
//Output: true
//
//Example 2:
//
//    5
//   / \
//  1   4
//     / \
//    3   6
//
//Input: [5,1,4,null,null,3,6]
//Output: false
//Explanation: The root node's value is 5 but its right child's value is 4.

namespace Solution2019
{
	namespace ValidateBinarySearchTree
	{
		namespace UseLongLong {
			bool helper(const TreeNode* node, const long long minV, const long long maxV) {
				if (!node) { return true; }

				if (node->val <= minV || node->val >= maxV) {
					return false;
				}

				return helper(node->left, minV, node->val)
					&& helper(node->right, node->val, maxV);
			}


			bool isValidBST(TreeNode* root) {
				return helper(root, LLONG_MIN, LLONG_MAX);
			}
		}

		namespace UseTreeNode {
			bool helper(const TreeNode* node, const TreeNode* minNode, const TreeNode* maxNode) {
				if (!node) { return true; }

				if (minNode && node->val <= minNode->val || maxNode && node->val >= maxNode->val) { return false; }

				return helper(node->left, minNode, node)
					&& helper(node->right, node, maxNode);
			}


			bool isValidBST(TreeNode* root) {
				return helper(root, nullptr, nullptr);
			}
		}

		namespace InorderTraversal {
			bool helper(TreeNode* root, TreeNode*& prev) {
				if (!root) { return true; }
				if (!helper(root->left, prev)) { return false; }

				if (prev && root->val <= prev->val) { return false; }
				prev = root;
				return helper(root->right, prev);
			}

			bool isValidBST(TreeNode* root) {
				TreeNode* prev = nullptr;
				return helper(root, prev);
			}
		}


		void Main() {
			TreeNode* root = new TreeNode(2);
			root->left = new TreeNode(1);
			root->right = new TreeNode(3);
			print(UseLongLong::isValidBST(root));
		}
	}
}

