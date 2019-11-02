#include "stdafx.h"


//Implement a data structure supporting the following operations:
//Inc(Key) - Inserts a new key with value 1. Or increments an existing key by 1.
//Key is guaranteed to be a non-empty string.
//Dec(Key) - If Key's value is 1, remove it from the data structure. Otherwise
//decrements an existing key by 1. If the key does not exist, this function does
//nothing. Key is guaranteed to be a non-empty string.
//GetMaxKey() - Returns one of the keys with maximal value. If no element exists,
//return an empty string "".
//GetMinKey() - Returns one of the keys with minimal value. If no element exists,
//return an empty string "".
//Challenge: Perform all these in O(1) time complexity.

namespace Solution2019
{
	namespace AllOoneDataStructure
	{
		class AllOne {
		private:
			struct curB {
				int value;
				unordered_set<string> keys;
			};
			list<curB> buckets;
			unordered_map<string, list<curB>::iterator> bucketOfKey;
		public:
			/** Initialize your data structure here. */
			AllOne() {

			}

			/** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
			void inc(string key) {
				if (!bucketOfKey.count(key)) {
					bucketOfKey[key] = buckets.insert(buckets.begin(), { 0, {key} });
				}

				auto curB = bucketOfKey[key];
				auto nextB = next(curB);

				if (nextB == buckets.end() || nextB->value > curB->value + 1) {
					nextB = buckets.insert(nextB, { curB->value + 1, {key} });
				}
				else {
					nextB->keys.insert(key);
				}
				bucketOfKey[key] = nextB;

				curB->keys.erase(key);
				if (curB->keys.empty()) { buckets.erase(curB); }
			}

			/** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
			void dec(string key) {
				if (!bucketOfKey.count(key)) { return; }

				auto curB = bucketOfKey[key];
				auto prevB = prev(curB);
				bucketOfKey.erase(key); ///---> Don't forget to erase the key!!!
				if (curB->value > 1) {
					if (curB == buckets.begin() || prevB->value < curB->value - 1) {
						prevB = buckets.insert(curB, { curB->value - 1, {key} });
					}
					else { prevB->keys.insert(key); }
					bucketOfKey[key] = prevB;
				}

				curB->keys.erase(key);
				if (curB->keys.empty()) {
					buckets.erase(curB);
				}
			}

			/** Returns one of the keys with maximal value. */
			string getMaxKey() {
				return buckets.empty() ? "" : *(buckets.rbegin()->keys.begin());
			}

			/** Returns one of the keys with Minimal value. */
			string getMinKey() {
				return buckets.empty() ? "" : *(buckets.begin()->keys.begin());
			}
		};
		/**
		 * Your AllOne object will be instantiated and called as such:
		 * AllOne* obj = new AllOne();
		 * obj->inc(key);
		 * obj->dec(key);
		 * string param_3 = obj->getMaxKey();
		 * string param_4 = obj->getMinKey();
		 */

		void Main() {
			AllOne* obj = new AllOne();
			obj->inc("a");
			obj->inc("b");
			obj->inc("b");
			obj->inc("b");
			obj->inc("b");
			obj->dec("b");
			obj->dec("b");
			string param_3 = obj->getMaxKey();
			string param_4 = obj->getMinKey();
		}
	}
}

