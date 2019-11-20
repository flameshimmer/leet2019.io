#include "stdafx.h"

//You are given a perfect binary tree where all leaves are on the same level, and
//every parent has two children. The binary tree has the following definition:
//struct Node {
//  int val;
//  Node *left;
//  Node *right;
//  Node *next;
//}
//Populate each next pointer to point to its next right node. If there is no next
//right node, the next pointer should be set to NULL.
//Initially, all next pointers are set to NULL.
//
//Example:
/*
			 1
			/ \
		   2   3
		  /\   /\
		 4  5 6  7
		 (Figure A)

		 1 -> NULL
		/  \
	   2 -> 3 -> NULL
	  /\    /\
	 4->5->6->7 -> NULL
	 (Figure B)
*/
//Explanation: Given the above perfect binary tree (Figure A), your function
//should populate each next pointer to point to its next right node, just like in
//Figure B.
//
//Note:
//You may only use constant extra space.
//Recursive approach is fine, implicit stack space does not count as extra space
//for this problem. 

namespace Solution2019
{
	namespace PopulatingNextRightPointersinEachNode
	{
		class Node {
		public:
			int val;
			Node* left;
			Node* right;
			Node* next;

			Node() {}

			Node(int _val, Node* _left, Node* _right, Node* _next) {
				val = _val;
				left = _left;
				right = _right;
				next = _next;
			}
		};

		Node* connectRecursive(Node* root) {
			if (!root || !root->left || !root->right) { return root; }
			root->left->next = root->right;
			root->right->next = root->next ? root->next->left : nullptr;
			connectRecursive(root->left);
			connectRecursive(root->right);
			return root;
		}

		Node* connectIterative(Node* root) {
			if (!root) { return nullptr; }

			Node* levelStart = root; // do a backup of the root here due to return requirement
			while (levelStart->left) {
				Node* cur = levelStart;
				while (cur) {
					cur->left->next = cur->right;
					cur->right->next = cur->next ? cur->next->left : nullptr;
					cur = cur->next;
				}
				levelStart = levelStart->left; // levelStart go down a level
			}
			return root;
		}

		Node* connectBFS(Node* root) {
			if (!root) { return nullptr; }
			queue<Node*> q;
			q.push(root);
			while (!q.empty()) {
				int sz = q.size();
				Node* cur = nullptr;
				while (sz) {
					sz--;
					cur = q.front();
					q.pop();
					cur->next = q.front();
					if (cur->left) { q.push(cur->left); }
					if (cur->right) { q.push(cur->right); }
				}
				cur->next = nullptr;
			}
			return root;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

