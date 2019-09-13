#include "stdafx.h"
//Given an array of integers, find if the array contains any duplicates.
//
//Your function should return true if any value appears at 
//least twice in the array, and it should return false if every element is distinct.
//
//Example 1:
//
//Input: [1,2,3,1]
//Output: true
//Example 2:
//
//Input: [1,2,3,4]
//Output: false
//Example 3:
//
//Input: [1,1,1,3,3,4,3,2,4,2]
//Output: true

namespace Solution2019
{
	namespace ContainsDuplicate
	{
		bool containsDuplicate(vector<int>& nums) {
			unordered_set<int> set;
			for (int i : nums) {
				if (set.find(i) != set.end()) { return true; }
				else { set.insert(i); }
			}
			return false;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

