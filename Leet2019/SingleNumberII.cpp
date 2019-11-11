#include "stdafx.h"

//Given a non-empty array of integers, every element appears three times except
//for one, which appears exactly once. Find that single one.
//
//Note:
//Your algorithm should have a linear runtime complexity. Could you implement it
//without using extra memory?
//
//Example 1:
//Input: [2,2,3,2]
//Output: 3
//
//Example 2:
//Input: [0,1,0,1,0,1,99]
//Output: 99

namespace Solution2019
{
	namespace SingleNumberII
	{
		int singleNumber(vector<int>& nums) {
			if (nums.size() == 1) { return nums[0]; }
			int result = 0;
			for (int i = 0; i < 32; i++) {
				int sum = 0;
				for (int num : nums) {
					sum += (num >> i) & 1;
				}
				sum %= 3;
				result = result | (sum << i);
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

