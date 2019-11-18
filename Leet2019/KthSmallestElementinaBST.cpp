#include "stdafx.h"

//Given a binary search tree, write a function kthSmallest to find the kth
//smallest element in it.
//
//Note:
//You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
//
//Example 1:
//Input: root = [3,1,4,null,2], k = 1
//   3
//  / \
// 1   4
//  \
//   2
//Output: 1
//
//Example 2:
//Input: root = [5,3,6,2,4,null,null,1], k = 3
//       5
//      / \
//     3   6
//    / \
//   2   4
//  /
// 1
//Output: 3
//Follow up:
//What if the BST is modified (insert/delete operations) often and you need to
//find the kth smallest frequently? How would you optimize the kthSmallest
//routine? 

namespace Solution2019
{
	namespace KthSmallestElementinaBST
	{
		namespace Recursive {
			bool helper(TreeNode* node, int& k, int& result) {
				if (!node) { return false; }
				if (helper(node->left, k, result)) { return true; }
				k--;
				if (k == 0) { result = node->val; return true; }
				return helper(node->right, k, result);
			}


			int kthSmallest(TreeNode* root, int k) {
				int result = 0;
				helper(root, k, result);
				return result;
			}
		}

		namespace Iterative {
			int kthSmallest(TreeNode* root, int k) {
				if (!root) { return 0; }

				stack<TreeNode*> s;
				TreeNode* cur = root;
				int count = 0;
				while (!s.empty() || cur) {
					if (cur) {
						s.push(cur);
						cur = cur->left;
					}
					else {
						TreeNode* top = s.top();
						s.pop();
						count++;
						if (count == k) { return top->val; }
						cur = top->right;
					}
				}
				return 0;
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

