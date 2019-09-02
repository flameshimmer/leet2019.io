#include "stdafx.h"
//Given a linked list, swap every two adjacent nodes and return its head.
//
//You may not modify the values in the list's nodes, only nodes itself may be changed.
//
// 
//
//Example:
//
//Given 1->2->3->4, you should return the list as 2->1->4->3.
namespace Solution2019
{
	namespace SwapNodesinPairs
	{

		ListNode* SwapNodesinPairsRecursive(ListNode* head) {
			if (!head || !head->next) { 
				return head;
			}
			
			ListNode* next = head->next;
			ListNode* nextSectionHead = SwapNodesinPairsRecursive(next->next);
			next->next = head;
			head->next = nextSectionHead;
			return next;
		}

		ListNode* SwapNodesinPairs(ListNode* head) {
			if (!head || !head->next) { return head; }

			ListNode* result = head->next;
			ListNode* cur = head;
			ListNode* next = cur->next;
			ListNode* nN = nullptr;
			ListNode* prev = nullptr;

			while (next) {
				nN = next->next;
				next->next = cur;
				cur->next = nN;

				if (prev) { prev->next = next; }
				prev = cur;

				cur = nN;
				next = cur ? cur->next : nullptr;			
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(SwapNodesinPairs(createList({1, 2, 3, 4})));
		}
	}
}

