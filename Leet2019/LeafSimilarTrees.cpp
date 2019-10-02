#include "stdafx.h"
//Consider all the leaves of a binary tree.  
//From left to right order, the values of those 
//leaves form a leaf value sequence.
//
//For example, in the given tree above, the leaf 
//value sequence is (6, 7, 4, 9, 8).
//
//Two binary trees are considered leaf-similar if 
//their leaf value sequence is the same.
//
//Return true if and only if the two given trees with 
//head nodes root1 and root2 are leaf-similar.
//
//Note:
//Both of the given trees will have between 1 and 100 nodes.

namespace Solution2019
{
	namespace LeafSimilarTrees
	{
		void getLeafSequence(TreeNode* root, vector<int>& result) {
			if (!root) { return; }
			if (!root->left && !root->right) { result.push_back(root->val); }
			getLeafSequence(root->left, result);
			getLeafSequence(root->right, result);
		}
		bool leafSimilar(TreeNode* root1, TreeNode* root2) {
			vector<int> s1;
			vector<int> s2;
			getLeafSequence(root1, s1);
			getLeafSequence(root2, s2);
			return s1 == s2;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

