#include "stdafx.h"

//Given a binary array, find the maximum length of a contiguous subarray with
//equal number of 0 and 1.
//
//Example 1:
//Input: [0,1]
//Output: 2
//Explanation: [0, 1] is the longest contiguous subarray with equal number of 0
//and 1.
//
//Example 2:
//Input: [0,1,0]
//Output: 2
//Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal
//number of 0 and 1.
//
//Note: The length of the given binary array will not exceed 50,000. 

namespace Solution2019
{
	namespace ContiguousArray
	{
		int findMaxLength(vector<int>& nums) {
			int len = nums.size();
			if (len == 0) { return 0; }
			unordered_map<int, int> map;
			int sum = 0;
			int result = 0;
			for (int i = 0; i < len; i++) {
				sum += (nums[i] == 0 ? -1 : 1);
				if (sum == 0) {
					result = i + 1;
				}
				else if (map.count(sum)) {
					result = max(result, i - map[sum]); // i - (map[sum] + 1) + 1
				}
				else {
					map[sum] = i;
				}
			}
			return result;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

