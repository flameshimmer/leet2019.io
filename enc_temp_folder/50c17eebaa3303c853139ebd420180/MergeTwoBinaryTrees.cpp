#include "stdafx.h"
//Given two binary trees and imagine that when you put one of 
//them to cover the other, some nodes of the two trees are 
//overlapped while the others are not.
//
//You need to merge them into a new binary tree. The merge 
//rule is that if two nodes overlap, then sum node values up 
//as the new value of the merged node. Otherwise, the NOT 
//null node will be used as the node of new tree.
//
//Example 1:
//
//Input: 
//	Tree 1                     Tree 2                  
//          1                         2                             
//         / \                       / \                            
//        3   2                     1   3                        
//       /                           \   \                      
//      5                             4   7                  
//Output: 
//Merged tree:
//	     3
//	    / \
//	   4   5
//	  / \   \ 
//	 5   4   7
// 
//
//Note: The merging process must start from the root nodes of both trees.

namespace Solution2019
{
	namespace MergeTwoBinaryTrees
	{
		TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
			if (!t1 || !t2) { return t1 ? t1 : t2; }

			TreeNode* newNode = new TreeNode(t1->val + t2->val);
			newNode->left = mergeTrees(t1->left, t2->left);
			newNode->right = mergeTrees(t1->right, t2->right);
			return newNode;
		}

		TreeNode* mergeTreesIterative(TreeNode* t1, TreeNode* t2) {
			if (!t1 || !t2) { return t1 ? t1 : t2; }
			stack<pair<TreeNode*, TreeNode*>> s;
			s.push({ t1, t2 });
			while (!s.empty()) {
				pair<TreeNode*, TreeNode*> top = s.top();
				s.pop();
				TreeNode* n1 = top.first;
				TreeNode* n2 = top.second;
				n1->val += n2->val;
				if (!n1->left && n2->left) { n1->left = n2->left; }
				if (!n1->right && n2->right) { n1->right = n2->right; }
				if (n1->left && n2->left) { s.push({ n1->left, n2->left }); }
				if (n1->right && n2->right) { s.push({ n1->right, n2->right }); }
			}
			return t1;
		}
		void Main() {
			vector<string> data1 = { "1", "3", "2", "5" };
			int i = 0;
			TreeNode* t1 = ReadBinaryTree(data1, i);
			//TreeNode* t2 = ReadBinaryTree({ 2, 1, 3, nullptr, 4, nullpr, 75 });
			printTree(t1);
			//mergeTreesIterative(test);
		}
	}
}

