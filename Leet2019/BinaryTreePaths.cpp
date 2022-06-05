#include "stdafx.h"

//Given a binary tree, return all root-to-leaf paths.
//
//Note: A leaf is a node with no children.
//
//Example:
//Input:
//   1
// /   \
//2     3
// \
//  5
//Output: ["1->2->5", "1->3"]
//Explanation: All root-to-leaf paths are: 1->2->5, 1->3

namespace Solution2019
{
	namespace BinaryTreePaths
	{
		void helper(TreeNode* node, string result, vector<string>& results) {
			if (!node) { return; }
			if (!node->left && !node->right) {
				result += to_string(node->val);
				results.push_back(result);
				return;
			}
			result += to_string(node->val) + "->";
			helper(node->left, result, results);
			helper(node->right, result, results);
		}


		vector<string> binaryTreePaths(TreeNode* root) {
			if (!root) { return {}; }
			vector<string> results;
			string result;
			helper(root, result, results);
			return results;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

