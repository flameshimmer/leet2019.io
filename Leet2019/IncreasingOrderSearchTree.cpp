#include "stdafx.h"
//Given a binary search tree, rearrange the tree in in-order so that
//the leftmost node in the tree is now the root of the tree, and 
//every node has no left child and only 1 right child.
//
//Example 1:
//Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]
//
//       5
//      / \
//    3    6
//   / \    \
//  2   4    8
// /        / \ 
//1        7   9
//
//Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
//
// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
//          \
//           6
//            \
//             7
//              \
//               8
//                \
//                 9  
//Note:
//The number of nodes in the given tree will be between 1 and 100.
//Each node will have a unique integer value from 0 to 1000.

namespace Solution2019
{
	namespace IncreasingOrderSearchTree
	{
		namespace Relinking {
			TreeNode* increasingBST(TreeNode* root, TreeNode* tail = nullptr) {
				if (!root) { return tail; }

				TreeNode* result = increasingBST(root->left, root);
				root->left = nullptr;
				root->right = increasingBST(root->right, tail);
				return result;
			}
		}

		namespace ReconstructNewTree {
			void GetInorderVal(TreeNode* root, vector<int>& result) {
				if (!root) { return; }
				GetInorderVal(root->left, result);
				result.push_back(root->val);
				GetInorderVal(root->right, result);
			}

			TreeNode* increasingBST(TreeNode* root) {
				if (!root) { return nullptr; }

				TreeNode* result = nullptr;
				TreeNode* cur = nullptr;
				vector<int> values;
				GetInorderVal(root, values);
				for (int v : values) {
					TreeNode* newNode = new TreeNode(v);
					if (!result) { result = newNode; cur = newNode; }
					else {
						cur->right = newNode;
						cur = newNode;
					}
				}
				return result;
			}
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

