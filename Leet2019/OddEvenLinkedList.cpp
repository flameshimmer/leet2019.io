#include "stdafx.h"
//Given a singly linked list, group all odd nodes together followed by 
//the even nodes. Please note here we are talking about the node number
//and not the value in the nodes.
//
//You should try to do it in place. The program should run in O(1) space
//complexity and O(nodes) time complexity.
//
//Example 1:
//
//Input: 1->2->3->4->5->NULL
//Output: 1->3->5->2->4->NULL
//Example 2:
//
//Input: 2->1->3->5->6->4->7->NULL
//Output: 2->3->6->7->1->5->4->NULL
//Note:
//
//The relative order inside both the even and odd groups should remain 
//as it was in the input.
//The first node is considered odd, the second node even and so on ...

namespace Solution2019
{
	namespace OddEvenLinkedList
	{
		ListNode* OddEvenLinkedList(ListNode* head) {
			if (!head || !head->next || !head->next->next) { return head; }

			ListNode* odd = nullptr;
			ListNode* oddTail = nullptr;
			ListNode* even = nullptr;
			ListNode* evenTail = nullptr;
			int i = 1;
			while (head) {
				if (i % 2 == 0) { 
					if (!even) { even = head; }
					else { evenTail->next = head; }
					evenTail = head;
				}
				if (i % 2 == 1) { 
					if (!odd) { odd = head; }
					else { oddTail->next = head; }
					oddTail = head;
				}
				head = head->next;
				i++;
			}
			if (oddTail) { oddTail->next = even; }
			if (evenTail) { evenTail->next = nullptr; }

			return odd;
		}

		ListNode* OddEvenLinkedListMoreConcise(ListNode* head) {
			if (!head || !head->next || !head->next->next) { return head; }

			ListNode* odd = head;
			ListNode* even = head->next;
			ListNode* evenHead = even;

			while (even && even->next) {
				odd->next = even->next;
				odd = odd->next;
				even->next = odd->next;
				even = even->next;
			}
			odd->next = evenHead;
			return head; 
		}

		void Main() {
			string test = "tst test test";
			print(OddEvenLinkedList(createList({1, 2, 3, 4, 5, 6, 7, 8})));
		}
	}
}

