#include "stdafx.h"
//Given a binary tree, return the inorder traversal of its nodes' values.
//
//Example:
//
//Input: [1,null,2,3]
//   1
//    \
//     2
//    /
//   3
//
//Output: [1,3,2]
//Follow up: Recursive solution is trivial, could you do it iteratively?

namespace Solution2019
{
	namespace BinaryTreeInorderTraversal
	{
		namespace Iterative {
			vector<int> inorderTraversal(TreeNode* root) {
				vector<int> result;
				stack<TreeNode*> s;

				TreeNode* cur = root;
				while (cur || !s.empty()) {
					while (cur) {
						s.push(cur);
						cur = cur->left;
					}
					cur = s.top();
					s.pop();
					result.push_back(cur->val);
					cur = cur->right;
				}
				return result;
			}
		}

		namespace Recursive {
			void helper(TreeNode* node, vector<int>& result) {
				if (!node) { return; }
				helper(node->left, result);
				result.push_back(node->val);
				helper(node->right, result);
			}

			vector<int> inorderTraversal(TreeNode* root) {
				vector<int> result;
				helper(root, result);
				return result;
			}
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

