#include "stdafx.h"
//Given inorder and postorder traversal of a tree, 
//construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree.
//
//For example, given
//
//inorder = [9,3,15,20,7]
//postorder = [9,15,7,20,3]
//Return the following binary tree:
//
//    3
//   / \
//  9  20
//    /  \
//   15   7

namespace Solution2019
{
	namespace ConstructBinaryTreefromInorderandPostorderTraversal
	{
		TreeNode* helper(vector<int>& postorder, int& index, vector<int>& inorder, int start, int end, unordered_map<int, int>& map) {
			if (start > end) { return nullptr; }

			int rootVal = postorder[index];
			TreeNode* newNode = new TreeNode(rootVal);
			index--;

			int i = map[rootVal];
			newNode->right = helper(postorder, index, inorder, i + 1, end, map);
			newNode->left = helper(postorder, index, inorder, start, i - 1, map);
			return newNode;
		}

		TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
			int len = inorder.size();
			int index = len - 1;
			unordered_map<int, int> map;
			for (int i = 0; i < len; i++) {
				map[inorder[i]] = i;
			}

			return helper(postorder, index, inorder, 0, len - 1, map);
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

