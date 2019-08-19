#include "stdafx.h"

//
//Reverse a linked list from position m to n.Do it in one - pass.
//
//Note: 1 <= m <= n <= length of list.
//
//  Example :
//
//	  Input : 1->2->3->4->5->NULL, m = 2, n = 4
//		  Output : 1->4->3->2->5->NULL

namespace Solution2019
{
	namespace ReverseLinkedListII
	{

		ListNode* ReverseLinkedListII(ListNode* l, int m, int n)
		{
			if (l == nullptr || l->next == nullptr || m >= n) { return l; }

			ListNode* dummy = new ListNode(0);
			dummy->next = l;
			ListNode* prev = dummy;
			ListNode* cur = l;
			int counter = 1;

			while (counter < m)
			{
				prev = prev->next;
				cur = cur->next;
				counter++;
			}

			ListNode* firstSectionEnd = prev;
			ListNode* lastSectionStart = cur;
			ListNode* next = nullptr;
			while (counter <= n) 
			{
				next = cur->next;
				cur->next = prev;
				if (counter == n) { break; }
				prev = cur;
				cur = next;	
				counter++;
			}
			firstSectionEnd->next = cur;
			lastSectionStart->next = next;

			ListNode* result = dummy->next;
			delete dummy;
			return result;
		}




		void Main() {
			string test = "tst test test";
			print(ReverseLinkedListII(createList({1, 2, 3, 4, 5}), 2, 4));
		}
	}
}

