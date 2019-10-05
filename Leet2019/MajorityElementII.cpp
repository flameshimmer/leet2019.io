#include "stdafx.h"
//Given an integer array of size n, find all 
//elements that appear more than ⌊ n/3 ⌋ times.
//
//Note: The algorithm should run in linear time and in O(1) space.
//
//Example 1:
//Input: [3,2,3]
//Output: [3]
//
//Example 2:
//Input: [1,1,1,3,3,2,2,2]
//Output: [1,2]

namespace Solution2019
{
	namespace MajorityElementII
	{
		vector<int> majorityElement(vector<int>& nums) {
			vector<int> result;
			int len = nums.size();
			if (len == 0) { return result; }

			int num1 = nums[0];
			int num2 = nums[0];
			int c1 = 0;
			int c2 = 0;
			for (int v : nums) {
				if (v == num1) { c1++; }
				else if (v == num2) { c2++; }
				else if (c1 == 0) { c1 = 1; num1 = v; }
				else if (c2 == 0) { c2 = 1; num2 = v; }
				else { c1--; c2--; }
			}

			c1 = 0;
			c2 = 0;
			for (int v : nums) {
				if (v == num1) { c1++; }
				else if (v == num2) { c2++; }
			}
			if (c1 > len / 3) { result.push_back(num1); }
			if (c2 > len / 3) { result.push_back(num2); }
			return result;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

