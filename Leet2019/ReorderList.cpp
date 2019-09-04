#include "stdafx.h"
//Given a singly linked list L: L0→L1→…→Ln-1→Ln,
//reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
//
//You may not modify the values in the list's nodes, only nodes itself may be changed.
//
//Example 1:
//
//Given 1->2->3->4, reorder it to 1->4->2->3.
//Example 2:
//
//Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

namespace Solution2019
{
	namespace ReorderList
	{
		ListNode* ReverseLinkedList(ListNode* head) {
			if (!head || !head->next) { return head; }
			ListNode* cur = head;
			ListNode* next = cur->next;
			ListNode* nN;
			cur->next = nullptr;
			while (next) {
				nN = next->next;
				next->next = cur;
				cur = next;
				next = nN;
			}
			return cur;
		}

		ListNode* ReorderList(ListNode* head) {
			if (!head || !head->next) { return head; }
			ListNode* slow = head;
			ListNode* fast = head->next;
			while (fast->next)
			{
				slow = slow->next;
				fast = fast->next;
				if (fast->next) { fast = fast->next; }
			}
			ListNode* secondHead = slow->next;
			slow->next = nullptr;
			secondHead = ReverseLinkedList(secondHead);

			ListNode* newHead = nullptr;
			ListNode* newTail = nullptr;

			int i = 0;
			while (head && secondHead) {
				ListNode* cur;
				if (i % 2 == 0) {
					cur = head;
					head = head->next;
				} else {
					cur = secondHead;
					secondHead = secondHead->next;
				}
				if (!newHead) { newHead = cur; }
				else { newTail->next = cur; }
				newTail = cur;
				i++;
			}
			if (head || secondHead) {
				newTail->next = head ? head : secondHead;
			}
			return newHead;
		}

		void Main() {
			print(ReorderList(createList({1, 2, 3, 4, 5})));
			print(ReorderList(createList({ 1, 2, 3, 4})));
		}
	}
}

