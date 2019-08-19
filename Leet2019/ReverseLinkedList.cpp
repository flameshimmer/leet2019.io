#include "stdafx.h"

//
//Reverse a singly linked list.
//
//Example:
//
//Input : 1->2->3->4->5->NULL
//Output : 5->4->3->2->1->NULL
//		 Follow up :
//
//		A linked list can be reversed either iteratively or recursively.Could you implement both ?

namespace Solution2019
{
	namespace ReverseLinkedList
	{
		ListNode* ReverseLinkedList(ListNode* l)
		{
			if (l == nullptr || l->next == nullptr) { return l; }

			ListNode* cur = l;
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

		ListNode* ReverseLinkedListRecursive(ListNode* l) {
			if (l == nullptr || l->next == nullptr) {
				return l;
			}
			ListNode* nextTail = l->next;
			ListNode* result = ReverseLinkedList(l->next);
			nextTail->next = l;
			l->next = nullptr;
			return result;
		}

		void Main() {
			
			print(ReverseLinkedListRecursive(createList({ 1, 2, 3, 4 })));
			print(ReverseLinkedListRecursive(createList({ 1 })));
			print(ReverseLinkedListRecursive(nullptr));
		}
	}
}

