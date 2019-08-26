#include "stdafx.h"
//Given an array and a value, remove all instances of that value in place and return the new length.
//
//The order of elements can be changed.It doesn't matter what you leave beyond the new length.

namespace Solution2019
{
	namespace RemoveElement
	{
		int removeElement(vector<int>& nums, int val) {
			int len = nums.size();
			if (len == 0) { return 0; }

			int i = -1;
			for (int j = 0; j < len; j++) {
				if (nums[j] != val) {
					i++;
					nums[i] = nums[j];
				}
			}
			return i + 1;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

