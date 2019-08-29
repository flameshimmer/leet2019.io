#include "stdafx.h"
//Given a sorted linked list, delete all nodes that have duplicate 
//numbers, leaving only distinct numbers from the original list.
//
//Example 1:
//Input: 1->2->3->3->4->4->5
//Output: 1->2->5
//
//Example 2:
//Input: 1->1->1->2->3
//Output: 2->3

namespace Solution2019
{
	namespace RemoveDuplicatesfromSortedListII
	{
		ListNode* RemoveDuplicatesfromSortedListII(ListNode* head) {
			if (head == nullptr || head->next == nullptr) { return head; }
			ListNode* newHead = nullptr;
			ListNode* newTail = nullptr;
			ListNode* cur = head;
			while (cur) {
				int count = 1;
				while (cur->next != nullptr && cur->val == cur->next->val) {
					count++; 
					ListNode* tmp = cur;  
					cur = cur->next; 
					delete tmp; 
				}
				if (count == 1) {
					if (!newHead) { newHead = cur; newTail = newHead; }
					else { newTail->next = cur; newTail = cur; }
					cur = cur->next;
				}
				else {
					ListNode* tmp = cur;
					cur = cur->next;
					delete tmp;
				}
			}
			if (newTail) { newTail->next = nullptr; } // ----------> don't forget about this!
			return newHead;
		}

		ListNode* RemoveDuplicatesfromSortedListIISimilarToI(ListNode* head) {
			if (head == nullptr || head->next == nullptr) { return head; }
			ListNode dummy(0);
			dummy.next = head;

			ListNode* prev = &dummy;
			ListNode* cur = head;
			bool hasDup = false;
			while (cur->next) {
				if (cur->val == cur->next->val) {
					ListNode* tmp = cur->next;
					hasDup = true;
					cur->next = cur->next->next;
					delete tmp;
				}
				else if (hasDup){
					ListNode* tmp = cur;
					prev->next = cur->next;
					cur = cur->next;
					delete tmp;
					hasDup = false;
				}
				else {
					prev = cur;
					cur = cur->next;
				}
			}
			if (hasDup){ //--------------------> don't forget about this!
				ListNode* tmp = cur;
				prev->next = cur->next;
				cur = cur->next;
				delete tmp;
				hasDup = false;
			}
			return dummy.next;

		}

		void Main() {
			string test = "tst test test";
			print(RemoveDuplicatesfromSortedListII(createList({ 1, 1 })));
			print(RemoveDuplicatesfromSortedListII(createList({ 1, 1, 1, 2, 3 })));
			print(RemoveDuplicatesfromSortedListII(createList({1, 2, 3, 3, 4, 4, 5})));			
		}
	}
}

