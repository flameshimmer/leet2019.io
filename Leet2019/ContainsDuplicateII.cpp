#include "stdafx.h"
//Given an array of integers and an integer k, find out whether
//there are two distinct indices i and j in the array such that 
//nums[i] = nums[j] and the absolute difference between i and j is at most k.
//
//Example 1:
//Input: nums = [1,2,3,1], k = 3
//Output: true
//
//Example 2:
//Input: nums = [1,0,1,1], k = 1
//Output: true
//
//Example 3:
//Input: nums = [1,2,3,1,2,3], k = 2
//Output: false
 

namespace Solution2019
{
	namespace ContainsDuplicateII
	{
		bool containsNearbyDuplicate(vector<int>& nums, int k) {
			unordered_set<int> window;
			for (int i = 0; i < nums.size(); i++) {
				if (i > k) { window.erase(nums[i - k - 1]); }
				if (window.find(nums[i]) != window.end()) { return true; }
				window.insert(nums[i]);
			}
			return false;
		}

		bool containsNearbyDuplicateWithHashMap(vector<int>& nums, int k) {
			int len = nums.size();
			if (len < 2) { return false; }

			unordered_map<int, int> map;
			for (int i = 0; i < len; i++) {
				int val = nums[i];
				if (map.find(val) != map.end() && i - map[val] <= k) { return true; }
				map[val] = i;				
			}
			return false;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

