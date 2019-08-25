#include "stdafx.h"
//Merge two sorted linked lists and return it as a new list.
//The new list should be made by splicing together the nodes of the first two lists.

namespace Solution2019
{
	namespace MergeTwoSortedLists
	{
		ListNode* MergeTwoSortedLists(ListNode* l1, ListNode* l2) {
			if (l1 == nullptr || l2 == nullptr) { return l1 ? l1 : l2; }

			ListNode* head =  nullptr;
			ListNode* cur = nullptr;
			while (l1 && l2) {
				bool l1Smaller = l1->val < l2->val;
				if (head == nullptr) { 
					head = l1Smaller ? l1 : l2;
					cur = head;
				}
				else {
					cur->next = l1Smaller ? l1 : l2;
					cur = cur->next;
				}
				if (l1Smaller) { l1 = l1->next; }
				else { l2 = l2->next; }
			}
			cur->next = l1 ? l1 : l2;
			return head;
		}

		void Main() {
			string test = "tst test test";
			print(MergeTwoSortedLists(createList({ 1, 2, 4 }), createList({ 1, 3, 4 })));
		}
	}
}

