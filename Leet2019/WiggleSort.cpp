#include "stdafx.h"
//Given an unsorted array nums, reorder it in-place such 
//that nums[0] <= nums[1] >= nums[2] <= nums[3]....
//
//Example:
//
//Input: nums = [3,5,2,1,6,4]
//Output: One possible answer is [3,5,1,6,2,4]

namespace Solution2019
{
	namespace WiggleSort
	{
		void wiggleSort(vector<int>& nums) {
			int len = nums.size();
			for (int i = 1; i < len; i++) {
				if ((i % 2 == 1 && nums[i] < nums[i - 1]) || (i % 2 == 0 && nums[i] > nums[i - 1])) {
					swap(nums[i], nums[i - 1]);
				}
			}
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

