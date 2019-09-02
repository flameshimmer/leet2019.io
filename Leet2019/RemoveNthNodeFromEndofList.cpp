#include "stdafx.h"
//Given a linked list, remove the n-th node from the end of list and return its head.
//
//Example:
//
//Given linked list: 1->2->3->4->5, and n = 2.
//
//After removing the second node from the end, the linked list becomes 1->2->3->5.
//Note:
//
//Given n will always be valid.
//
//Follow up:
//
//Could you do this in one pass?
namespace Solution2019
{
	namespace RemoveNthNodeFromEndofList
	{
		ListNode* RemoveNthNodeFromEndofList(ListNode* head, int n) {
			if (!head) { return head; }

			ListNode* dummy = new ListNode(0);
			dummy->next = head;
			ListNode* front = dummy;
			for (int i = 0; i < n; i++) {
				front = front->next;
			}
			ListNode* back = dummy;
			while (front->next) {
				front = front->next;
				back = back->next;
			}
			ListNode* tmp = back->next;
			back->next = back->next->next;
			delete tmp;

			tmp = dummy->next;
			delete dummy;
			return tmp;
		}


		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

