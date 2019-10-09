#include "stdafx.h"
//Given an array where elements are sorted in ascending
//order, convert it to a height balanced BST.
//
//For this problem, a height-balanced binary tree is 
//defined as a binary tree in which the depth of the 
//two subtrees of every node never differ by more than 1.
//
//Example:
//Given the sorted array: [-10,-3,0,5,9],
//One possible answer is: [0,-3,9,-10,null,5], 
//which represents the following height balanced BST:
//
//      0
//     / \
//   -3   9
//   /   /
// -10  5

namespace Solution2019
{
	namespace ConvertSortedArraytoBinarySearchTree
	{
		TreeNode* helper(vector<int>& nums, int start, int end)
		{
			if (start > end) { return nullptr; }
			int mid = start + (end - start) / 2;
			TreeNode* newNode = new TreeNode(nums[mid]);
			newNode->left = helper(nums, start, mid - 1);
			newNode->right = helper(nums, mid + 1, end);
			return newNode;
		}

		TreeNode* sortedArrayToBST(vector<int>& nums) {
			int len = nums.size();
			return helper(nums, 0, len - 1);
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

