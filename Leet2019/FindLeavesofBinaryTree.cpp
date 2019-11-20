#include "stdafx.h"

//Given a binary tree, collect a tree's nodes as if you were doing this: Collect
//and remove all leaves, repeat until the tree is empty.
// 
//
//Example:
//Input: [1,2,3,4,5]
//  
//          1
//         / \
//        2   3
//       / \     
//      4   5    
//Output: [[4,5,3],[2],[1]]
// 
//Explanation:
//1. Removing the leaves [4,5,3] would result in this tree:
//          1
//         / 
//        2          
// 
//2. Now removing the leaf [2] would result in this tree:
//          1          
// 
//3. Now removing the leaf [1] would result in the empty tree:
//          []          

namespace Solution2019
{
	namespace FindLeavesofBinaryTree
	{
		int helper(TreeNode* node, vector<vector<int>>& result) {
			if (!node) { return -1; }
			int level = max(helper(node->left, result), helper(node->right, result)) + 1;
			if (level >= result.size()) { result.push_back({}); }
			result[level].push_back(node->val);
			return level;
		}

		vector<vector<int>> findLeaves(TreeNode* root) {
			vector<vector<int>> result;
			helper(root, result);
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

