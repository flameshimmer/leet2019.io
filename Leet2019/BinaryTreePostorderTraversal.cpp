#include "stdafx.h"

//Given a binary tree, return the postorder traversal of its nodes' values.
//
//Example:
//Input: [1,null,2,3]
//   1
//    \
//     2
//    /
//   3
//Output: [3,2,1]
//Follow up: Recursive solution is trivial, could you do it iteratively? 

namespace Solution2019
{
	namespace BinaryTreePostorderTraversal
	{
		vector<int> postOrderTraversal(TreeNode* root) {
		vector<int> result;
		if (!root) { return result; }

		TreeNode* cur = root;
		stack<TreeNode*> s;
		TreeNode* prev = nullptr;
		while (!s.empty() || cur) {
			if (cur) {
				s.push(cur);
				cur = cur->left;
			}
			else {
				TreeNode* top = s.top();
				if (top->right && top->right != prev) {
					cur = top->right;
				}
				else {
					s.pop();
					result.push_back(top->val);
					prev = top;
				}
			}
		}
		return result;
	}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

