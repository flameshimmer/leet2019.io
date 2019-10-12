#include "stdafx.h"
//In a binary tree, the root node is at depth 0, and 
//children of each depth k node are at depth k+1.
//
//Two nodes of a binary tree are cousins if they have 
//the same depth, but have different parents.
//
//We are given the root of a binary tree with unique 
//values, and the values x and y of two different nodes
//in the tree.
//
//Return true if and only if the nodes corresponding to 
//the values x and y are cousins.
//
//Example 1:
//Input: root = [1,2,3,4], x = 4, y = 3
//Output: false
//
//Example 2:
//Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
//Output: true
//
//Example 3:
//Input: root = [1,2,3,null,4], x = 2, y = 3
//Output: false
// 
//Note:
//The number of nodes in the tree will be between 2 and 100.
//Each node has a unique integer value from 1 to 100.
 

namespace Solution2019
{
	namespace CousinsinBinaryTree
	{
		bool isCousins(TreeNode* root, int A, int B) {
			queue<TreeNode*> q;
			q.push(root);
			while (!q.empty()) {
				int sz = q.size();
				bool foundA = false;
				bool foundB = false;
				while (sz) {
					sz--;
					TreeNode* cur = q.front();
					q.pop();
					if (cur->left && cur->right) {
						if (cur->left->val == A && cur->right->val == B) { return false; }
						if (cur->left->val == B && cur->right->val == A) { return false; }
					}
					if (!foundA && cur->val == A) { foundA = true; }
					if (!foundB && cur->val == B) { foundB = true; }
					if (foundA && foundB) { return true; }
					if (cur->left) { q.push(cur->left); }
					if (cur->right) { q.push(cur->right); }
				}
			}
			return false;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

