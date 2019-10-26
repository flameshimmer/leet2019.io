#include "stdafx.h"
//Design and implement a data structure for Least Frequently Used (LFU) cache.
//It should support the following operations: get and put.
//
//get(key) - Get the value (will always be positive) of the key if the key 
//exists in the cache, otherwise return -1.
//put(key, value) - Set or insert the value if the key is not already present. 
//When the cache reaches its capacity, it should invalidate the least frequently 
//used item before inserting a new item. For the purpose of this problem, when 
//there is a tie (i.e., two or more keys that have the same frequency), the 
//least recently used key would be evicted.
//
//Note that the number of times an item is used is the number of calls to the 
//get and put functions for that item since it was inserted. This number is 
//set to zero when the item is removed. 
//
//Follow up:
//Could you do both operations in O(1) time complexity? 
//
//Example:
//
//LFUCache cache = new LFUCache(2 /* capacity */);
//
//cache.put(1, 1);
//cache.put(2, 2);
//cache.get(1);       // returns 1
//cache.put(3, 3);    // evicts key 2
//cache.get(2);       // returns -1 (not found)
//cache.get(3);       // returns 3.
//cache.put(4, 4);    // evicts key 1.
//cache.get(1);       // returns -1 (not found)
//cache.get(3);       // returns 3
//cache.get(4);       // returns 4

namespace Solution2019
{
	namespace LFUCache
	{
		class LFUCache {
			struct Node {
				int key;
				int value;
				int freq;
				list<int>::const_iterator it;
			};
			int cap;
			int min_freq;
			unordered_map<int, Node> n; // key, node
			unordered_map<int, list<int>> l; // freq, list of keys of nodes of this freq

			void touch(Node& node) {
				const int prev_freq = node.freq;
				node.freq++;

				l[prev_freq].erase(node.it);
				if (l[prev_freq].empty() && prev_freq == min_freq) {
					l.erase(prev_freq);
					min_freq++;
				}

				l[node.freq].push_front(node.key);
				node.it = l[node.freq].cbegin();
			}

		public:
			LFUCache(int capacity) {
				cap = capacity;
				min_freq = 0;
			}

			int get(int key) {
				auto it = n.find(key);
				if (it == n.end()) { return -1; }
				touch(it->second);
				return it->second.value;
			}

			void put(int key, int value) {
				if (cap == 0) { return; }

				auto it = n.find(key);
				if (it != n.cend()) {
					it->second.value = value;
					touch(it->second);
					return;
				}

				if (n.size() == cap) {
					int deletekey = l[min_freq].back();
					l[min_freq].pop_back();
					n.erase(deletekey);
				}

				min_freq = 1;
				l[1].push_front(key);
				n[key] = { key, value, 1, l[1].cbegin() };
			}
		};

		/**
		 * Your LFUCache object will be instantiated and called as such:
		 * LFUCache* obj = new LFUCache(capacity);
		 * int param_1 = obj->get(key);
		 * obj->put(key,value);
		 */
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

