#include "stdafx.h"
//Sort a linked list using insertion sort.
//
//A graphical example of insertion sort. The partial sorted list 
//(black) initially contains only the first element in the list.
//With each iteration one element (red) is removed from the input 
//data and inserted in-place into the sorted list
// 
//Algorithm of Insertion Sort:
//
//Insertion sort iterates, consuming one input element each repetition,
//and growing a sorted output list.
//At each iteration, insertion sort removes one element from the input data, 
//finds the location it belongs within the sorted list, and inserts it there.
//It repeats until no input elements remain.
//
//Example 1:
//Input: 4->2->1->3
//Output: 1->2->3->4
//Example 2:
//
//Input: -1->5->3->4->0
//Output: -1->0->3->4->5

namespace Solution2019
{
	namespace InsertionSortList
	{
		void insert(ListNode* node, ListNode*& newHead, ListNode*& newTail) {
			if (node->val <= newHead->val) { node->next = newHead; newHead = node; return; }
			if (node->val >= newTail->val) { newTail->next = node; newTail = node; return; }
			ListNode* cur = newHead;
			while (cur->next) {
				if (cur->next->val >= node->val) {
					node->next = cur->next;
					cur->next = node;
					return;
				}
				cur = cur->next;
			}
		}


		ListNode* insertionSortList(ListNode* head) {
			if (!head || !head->next) { return head; }
			ListNode* cur = head;

			ListNode* newHead = nullptr;
			ListNode* newTail = nullptr;
			while (cur) {
				ListNode* next = cur->next;
				cur->next = nullptr;
				if (!newHead) { newHead = cur; newTail = cur; }
				else {
					insert(cur, newHead, newTail);
				}
				cur = next;
			}
			return newHead;
		}

		void Main() {
			string test = "tst test test";
			print(insertionSortList(createList({ 1, 1 })));
			print(insertionSortList(createList({4,2,1,3})));
			print(insertionSortList(createList({ -1, 5, 3, 4, 0 })));
		}
	}
}

