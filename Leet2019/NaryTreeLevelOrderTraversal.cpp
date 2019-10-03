#include "stdafx.h"
//Given an n-ary tree, return the level order traversal
//of its nodes' values. (ie, from left to right, level by level).
//
//For example, given a 3-ary tree:
//We should return its level order traversal:
//[
//     [1],
//     [3,2,4],
//     [5,6]
//]
//
//Note:
//The depth of the tree is at most 1000.
//The total number of nodes is at most 5000.

namespace Solution2019
{
	namespace NaryTreeLevelOrderTraversal
	{
		vector<vector<int>> levelOrder(Node* root) {
			vector<vector<int>> result;
			if (!root) { return result; }

			queue<Node*> q;
			q.push(root);
			while (!q.empty()) {
				int sz = q.size();
				vector<int> level;
				while (sz) {
					sz--;
					Node* cur = q.front();
					q.pop();
					level.push_back(cur->val);
					for (Node* child : cur->children) { q.push(child); }
				}
				result.push_back(level);
			}
			return result;
		}

		namespace RecursiveDFS {
			void helper(Node* node, int level, vector<vector<int>>& result) {
				if (!node) { return; }
				if (result.size() < level + 1) { result.push_back({}); }
				result[level].push_back(node->val);
				for (Node* child : node->children) {
					helper(child, level + 1, result);
				}
			}

			vector<vector<int>> levelOrder(Node* root) {
				vector<vector<int>> result;
				helper(root, 0, result);
				return result;
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

