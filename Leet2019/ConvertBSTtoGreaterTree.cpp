#include "stdafx.h"
//Given a Binary Search Tree (BST), convert it to a Greater Tree such 
//that every key of the original BST is changed to the original key 
//plus sum of all keys greater than the original key in BST.
//
//Example:
//
//Input: The root of a Binary Search Tree like this:
//              5
//            /   \
//           2     13
//
//Output: The root of a Greater Tree like this:
//             18
//            /   \
//          20     13


namespace Solution2019
{
	namespace ConvertBSTtoGreaterTree
	{
		namespace Iterative {
			TreeNode* convertBST(TreeNode* root) {
				int sum = 0;
				stack<TreeNode*> s;

				TreeNode* cur = root;
				while (!s.empty() || cur) {
					while (cur) {
						s.push(cur);
						cur = cur->right;
					}

					cur = s.top();
					s.pop();
					sum += cur->val;
					cur->val = sum;

					cur = cur->left;
				}
				return root;
			}
		}
		namespace Recursive {
			void convert(TreeNode* node, int& sum) {
				if (!node) { return; }
				convert(node->right, sum);
				sum += node->val;
				node->val = sum;
				convert(node->left, sum);
			}

			TreeNode* convertBST(TreeNode* root) {
				int sum = 0;
				convert(root, sum);
				return root;
			}
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

