#include "stdafx.h"
//Given an array of integers, find out whether there are two distinct indices i
// and j in the array such that the absolute difference between nums[i] and nums[j] 
//is at most t and the absolute difference between iand j is at most k.
//
//Example 1:
//Input: nums = [1, 2, 3, 1], k = 3, t = 0
//Output : true
//
//Example 2 :
//Input : nums = [1, 0, 1, 1], k = 1, t = 2
//Output : true
//
//Example 3 :
//Input : nums = [1, 5, 9, 1, 5, 9], k = 2, t = 3
//Output : false

namespace Solution2019
{
	namespace ContainsDuplicateIII
	{
		bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
			set<long long> window;
			for (int i = 0; i < nums.size(); i++) {
				if (i > k) { window.erase(nums[i - k - 1]); }
				auto pos = window.lower_bound((long long)nums[i] - (long long)t);
				if (pos != window.end() && *pos - nums[i] <= t) { return true; }
				window.insert(nums[i]);
			}
			return false;
		}
		void Main() {
			vector<int> test = { 1, 5, 9, 1, 5, 9 };
			print(containsNearbyAlmostDuplicate(test, 2, 3));
		}
	}
}

