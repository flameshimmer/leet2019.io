#include "stdafx.h"
//Design a data structure that supports all following 
//operations in average O(1) time.
//
//Note: Duplicate elements are allowed.
//insert(val): Inserts an item val to the collection.
//remove(val): Removes an item val from the collection 
//if present.
//getRandom: Returns a random element from current 
//collection of elements. The probability of each
//element being returned is linearly related to the
//number of same value the collection contains.
//
//Example:
//
//// Init an empty collection.
//RandomizedCollection collection = new RandomizedCollection();
//
//// Inserts 1 to the collection. Returns true as the collection did not contain 1.
//collection.insert(1);
//
//// Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
//collection.insert(1);
//
//// Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
//collection.insert(2);
//
//// getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
//collection.getRandom();
//
//// Removes 1 from the collection, returns true. Collection now contains [1,2].
//collection.remove(1);
//
//// getRandom should return 1 and 2 both equally likely.
//collection.getRandom();

namespace Solution2019
{
	namespace InsertDeleteGetRandomODuplicatesallowed
	{
		class RandomizedCollection {
		private:
			unordered_multimap<int, int> map;
			vector<int> nums;
		public:
			/** Initialize your data structure here. */
			RandomizedCollection() {

			}

			/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
			bool insert(int val) {
				bool result = (map.count(val) == 0);

				nums.push_back(val);
				map.insert({ val, nums.size() - 1 });
				return result;
			}

			/** Removes a value from the collection. Returns true if the collection contained the specified element. */
			bool remove(int val) {
				if (!map.count(val)) { return false; }


				int len = nums.size();
				auto it = map.find(val);
				int index = it->second;

				int lastVal = nums[len - 1];

				if (index != len - 1) {
					swap(nums[index], nums[len - 1]);
					auto range = map.equal_range(lastVal);
					for (auto b = range.first; b != range.second; b++) {
						if (b->second == len - 1) {
							b->second = index;
							break;
						}
					}
				}
				nums.pop_back();
				map.erase(it);

				return true;
			}

			/** Get a random element from the collection. */
			int getRandom() {
				return nums[rand() % nums.size()];
			}
		};

		void Main() {
			RandomizedCollection* obj = new RandomizedCollection();
			bool param_1 = obj->insert(1);
			bool param_2 = obj->remove(1);
			bool param_3 = obj->insert(1);
			int param_4 = obj->getRandom();
		}
	}
}

