#include "stdafx.h"
// 

namespace Solution2019
{
	namespace LowestCommonAncestorofaBinaryTree
	{
		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
			if (!root || !p || !q) {
				return nullptr;
			}
			if (root == p || root == q) { return root; }

			TreeNode* l = lowestCommonAncestor(root->left, p, q);
			TreeNode* r = lowestCommonAncestor(root->right, p, q);
			if (l && r) { return root; }
			else { return l ? l : r; }
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

