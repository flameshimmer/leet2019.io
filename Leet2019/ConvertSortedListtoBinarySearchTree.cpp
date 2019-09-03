#include "stdafx.h"
//Given a singly linked list where elements are sorted 
//in ascending order, convert it to a height balanced BST.
//
//For this problem, a height-balanced binary tree is defined
//as a binary tree in which the depth of the two subtrees of 
//every node never differ by more than 1.
//
//Example:
//Given the sorted linked list: [-10,-3,0,5,9],
//One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
//
//      0
//     / \
//   -3   9
//   /   /
// -10  5

namespace Solution2019
{
	namespace ConvertSortedListtoBinarySearchTree
	{
		TreeNode* ConvertSortedListtoBinarySearchTreeSlow(ListNode* head) {
			if (!head) { return nullptr; }
			if (!head->next) { return new TreeNode(head->val); }

			ListNode* dummy = new ListNode(-1);
			dummy->next = head;

			ListNode* slow = dummy;
			ListNode* fast = dummy;
			while (fast->next && fast->next->next) {
				slow = slow->next;
				fast = fast->next->next;
			}
			ListNode* next = slow->next;
			slow->next = nullptr;

			TreeNode* root = new TreeNode(next->val);
			root->left = ConvertSortedListtoBinarySearchTreeSlow(head);
			root->right = ConvertSortedListtoBinarySearchTreeSlow(next->next);
			delete dummy;
			return root;
		}

		TreeNode* ConvertInternal(ListNode*& head, int start, int end) {
			if (!head || start > end) { return nullptr; }
	
			
			int mid = start + (end - start) / 2;
			TreeNode* left = ConvertInternal(head, start, mid - 1);
			TreeNode* root = new TreeNode(head->val);
			root->left = left;
			head = head->next;
			root->right = ConvertInternal(head, mid + 1, end);
			return root;
		}

		TreeNode* sortedListToBST(ListNode* head) {
			if (!head) { return nullptr; }
			
			int len = 0; 
			ListNode* cur = head;
			while (cur) { cur = cur->next; len++; }
			return ConvertInternal(head, 0, len - 1);
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

