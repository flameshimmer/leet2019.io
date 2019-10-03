#include "stdafx.h"
//Given a binary tree, each node has value 0 or 1.  
//Each root-to-leaf path represents a binary number 
//starting with the most significant bit.  For example, 
//if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could 
//represent 01101 in binary, which is 13.
//
//For all leaves in the tree, consider the numbers 
//represented by the path from the root to that leaf.
//
//Return the sum of these numbers.
//
//Example 1:
//Input: [1,0,1,0,1,0,1]
//Output: 22
//Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
// 
//Note:
//The number of nodes in the tree is between 1 and 1000.
//node.val is 0 or 1.
//The answer will not exceed 2^31 - 1.

namespace Solution2019
{
	namespace SumofRootToLeafBinaryNumbers
	{
		int sumRootToLeaf(TreeNode* root, int sum = 0) {
			if (!root) { return 0; }
			sum = sum * 2 + root->val;
			if (!root->left && !root->right) { return sum; }
			else { return sumRootToLeaf(root->left, sum) + sumRootToLeaf(root->right, sum); }
		}

		namespace Another {
			void helper(TreeNode* node, int sum, int& result) {
				if (!node) { return; }
				sum = sum * 2 + node->val;
				if (!node->left && !node->right) {
					result += sum;
					return;
				}
				helper(node->left, sum, result);
				helper(node->right, sum, result);
			}

			int sumRootToLeaf(TreeNode* root) {
				int result = 0;
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

