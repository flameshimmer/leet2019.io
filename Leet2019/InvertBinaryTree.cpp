#include "stdafx.h"
//Invert a binary tree.
//
//Example:
//
//Input:
//
//     4
//   /   \
//  2     7
// / \   / \
//1   3 6   9
//Output:
//
//     4
//   /   \
//  7     2
// / \   / \
//9   6 3   1
//Trivia:
//This problem was inspired by this original tweet by Max Howell:
//
//Google: 90% of our engineers use the software you wrote (Homebrew),
//but you can’t invert a binary tree on a whiteboard so f*** off.
namespace Solution2019
{
	namespace InvertBinaryTree
	{
		TreeNode* invertTreeRecursive(TreeNode* root) {
			if (!root || (!root->left && !root->right)) { return root; }

			TreeNode* l = root->left;
			root->left = invertTreeRecursive(root->right);
			root->right = invertTreeRecursive(l);
			return root;
		}

		TreeNode* invertTreeIterative(TreeNode* root) {
			if (!root) { return nullptr; }

			queue<TreeNode*> q;
			q.push(root);
			while (!q.empty()) {
				TreeNode* cur = q.front();
				q.pop();

				TreeNode* tmp = cur->left;
				cur->left = cur->right;
				cur->right = tmp;

				if (cur->left) { q.push(cur->left); }
				if (cur->right) { q.push(cur->right); }
			}
			return root;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

