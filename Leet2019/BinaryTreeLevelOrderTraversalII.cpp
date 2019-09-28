#include "stdafx.h"
//Given a binary tree, return the bottom-up level order traversal 
//of its nodes' values. 
//(ie, from left to right, level by level from leaf to root).
//
//For example:
//Given binary tree [3,9,20,null,null,15,7],
//    3
//   / \
//  9  20
//    /  \
//   15   7
//return its bottom-up level order traversal as:
//[
//  [15,7],
//  [9,20],
//  [3]
//] 

namespace Solution2019
{
	namespace BinaryTreeLevelOrderTraversalII
	{
		vector<vector<int>> levelOrderBottom(TreeNode* root) {
			vector<vector<int>> results;
			if (!root) { return results; }

			queue<TreeNode*> q;
			q.push(root);

			while (!q.empty()) {
				int sz = q.size();
				vector<int> result;
				while (sz > 0) {
					sz--;
					TreeNode* top = q.front();
					q.pop();
					result.push_back(top->val);
					if (top->left) { q.push(top->left); }
					if (top->right) { q.push(top->right); }
				}
				results.push_back(result);
			}
			reverse(results.begin(), results.end());
			return results;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

