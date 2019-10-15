#include "stdafx.h"
//Design and implement a data structure for Least Recently
//Used (LRU) cache. It should support the following 
//operations: get and put.
//
//get(key) - Get the value (will always be positive) of 
//the key if the key exists in the cache, otherwise return -1.
//put(key, value) - Set or insert the value if the key 
//is not already present. When the cache reached its capacity,
//it should invalidate the least recently used item before
//inserting a new item.
//
//The cache is initialized with a positive capacity.
//
//Follow up:
//Could you do both operations in O(1) time complexity?
//
//Example:
//LRUCache cache = new LRUCache( 2 /* capacity */ );
//cache.put(1, 1);
//cache.put(2, 2);
//cache.get(1);       // returns 1
//cache.put(3, 3);    // evicts key 2
//cache.get(2);       // returns -1 (not found)
//cache.put(4, 4);    // evicts key 1
//cache.get(1);       // returns -1 (not found)
//cache.get(3);       // returns 3
//cache.get(4);       // returns 4 

namespace Solution2019
{
	namespace LRUCache
	{
		class LRUCache {
		private:
			int m_cap;
			list<int> m_keyList;
			unordered_map<int, pair<list<int>::iterator, int>> m_map;

			void moveToFront(int key) {
				m_keyList.erase(m_map[key].first);
				m_keyList.push_front(key);
				m_map[key].first = m_keyList.begin();
			}


		public:
			LRUCache(int capacity) {
				m_cap = capacity;
			}

			int get(int key) {
				if (m_map.find(key) == m_map.end()) { return -1; }
				moveToFront(key);
				return m_map[key].second;
			}

			void put(int key, int value) {
				if (m_map.find(key) != m_map.end()) {
					m_map[key].second = value;
					moveToFront(key);
				}
				else {
					m_keyList.push_front(key);
					m_map[key] = make_pair(m_keyList.begin(), value);

					if (m_keyList.size() > m_cap) {
						m_map.erase(m_keyList.back());
						m_keyList.pop_back();
					}
				}
			}
		};

		/**
		 * Your LRUCache object will be instantiated and called as such:
		 * LRUCache* obj = new LRUCache(capacity);
		 * int param_1 = obj->get(key);
		 * obj->put(key,value);
		 */

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

