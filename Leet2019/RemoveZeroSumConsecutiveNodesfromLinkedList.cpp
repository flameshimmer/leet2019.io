#include "stdafx.h"
//Given the head of a linked list, we repeatedly delete consecutive
//sequences of nodes that sum to 0 until there are no such sequences.
//
//After doing so, return the head of the final linked list.  
//You may return any such answer.
//
//(Note that in the examples below, all sequences are serializations of ListNode objects.)
//
//Example 1:
//Input: head = [1,2,-3,3,1]
//Output: [3,1]
//Note: The answer [1,2,1] would also be accepted.
//
//Example 2:
//Input: head = [1,2,3,-3,4]
//Output: [1,2,4]
//
//Example 3:
//Input: head = [1,2,3,-3,-2]
//Output: [1]
// 
//Constraints:
//The given linked list will contain between 1 and 1000 nodes.
//Each node in the linked list has -1000 <= node.val <= 1000.

namespace Solution2019
{
	namespace RemoveZeroSumConsecutiveNodesfromLinkedList
	{
		ListNode* RemoveZeroSumConsecutiveNodesfromLinkedList(ListNode* head) {
			if (!head) { return head; }
			ListNode* dummy = new ListNode(0);
			dummy->next = head;
			unordered_map<int, ListNode*> map;
			ListNode* cur = dummy;
			int sum = 0;
			while (cur) {
				sum += cur->val;
				map[sum] = cur;
				cur = cur->next;
			}

			sum = 0;
			cur = dummy;
			while (cur) {
				sum += cur->val;
				cur->next = map[sum]->next;
				cur = cur->next;
			}
			ListNode* result = dummy->next;
			delete dummy;
			return result;
		}


		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

