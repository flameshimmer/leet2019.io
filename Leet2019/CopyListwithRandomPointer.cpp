#include "stdafx.h"
//A linked list is given such that each node contains an additional 
//random pointer which could point to any node in the list or null.
//
//Return a deep copy of the list.
//
//Example 1:
//Input:
//{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}
//
//Explanation:
//Node 1's value is 1, both of its next and random pointer points to Node 2.
//Node 2's value is 2, its next pointer points to null and its random pointer points to itself.
// 
//Note:
//You must return the copy of the given head as a reference to the cloned list. 

namespace Solution2019
{
	namespace CopyListwithRandomPointer
	{	
		// Definition for a Node.
		class Node {
		public:
		int val;
		Node* next;
		Node* random;

		Node() {}

		Node(int _val, Node* _next, Node* _random) {
		val = _val;
		next = _next;
		random = _random;
		}
		};
		
		Node* CopyListwithRandomPointerWithHashMap(Node* head) {
			if (!head) { return nullptr; }

			unordered_map<Node*, Node*> map;
			Node* cur = head;
			Node* prev = nullptr;

			while (cur) {
				Node* copy;
				if (map.find(cur) != map.end()) {
					copy = map[cur];
				} else {
					copy = new Node(cur->val, nullptr, nullptr);
					map.emplace(cur, copy);
				}
				
				if (prev) { prev->next = copy; }
				prev = copy;

				if (cur->random != nullptr) {
					Node* random;
					if (map.find(cur->random) != map.end()) {
						random = map[cur->random];
					}
					else {
						random = new Node(cur->random->val, nullptr, nullptr);
						map.emplace(cur->random, random);
					}
					copy->random = random;
				}
				cur = cur->next;
			}
			return map[head];
		}

		Node* CopyListwithRandomPointer(Node* head) {
			if (!head) { return nullptr; }
			
			Node* cur = head;
			while (cur) {
				Node* copy = new Node(cur->val, nullptr, nullptr);
				copy->next = cur->next;
				cur->next = copy;
				cur = cur->next->next;
			}

			cur = head;
			while (cur) {
				if (cur->random) {
					cur->next->random = cur->random->next;
				}
				cur = cur->next->next;
			}

			Node* newHead = nullptr;
			Node* newTail = nullptr;
			cur = head;
			while (cur) {
				if (!newHead) { newHead = cur->next; }
				else { newTail->next = cur->next; }
				newTail = cur->next;

				cur->next = cur->next->next;
				cur = cur->next;
			}
			return newHead;
		}


		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

