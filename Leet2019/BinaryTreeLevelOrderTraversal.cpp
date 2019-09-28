#include "stdafx.h"
//Given a binary tree, return the level order traversal of its 
//nodes' values. (ie, from left to right, level by level).
//
//For example:
//Given binary tree [3,9,20,null,null,15,7],
//    3
//   / \
//  9  20
//    /  \
//   15   7
//return its level order traversal as:
//[
//  [3],
//  [9,20],
//  [15,7]
//]

namespace Solution2019
{
	namespace BinaryTreeLevelOrderTraversal
	{
		vector<vector<int>> levelOrder(TreeNode* root) {
			vector<vector<int>> results;
			if (!root) { return results; }
			queue<TreeNode*> q;
			q.push(root);

			while (!q.empty()) {
				int sz = q.size();
				vector<int> result;
				while (sz > 0) {
					TreeNode* top = q.front();
					result.push_back(top->val);
					q.pop();
					if (top->left) { q.push(top->left); }
					if (top->right) { q.push(top->right); }
					sz--;
				}
				results.push_back(result);
			}
			return results;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

