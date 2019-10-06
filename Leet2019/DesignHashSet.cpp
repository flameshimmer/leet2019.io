#include "stdafx.h"
//Design a HashSet without using any built-in hash table libraries.
//
//To be specific, your design should include these functions:
//
//add(value): Insert a value into the HashSet. 
//contains(value) : Return whether the value exists in the HashSet or not.
//remove(value): Remove a value in the HashSet.
//If the value does not exist in the HashSet, do nothing.
//
//Example:
//MyHashSet hashSet = new MyHashSet();
//hashSet.add(1);         
//hashSet.add(2);         
//hashSet.contains(1);    // returns true
//hashSet.contains(3);    // returns false (not found)
//hashSet.add(2);          
//hashSet.contains(2);    // returns true
//hashSet.remove(2);          
//hashSet.contains(2);    // returns false (already removed)
//
//Note:
//All values will be in the range of [0, 1000000].
//The number of operations will be in the range of [1, 10000].
//Please do not use the built-in HashSet library.

namespace Solution2019
{
	namespace DesignHashSet
	{
		namespace DoublyLinkedList {
			class MyHashSet {
			private:
				vector<list<int>> data;
				int size = 100000;
			public:
				/** Initialize your data structure here. */
				MyHashSet() {
					data.resize(size);
				}

				void add(int key) {
					for (int i : data[key % size]) {
						if (i == key) { return; }
					}
					data[key % size].push_back(key);
				}

				void remove(int key) {
					data[key % size].remove(key);
				}

				/** Returns true if this set contains the specified element */
				bool contains(int key) {
					for (int i : data[key % size]) {
						if (i == key) { return true; }
					}
					return false;
				}
			};

			/**
			 * Your MyHashSet object will be instantiated and called as such:
			 * MyHashSet* obj = new MyHashSet();
			 * obj->add(key);
			 * obj->remove(key);
			 * bool param_3 = obj->contains(key);
			 */
		}

		namespace BigFlatArray {
			class MyHashSet {
			public:
				/** Initialize your data structure here. */
				int data[1000000];
				MyHashSet() {
					memset(data, 0, sizeof(data));
				}

				void add(int key) {
					data[key] = 1;
				}

				void remove(int key) {
					data[key] = 0;
				}

				/** Returns true if this set contains the specified element */
				bool contains(int key) {
					return data[key] == 1;
				}
			};

			/**
			 * Your MyHashSet object will be instantiated and called as such:
			 * MyHashSet* obj = new MyHashSet();
			 * obj->add(key);
			 * obj->remove(key);
			 * bool param_3 = obj->contains(key);
			 */
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

