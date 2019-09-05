#include "stdafx.h"
//Remove all elements from a linked list of integers that have value val.
//
//Example:
//
//Input:  1->2->6->3->4->5->6, val = 6
//Output : 1->2->3->4->5

namespace Solution2019
{
	namespace RemoveLinkedListElements
	{
		ListNode* RemoveLinkedListElements(ListNode* head, int val) {
			if (!head) { return nullptr; }
			
			ListNode* dummy = new ListNode(-1);
			dummy->next = head;
			ListNode* cur = head;
			ListNode* prev = dummy;
			while (cur) {
				if (cur->val == val) {
					prev->next = cur->next;
					delete cur;
					cur = prev->next;
				}
				else {
					prev = cur;
					cur = cur->next;
				}
			}
			ListNode* result = dummy->next;
			delete dummy;
			return result;
		}

		ListNode* RemoveLinkedListElementsAnotherWay(ListNode* head, int val) {
			if (!head) { return nullptr; }

			ListNode* newHead = nullptr;
			ListNode* tail = nullptr;
			while (head) {
				if (head->val != val) {
					if (!newHead) { newHead = head; }
					else { tail->next = head; }
					tail = head;
				}
				head = head->next;
			}
			if (tail) { tail->next = nullptr; } ///-------------------> This is the one place we need to be careful about this method!
			return newHead;
		}

		void Main() {
			print(RemoveLinkedListElementsAnotherWay(createList({1,2,6,3,4,5,6}), 6));
		}
	}
}

