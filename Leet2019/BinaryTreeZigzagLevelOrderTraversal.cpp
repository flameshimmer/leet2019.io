#include "stdafx.h"

//Given a binary tree, return the zigzag level order traversal of its nodes'
//values. (ie, from left to right, then right to left for the next level and
//alternate between).
//For example:
//Given binary tree [3,9,20,null,null,15,7],
//    3
//   / \
//  9  20
//    /  \
//   15   7
//return its zigzag level order traversal as:
//[
//  [3],
//  [20,9],
//  [15,7]
//]

namespace Solution2019
{
	namespace BinaryTreeZigzagLevelOrderTraversal
	{
		vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
			vector<vector<int>> results;
			if (!root) { return results; }

			queue<TreeNode*> q;
			q.push(root);

			bool ltr = true;
			while (!q.empty()) {
				int sz = q.size();
				vector<int> result(sz);
				for (int i = 0; i < sz; i++) {
					TreeNode* cur = q.front();
					q.pop();
					int index = ltr ? i : (sz - 1 - i);
					result[index] = cur->val;
					if (cur->left) { q.push(cur->left); }
					if (cur->right) { q.push(cur->right); }
				}
				ltr = !ltr;
				results.push_back(result);
			}
			return results;
		}

		namespace UseReversal {
			vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
				vector<vector<int>> results;
				if (!root) { return results; }

				queue<TreeNode*> q;
				q.push(root);
				vector<int> result;
				int level = 0;
				while (!q.empty()) {
					int sz = q.size();
					level++;
					result.clear();
					while (sz) {
						sz--;
						TreeNode* cur = q.front();
						q.pop();
						result.push_back(cur->val);
						if (cur->left) { q.push(cur->left); }
						if (cur->right) { q.push(cur->right); }
					}
					if (level % 2 == 0) { reverse(result.begin(), result.end()); }
					results.push_back(result);
				}
				return results;
			}		
		}

		void Main() {
			TreeNode* root = new TreeNode(3);
			root->left = new TreeNode(9);
			root->right = new TreeNode(20);
			print(zigzagLevelOrder(root));
		}
	}
}

