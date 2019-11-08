#include "stdafx.h"

//Given a complete binary tree, count the number of nodes.
//
//Note:
//Definition of a complete binary tree from Wikipedia:
//In a complete binary tree every level, except possibly the last, is completely
//filled, and all nodes in the last level are as far left as possible. It can
//have between 1 and 2h nodes inclusive at the last level h.
//
//Example:
//Input: 
//    1
//   / \
//  2   3
// / \  /
//4  5 6
//Output: 6 

namespace Solution2019
{
	namespace CountCompleteTreeNodes
	{
		namespace Recursion {
			// Run time: h (height of the tree=logN) + (h-1) + (h-2)...+1 
			// = O(h^2) = O(logN*logN)
			int countNodes(TreeNode* root) {
				if (!root) { return 0; }

				int leftHeight = 0;
				TreeNode* l = root;
				while (l) {
					leftHeight++;
					l = l->left;
				}

				int rightHeight = 0;
				TreeNode* r = root;
				while (r) {
					rightHeight++;
					r = r->right;
				}

				if (leftHeight == rightHeight) { return pow(2, leftHeight) - 1; }
				return 1 + countNodes(root->left) + countNodes(root->right);
			}
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

