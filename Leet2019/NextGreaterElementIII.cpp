#include "stdafx.h"

//Given a positive 32-bit integer n, you need to find the smallest 32-bit integer
//which has exactly the same digits existing in the integer n and is greater in
//value than n. If no such positive 32-bit integer exists, you need to return -1.
//
//Example 1:
//Input: 12
//Output: 21
// 
//
//Example 2:
//Input: 21
//Output: -1

namespace Solution2019
{
	namespace NextGreaterElementIII
	{
		bool nextPermutation(string& nums) {
			if (nums.empty()) { return false; }
			int len = nums.size();
			int i = len - 1;
			while (i - 1 >= 0 && nums[i] <= nums[i - 1]) { i--; }
			if (i == 0) { return false; }

			int j = len - 1;
			while (nums[j] <= nums[i - 1]) { j--; }
			swap(nums[i - 1], nums[j]);
			reverse(nums.begin() + i, nums.end());
			return true;
		}

		int nextGreaterElement(int n) {
			string digits = to_string(n);
			if (!nextPermutation(digits)) { return -1; }
			long long result = stoll(digits);
			return (result > INT_MAX || result <= n) ? -1 : result;
		}

		namespace Cheating {
			int nextGreaterElement(int n) {
				string digits = to_string(n);
				next_permutation(digits.begin(), digits.end());
				long long result = stoll(digits);
				return (result > INT_MAX || result <= n) ? -1 : result;
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

