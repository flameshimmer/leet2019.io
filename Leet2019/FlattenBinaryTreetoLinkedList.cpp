#include "stdafx.h"

//Given a binary tree, flatten it to a linked list in-place.
//For example, given the following tree:
//    1
//   / \
//  2   5
// / \   \
//3   4   6
//The flattened tree should look like:
//1
// \
//  2
//   \
//    3
//     \
//      4
//       \
//        5
//         \
//          6

namespace Solution2019
{
	namespace FlattenBinaryTreetoLinkedList
	{
		namespace Recursive {
			void helper(TreeNode* node, TreeNode*& prev) {
				if (!node) { return; }
				helper(node->right, prev);
				helper(node->left, prev);
				node->left = nullptr;
				node->right = prev;
				prev = node;
			}

			void flatten(TreeNode* root) {
				TreeNode* prev = nullptr;
				helper(root, prev);
			}
		}

		namespace Iterative {
			void flatten(TreeNode* root) {
				while (root) {
					if (root->left && root->right) {
						TreeNode* t = root->left;
						while (t->right) { t = t->right; };
						t->right = root->right;
					}
				}
				if (root->left) { root->right = root->left; }
				root->left = nullptr;
				root = root->right;
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

