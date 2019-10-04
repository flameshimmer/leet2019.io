#include "stdafx.h"
//Given an array of n positive integers and a positive 
//integer s, find the minimal length of a contiguous 
//subarray of which the sum ≥ s. If there isn't one, 
//return 0 instead.
//
//Example: 
//Input: s = 7, nums = [2,3,1,2,4,3]
//Output: 2
//Explanation: the subarray [4,3] has the minimal length 
//under the problem constraint.
//
//Follow up:
//If you have figured out the O(n) solution, try coding 
//another solution of which the time complexity is O(n log n).  

namespace Solution2019
{
	namespace MinimumSizeSubarraySum
	{
		int minSubArrayLen(int s, vector<int>& nums) {
			int len = nums.size();
			if (len == 0) { return 0; }

			int start = 0;
			int sum = 0;
			int result = INT_MAX;

			for (int end = 0; end < len; end++) {
				sum += nums[end];
				while (sum >= s) {
					result = min(result, end - start + 1);
					sum -= nums[start];
					start++;
				}
			}
			return result == INT_MAX ? 0 : result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

