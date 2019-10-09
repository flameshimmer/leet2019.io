#include "stdafx.h"
//Given an array of integers and an integer k, you need to find
//the total number of continuous subarrays whose sum equals to k.
//
//Example 1:
//Input:nums = [1,1,1], k = 2
//Output: 2
//
//Note:
//The length of the array is in range [1, 20,000].
//The range of numbers in the array is [-1000, 1000] and 
//the range of the integer k is [-1e7, 1e7].


namespace Solution2019
{
	namespace SubarraySumEqualsK
	{
		int subarraySum(vector<int>& nums, int k) {
			unordered_map<int, int> map;
			int sum = 0;
			int result = 0;
			map[0] = 1;
			for (int v : nums) {
				sum += v;
				result += map[sum - k];
				map[sum]++;
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

