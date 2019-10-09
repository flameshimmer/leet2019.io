#include "stdafx.h"
//Given a Binary Search Tree and a target number, return 
//true if there exist two elements in the BST such that 
//their sum is equal to the given target.
//
//Example 1:
//
//Input: 
//    5
//   / \
//  3   6
// / \   \
//2   4   7
//
//Target = 9
//
//Output: True
// 
//
//Example 2:
//
//Input: 
//    5
//   / \
//  3   6
// / \   \
//2   4   7
//
//Target = 28
//
//Output: False

namespace Solution2019
{
	namespace TwoSumIVInputisaBST
	{
		bool findTarget(TreeNode* node, int k, unordered_set<int>& set) {
			if (!node) { return false; }
			if (set.find(k - node->val) != set.end()) { return true; }
			set.insert(node->val);
			return findTarget(node->left, k, set) || findTarget(node->right, k, set);
		}

		bool findTarget(TreeNode* root, int k) {
			unordered_set<int> set;
			return findTarget(root, k, set);
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

