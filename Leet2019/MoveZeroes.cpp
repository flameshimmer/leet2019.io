#include "stdafx.h"
//Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
//
//Example:
//
//Input: [0, 1, 0, 3, 12]
//	Output : [1, 3, 12, 0, 0]
//	Note :
//
//	You must do this in - place without making a copy of the array.
//	Minimize the total number of operations.

namespace Solution2019
{
	namespace MoveZeroes
	{
		void moveZeroes(vector<int>& nums) {
			int len = nums.size();
			if (len < 2) { return; }
			int start = 0;
			int end = 0;
			while (end < len) {
				if (nums[end] != 0) {
					nums[start] = nums[end];
					start++;
				}
				end++;
			}
			while (start < len) { nums[start] = 0; start++; }
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

