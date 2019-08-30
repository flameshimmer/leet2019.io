#include "stdafx.h"
//Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
//
//For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
//
//    1
//   / \
//  2   2
// / \ / \
//3  4 4  3
// 
//
//But the following [1,2,2,null,3,null,3] is not:
//
//    1
//   / \
//  2   2
//   \   \
//   3    3
// 
//
//Note:
//Bonus points if you could solve it both recursively and iteratively.

namespace Solution2019
{
	namespace SymmetricTree
	{
		bool isSymmetric(TreeNode* root) {
			if (!root) { return true; }
			queue<TreeNode*> q;
			q.push(root);
			q.push(root);
			while (!q.empty()) {
				TreeNode* n1 = q.front();
				q.pop();
				TreeNode* n2 = q.front();
				q.pop();
				if (!n1 && !n2) { continue; }
				if (!n1 || !n2 || n1->val != n2->val) { return false; }
				q.push(n1->left);
				q.push(n2->right);
				q.push(n1->right);
				q.push(n2->left);
			}
			return true;
		}


		bool isSymmetricInternal(TreeNode* n1, TreeNode* n2) {
			if (!n1 && !n2) { return true; }
			if (!n1 || !n2) { return false; }
			if (n1->val != n2->val) { return false; }
			return isSymmetricInternal(n1->left, n2->right) && isSymmetricInternal(n1->right, n2->left);
		}

		bool isSymmetricRecursive(TreeNode* root) {
			if (!root) { return true; }
			return isSymmetricInternal(root->left, root->right);
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

