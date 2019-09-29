#include "stdafx.h"
//A binary tree is univalued if every node in the tree has the same value.
//
//Return true if and only if the given tree is univalued.
//
//
//Example 1:
//
//Input: [1,1,1,1,1,null,1]
//Output: true
//Example 2:
//
//Input: [2,2,2,5,2]
//Output: false
//
//Note:
//The number of nodes in the given tree will be in the range [1, 100].
//Each node's value will be an integer in the range [0, 99].

namespace Solution2019
{
	namespace UnivaluedBinaryTree
	{
		namespace Iterative {
			bool isUnivalTree(TreeNode* root) {
				if (!root) { return true; }
				int target = root->val;
				stack<TreeNode*> s;
				s.push(root);

				while (!s.empty()) {
					TreeNode* top = s.top();
					s.pop();

					if (top->val != target) { return false; }
					if (top->left) { s.push(top->left); }
					if (top->right) { s.push(top->right); }
				}
				return true;
			}
		}

		namespace Recursive {
			bool helper(TreeNode* root, int target) {
				if (!root) { return true; }
				if (root->val != target) { return false; }
				return helper(root->left, target) && helper(root->right, target);
			}

			bool isUnivalTree(TreeNode* root) {
				if (!root) { return true; }
				return helper(root, root->val);
			}
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

