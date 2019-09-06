#include "stdafx.h"
//You are given a doubly linked list which in addition to the next and 
//previous pointers, it could have a child pointer, which may or may not 
//point to a separate doubly linked list. These child lists may have one
//or more children of their own, and so on, to produce a multilevel data
//structure, as shown in the example below.
//
//Flatten the list so that all the nodes appear in a single-level, doubly 
//linked list. You are given the head of the first level of the list.
//
//Example:
//Input:
// 1---2---3---4---5---6--NULL
//         |
//         7---8---9---10--NULL
//             |
//             11--12--NULL
//
//Output:
//1-2-3-7-8-11-12-9-10-4-5-6-NULL
 

namespace Solution2019
{
	namespace FlattenaMultilevelDoublyLinkedList
	{
		class Node {
		public:
			int val;
			Node* prev;
			Node* next;
			Node* child;

			Node() {}

			Node(int _val, Node* _prev, Node* _next, Node* _child) {
				val = _val;
				prev = _prev;
				next = _next;
				child = _child;
			}
		};

		Node* flattenInternal(Node* head) {
			Node* prev = nullptr;
			Node* cur = head;
			while (cur) {
				prev = cur;
				if (!cur->child) { cur = cur->next; }
				else {
					Node* next = cur->next;
					cur->next = cur->child;
					cur->child->prev = cur;
					cur->child = nullptr;

					Node* childTail = flattenInternal(cur->next);
					if (next) {
						childTail->next = next;
						next->prev = childTail;
					}
					cur = next;
				}
			}
			return prev;
		}

		Node* flatten(Node* head) {
			if (!head) { return head; }
			flatten(head);
			return head;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

