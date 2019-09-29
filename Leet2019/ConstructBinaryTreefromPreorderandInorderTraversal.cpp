#include "stdafx.h"
//Given preorder and inorder traversal of a tree, 
//construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree.
//
//For example, given
//
//preorder = [3,9,20,15,7]
//inorder = [9,3,15,20,7]
//Return the following binary tree:
//
//    3
//   / \
//  9  20
//    /  \
//   15   7

namespace Solution2019
{
	namespace ConstructBinaryTreefromPreorderandInorderTraversal
	{
		TreeNode* helper(vector<int>& preorder, int& rootIndex, vector<int>& inorder, int start, int end, unordered_map<int, int>& map) {
			if (start > end) { return nullptr; }

			int rootVal = preorder[rootIndex];
			TreeNode* root = new TreeNode(rootVal);
			rootIndex++;

			int i = map[rootVal];
			root->left = helper(preorder, rootIndex, inorder, start, i - 1, map);
			root->right = helper(preorder, rootIndex, inorder, i + 1, end, map);

			return root;
		}


		TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
			int len = preorder.size();
			if (len == 0) { return nullptr; }
			unordered_map<int, int> map;
			for (int i = 0; i < len; i++) {
				map[inorder[i]] = i;
			}

			int rootIndex = 0;
			return helper(preorder, rootIndex, inorder, 0, len - 1, map);
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

