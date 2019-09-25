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
				else if (n1->left && n2->left) { s.push({ n1->left, n2->left }); } //// Note this is else if!!!! Since we modified the tree in the last line
				if (!n1->right && n2->right) {n1->right = n2->right; }				
				else if (n1->right && n2->right) { s.push({ n1->right, n2->right }); }
			}
			return t1;
		}
		void Main() {
			TreeNode* n1 = new TreeNode(1);
			TreeNode* n3 = new TreeNode(3);
			TreeNode* n2 = new TreeNode(2);
			TreeNode* n5 = new TreeNode(5);
			n1->left = n3;
			n1->right = n2;
			n3->left = n5;

			TreeNode* m2 = new TreeNode(2);
			TreeNode* m1 = new TreeNode(1);
			TreeNode* m3 = new TreeNode(3);
			TreeNode* m4 = new TreeNode(4);
			TreeNode* m7 = new TreeNode(7);
			m2->left = m1;
			m1->right = m4;
			m2->right = m3;
			m3->right = m7;

			mergeTreesIterative(n1, m2);
		}
	}
}

