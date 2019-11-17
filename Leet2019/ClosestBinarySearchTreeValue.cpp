#include "stdafx.h"

//Given a non-empty binary search tree and a target value, find the value in the
//BST that is closest to the target.
//
//Note:
//Given target value is a floating point.
//You are guaranteed to have only one unique value in the BST that is closest to
//the target.
//
//Example:
//Input: root = [4,2,5,1,3], target = 3.714286
//    4
//   / \
//  2   5
// / \
//1   3
//Output: 4

namespace Solution2019
{
	namespace ClosestBinarySearchTreeValue
	{
		int closestValue(TreeNode* root, double target) {
			double minDiff = DBL_MAX;
			int result;
			double diff;
			while (root) {
				diff = fabs((double)(root->val) - target);
				if (diff < minDiff) {
					minDiff = diff;
					result = root->val;
				}
				if (root->val == target) { return result; }
				else if (root->val < target) { root = root->right; }
				else { root = root->left; }
			}
			return result;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

