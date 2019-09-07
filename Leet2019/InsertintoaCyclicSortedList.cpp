#include "stdafx.h"
//Given a node from a cyclic linked list which is sorted in ascending order, 
//write a function to insert a value into the list such that it remains a 
//cyclic sorted list. The given node can be a reference to any single node
//in the list, and may not be necessarily the smallest value in the cyclic list.
//
//If there are multiple suitable places for insertion, you may choose any
//place to insert the new value. After the insertion, the cyclic list should remain sorted.
//
//If the list is empty (i.e., given node is null), you should create a new 
//single cyclic list and return the reference to that single node. 
//Otherwise, you should return the original given node.
//
//The following example may help you understand the problem better:
//
//In the figure above, there is a cyclic sorted list of three elements. 
//You are given a reference to the node with value 3, and we need to 
//insert 2 into the list.
//
//The new node should insert between node 1 and node 3. After the 
//insertion, the list should look like this, and we should still return node 3.

namespace Solution2019
{
	namespace InsertintoaCyclicSortedList
	{
		class Node {
		public:
			int val;
			Node* next;

			Node() {}

			Node(int _val, Node* _next) {
				val = _val;
				next = _next;
			}
		};

		Node* insert(Node* head, int insertVal) {
			Node* newNode = new Node(insertVal, nullptr);
			if (!head) {
				newNode->next = newNode;
				return newNode;
			}
			Node* cur = head;
			while (cur->next != head) {
				if (cur->val <= insertVal && cur->next->val >= insertVal) { break; }
				if ((insertVal >= cur->val || insertVal <= cur->next->val) && cur->val > cur->next->val) { break; }
				cur = cur->next;
			}
			cur->next = newNode;
			newNode->next = head;
			return head;
		}

		void Main() {
			Node* head = new Node(3, nullptr);
			Node* n2 = new Node(3, nullptr);
			Node* n3 = new Node(3, nullptr);
			head->next = n2;
			n2->next = n3;
			n3->next = head;
			insert(head, 0);
		}
	}
}

