#include "stdafx.h"
//Given a linked list, reverse the nodes of a linked 
//list k at a time and return its modified list.
//
//k is a positive integer and is less than or equal to the length of the linked list. 
//If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
//
//Example:
//
//Given this linked list: 1->2->3->4->5
//
//For k = 2, you should return: 2->1->4->3->5
//
//For k = 3, you should return: 3->2->1->4->5
//
//Note:
//
//Only constant extra memory is allowed.
//You may not alter the values in the list's nodes, only nodes itself may be changed.

namespace Solution2019
{
	namespace ReverseNodesinkGroup
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

		ListNode* reverseKGroup(ListNode* head, int n) {
			if (!head || !head->next) { return head; }
			
			ListNode* resultHead = nullptr;
			ListNode* resultTail = nullptr;
			ListNode* start = head;
			ListNode* end = head;
			ListNode* next;
			while (end) {
				int i = 0;
				while (end && i < n - 1) { end = end->next; i++; }
				if (end) {
					next = end->next;
					end->next = nullptr;
					ReverseLinkedList(start);

					if (!resultHead) { resultHead = end; }
					else { resultTail->next = end; }
					resultTail = start;

					start = next;
					end = next;					
				}			
			}
			if (!resultTail) { return head; }
			resultTail->next = start;
			return resultHead;
		}

		void Main() {			
			print(reverseKGroup(createList({1, 2, 3, 4, 5}), 2));
		}
	}
}

