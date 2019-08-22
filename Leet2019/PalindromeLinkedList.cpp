#include "stdafx.h"

//Given a singly linked list, determine if it is a palindrome.
//
//Example 1:
//
//Input: 1->2
//Output: false
//Example 2:
//
//Input: 1->2->2->1
//Output: true
//Follow up:
//Could you do it in O(n) time and O(1) space?

namespace Solution2019
{
	namespace PalindromeLinkedList
	{
		bool PalindromeLinkedListNonFollowUp(ListNode* l) {
			
			
			stack<int> s;
			ListNode* cur = l;
			while (cur) { s.push(cur->val); cur = cur->next; }
			cur = l;
			while (cur) {
				if (cur->val != s.top()) { return false; }
				s.pop();
				cur = cur->next;
			}
			return true;
		}
		
		ListNode* ReverseLinkedList(ListNode* l) {
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
		bool IsSameLinkedList(ListNode* l1, ListNode* l2) {
			while (l1 != nullptr && l2 != nullptr) {
				if (l1->val != l2->val) { return false; }
				l1 = l1->next;
				l2 = l2->next;
			}
			return true;
		}

		bool PalindromeLinkedList(ListNode* l) {
			if (l == nullptr || l->next == nullptr) { return true; }
			ListNode* back = l;
			ListNode* front = l;
			ListNode* prev = nullptr;
			while (front && front->next) {
				front = front->next->next;
				prev = back;
				back = back->next;
			}
			prev->next = nullptr;

			ListNode* l2 = back;			
			if (front != nullptr) { l2 = l2->next; }
			
			l2 = ReverseLinkedList(l2);
			return IsSameLinkedList(l, l2);
		}
		
		void Main() {
			string test = "tst test test";
			print(PalindromeLinkedList(createList({ 1, 0, 0})));
			print(PalindromeLinkedList(createList({ 1, 2, 2, 1 })));
			print(PalindromeLinkedList(createList({ 1, 2 })));
			print(PalindromeLinkedList(createList({1})));
			print(PalindromeLinkedList(createList({ 1, 1 })));
			print(PalindromeLinkedList(createList({ 1, 0, 1 })));
			print(PalindromeLinkedList(createList({ 1, 0, 0, 0 })));
			print(PalindromeLinkedList(createList({ 1, 2 })));
		}
	}
}

