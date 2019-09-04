#include "stdafx.h"
//Sort a linked list in O(n log n) time using constant space complexity.
//
//Example 1:
//Input: 4->2->1->3
//Output: 1->2->3->4

//Example 2:
//Input: -1->5->3->4->0
//Output: -1->0->3->4->5

namespace Solution2019
{
	namespace SortList
	{
		ListNode* merge(ListNode* l1, ListNode* l2) {
			if (!l1 && !l2) { return nullptr; }
			if (!l1 || !l2) { return l1 ? l1 : l2; }

			ListNode* head = nullptr;
			ListNode* tail = nullptr;
			while (l1 && l2) {
				bool l1Smaller = l1->val < l2->val;
				ListNode* cur = l1Smaller ? l1 : l2;
				if (!head) { head = cur; }
				else { tail->next = cur; }
				tail = cur;
				if (l1Smaller) { l1 = l1->next; }
				else { l2 = l2->next; }
			}
			tail->next = l1 ? l1 : l2;
			return head;
		}

		ListNode* SortList(ListNode* head) {
			if (!head || !head->next) { return head; }

			ListNode* slow = head;
			ListNode* fast = head->next;
			while (fast && fast->next) {
				slow = slow->next;
				fast = fast->next->next;
			}
			ListNode* secondHead = slow->next;
			slow->next = nullptr;
			ListNode* left = SortList(head);
			ListNode* right = SortList(secondHead);
			ListNode* result = merge(left, right);
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(SortList(createList({4, 2, 1, 3})));
			print(SortList(createList({ -1, 5, 3, 4, 0 })));
			print(SortList(createList({ 1, 1 })));
		}
	}
}

