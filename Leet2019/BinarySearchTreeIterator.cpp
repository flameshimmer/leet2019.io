#include "stdafx.h"

//Implement an iterator over a binary search tree (BST). Your iterator will be
//initialized with the root node of a BST.
//Calling next() will return the next smallest number in the BST.
// 
//
//Example:
//   7
//  / \
// 3   15
//    /  \
//   9    20
//   
//BSTIterator iterator = new BSTIterator(root);
//iterator.next();    // return 3
//iterator.next();    // return 7
//iterator.hasNext(); // return true
//iterator.next();    // return 9
//iterator.hasNext(); // return true
//iterator.next();    // return 15
//iterator.hasNext(); // return true
//iterator.next();    // return 20
//iterator.hasNext(); // return false
// 
//
//Note:
//next() and hasNext() should run in average O(1) time and uses O(h) memory,
//where h is the height of the tree.
//You may assume that next() call will always be valid, that is, there will be at
//least a next smallest number in the BST when next() is called.

namespace Solution2019
{
	namespace BinarySearchTreeIterator
	{
		class BSTIterator {
			stack<TreeNode*> s;

			void pushAllLeft(TreeNode* node) {
				while (node) {
					s.push(node);
					node = node->left;
				}
			}

		public:
			BSTIterator(TreeNode* root) {
				pushAllLeft(root);
			}

			/** @return the next smallest number */
			int next() {
				TreeNode* tmp = s.top();
				s.pop();
				pushAllLeft(tmp->right);
				return tmp->val;
			}

			/** @return whether we have a next smallest number */
			bool hasNext() {
				return !s.empty();
			}
		};

		/**
		 * Your BSTIterator object will be instantiated and called as such:
		 * BSTIterator* obj = new BSTIterator(root);
		 * int param_1 = obj->next();
		 * bool param_2 = obj->hasNext();
		 */

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

