#include "stdafx.h"
//Given a linked list and a value x, partition it such that all 
//nodes less than x come before nodes greater than or equal to x.
//
//You should preserve the original relative order of the nodes 
//in each of the two partitions.
//
//Example:
//
//Input: head = 1->4->3->2->5->2, x = 3
//Output: 1->2->2->4->3->5
namespace Solution2019
{
	namespace PartitionList
	{
		ListNode* PartitionListOneNewListOnly(ListNode* head, int x) {
			if (!head || !head->next) { return head; }

			ListNode* biggerHead = nullptr;
			ListNode* biggerTail = nullptr;
			ListNode* dummy = new ListNode(0);
			dummy->next = head;
			ListNode* prev = dummy;
			ListNode* cur = head;
			
			while (cur) {
				if (cur->val >= x) {
					prev->next = cur->next;
					if (!biggerHead) { biggerHead = cur; }
					else { biggerTail->next = cur; }
					biggerTail = cur;
				}
				else {
					prev = cur;
				}
				cur = cur->next;				
			}
			prev->next = biggerHead;
			if (biggerTail) { biggerTail->next = nullptr; } //---------------------------> need to check whethr biggerTail is nullptr before calling next!

			ListNode* result = dummy->next;
			delete dummy;
			return result;
		}
		
		ListNode* PartitionList(ListNode* head, int x) {
			if (!head || !head->next) { return head; }
			ListNode* smallHead = nullptr;
			ListNode* smallTail = nullptr;
			ListNode* bigHead = nullptr;
			ListNode* bigTail = nullptr;

			ListNode* cur = head;
			while (cur) {
				if (cur->val < x) {
					if (!smallHead) { smallHead = cur; }
					else { smallTail->next = cur; }
					smallTail = cur;
				}
				else {
					if (!bigHead) { bigHead = cur; }
					else { bigTail->next = cur; }
					bigTail = cur;
				}
				cur = cur->next;
			}
			if (smallTail) { smallTail->next = bigHead; }
			if (bigTail) { bigTail->next = nullptr; }
			return smallHead ? smallHead : bigHead;
		}

		void Main() {
			print(PartitionList(createList({1, 4, 3, 2, 5, 2}), 3));
		}
	}
}

