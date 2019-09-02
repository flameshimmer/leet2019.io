#include "stdafx.h"
#include <functional>
//Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
//
//Example:
//
//Input:
//[
//  1->4->5,
//  1->3->4,
//  2->6
//]
//Output: 1->1->2->3->4->4->5->6

namespace Solution2019
{
	namespace MergekSortedListsMergeTwoAtATime
	{
		
		ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
			if (!l1 && !l2) { return nullptr; }
			if (!l1 || !l2) { return l1 ? l1 : l2; }

			ListNode* head = nullptr;
			ListNode* tail = nullptr;
			while (l1 && l2) {
				bool v1Smaller = l1->val < l2->val;
				ListNode * target = v1Smaller ? l1 : l2;
				if (!head) { head = target; }
				else { tail->next = target; }
				tail = target;
				if (v1Smaller) { l1 = l1->next; }
				else { l2 = l2->next; }
			}
			tail->next = l1 ? l1 : l2;
			return head;
		}

		ListNode* mergeKLists(vector<ListNode*>& lists) {
			ListNode* result = nullptr;
			for (ListNode* l : lists) {
				result = mergeTwoLists(result, l);
			}
			return result;
		}

		ListNode* mergeKListsDivideAndConque(vector<ListNode*>& lists) {
			if (lists.size() == 0) { return nullptr; }
			while (lists.size() > 1) {
				ListNode* l1 = lists[0];
				ListNode* l2 = lists[1];				
				lists.erase(lists.begin(), lists.begin() + 2);
				lists.push_back(mergeTwoLists(l1, l2));
			}
			return lists[0];
		}


		void Main() {
			vector<ListNode*> lists;
			lists.push_back(createList({ 1, 4, 5 }));
			lists.push_back(createList({1, 3, 4}));
			lists.push_back(createList({ 2, 6 }));
			print(mergeKLists(lists));
		}
	}

	namespace MergekSortedLists
	{
		static bool compare(ListNode* l1, ListNode* l2) { return l1->val > l2->val; }
		
		ListNode* mergeKLists(vector<ListNode*>& lists) {
			if (lists.size() == 0) { return nullptr; }

			priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode*, ListNode*)>> q(compare);

			for (ListNode* l : lists) {
				if (l != nullptr) { q.push(l); }
			}

			ListNode* head = nullptr;
			ListNode* tail = nullptr;
			while (!q.empty()) {
				ListNode* top = q.top();
				q.pop();
				if (!head) { head = top; }
				else { tail->next = top; }
				tail = top;
				if (top->next) { q.push(top->next); }
			}
			return head;
		}

		void Main() {
			vector<ListNode*> lists;
			lists.push_back(createList({ 1, 4, 5 }));
			lists.push_back(createList({ 1, 3, 4 }));
			lists.push_back(createList({ 2, 6 }));
			print(mergeKLists(lists));
		}
	}
}

