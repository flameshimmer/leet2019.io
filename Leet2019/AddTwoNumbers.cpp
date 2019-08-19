#include "stdafx.h"

//You are given two non - empty linked lists representing two non - negative integers.
//The digits are stored in reverse order and each of their nodes contain a single digit.
//Add the two numbers and return it as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//Example:
//
//Input : (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output : 7 -> 0 -> 8
//	 Explanation : 342 + 465 = 807.

namespace Solution2019
{
	namespace AddTwoNumbers
	{
		ListNode* AddTwoNumbers(ListNode* l1, ListNode* l2) {
			if (l1 == nullptr || l2 == nullptr) { return l1 ? l1 : l2; }
			ListNode* dummy = new ListNode(0);
			ListNode* cur = dummy;

			int carry = 0;
			while (l1 != nullptr || l2 != nullptr) {
				int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
				carry = sum / 10;
				cur->next = new ListNode(sum % 10);
				cur = cur->next;
				if (l1 != nullptr) { l1 = l1->next; }
				if (l2 != nullptr) { l2 = l2->next; }				
			}
			if (carry > 0) { cur->next = new ListNode(carry); }
			ListNode* result = dummy->next;
			delete dummy;
			return result;
		}

		void Main() {

			ListNode* l1 = createList({ 5 });
			ListNode* l2 = createList({ 5 });
			print(AddTwoNumbers(l1, l2));
			
			l1 = createList({ 1, 2, 3 });
			l2 = createList({ 4, 5, 6 });
			print(AddTwoNumbers(l1, l2));

		}
	}
}

