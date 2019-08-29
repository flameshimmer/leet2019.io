#include "stdafx.h"
//Given a sorted linked list, delete all duplicates such that each element appear only once.
//
//Example 1:
//Input: 1->1->2
//Output: 1->2
//
//Example 2:
//Input: 1->1->2->3->3
//Output: 1->2->3

namespace Solution2019
{
	namespace RemoveDuplicatesfromSortedList
	{
		ListNode* deleteDuplicates(ListNode* head) {
			if (head == nullptr || head->next == nullptr) { return head; }
			ListNode* cur = head;
			while (cur->next) {
				if (cur->val == cur->next->val) {
					ListNode* tmp = cur->next;
					cur->next = cur->next->next;
					delete tmp;
				}
				else
				{
					cur = cur->next;
				}
			}
			return head;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

