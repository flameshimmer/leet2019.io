#include "stdafx.h"

//Given a binary tree
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
//				1
//			   / \
//			  2   3
//			 / \   \
//			4  5    7
//After calling your function, the tree should look like :
//				1->NULL
//			   /  \
//			  2 -> 3->NULL
//			 / \    \
//			4-->5--->7->NULL
//
//Note:
//You may only use constant extra space.
//Recursive approach is fine, implicit stack space does not count as extra space
//for this problem.

namespace Solution2019
{
	namespace PopulatingNextRightPointersinEachNodeII
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

		Node* connectIterative(Node* root) {
			Node* result = root;
			Node* cur = root;
			while (cur) {
				Node* prev = nullptr;
				Node* next = nullptr;
				while (cur) {
					if (cur->left) {
						if (!prev) { prev = cur->left; }
						else { prev->next = cur->left; prev = prev->next; }
						if (!next) { next = cur->left; }
					}
					if (cur->right) {
						if (!prev) { prev = cur->right; }
						else { prev->next = cur->right; prev = prev->next; }
						if (!next) { next = cur->right; }
					}
					cur = cur->next;
				}
				cur = next;
			}
			return result;
		}

		Node* connectRecursive(Node* root) {
			if (!root) { return nullptr; }
			Node* result = root;
			Node* child = nullptr;
			if (root->left) { root->left->next = root->right; child = root->left; }
			if (root->right) { child = root->right; }

			if (child) {
				Node* cur = root->next;
				while (cur) {
					if (cur->left) { child->next = cur->left; break; }
					if (cur->right) { child->next = cur->right; break; }
					cur = cur->next;
				}
			}
			connectRecursive(root->right); // right first!
			connectRecursive(root->left);
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

