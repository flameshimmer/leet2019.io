#include "stdafx.h"
//Given a non-negative integer represented as non-empty a singly linked list of digits, plus one to the integer.
//
//You may assume the integer do not contain any leading zero, except the number 0 itself.
//
//The digits are stored such that the most significant digit is at the head of the list.
//
//Example :
//
//Input: [1,2,3]
//Output: [1,2,4]

namespace Solution2019
{
	namespace PlusOneLinkedList
	{
		ListNode* ReverseLinkedList(ListNode* head) {
			if (!head || !head->next) { return head; }
			ListNode* cur = head;
			ListNode* next = head->next;
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

		ListNode* PlusOneLinkedList(ListNode* head) {
			if (!head) { return nullptr; }
			int carry = 1;
			ListNode* reversed = ReverseLinkedList(head);
			ListNode* cur = reversed;
			while (cur) {
				int sum = cur->val + carry;
				cur->val = sum % 10;
				carry = sum / 10;
				cur = cur->next;
			}
			if (carry) {
				head->next = new ListNode(carry);
				head = head->next;
			}
			return ReverseLinkedList(reversed);
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

