#include "stdafx.h"

//Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2]
//< nums[3]....
//
//Example 1:
//Input: nums = [1, 5, 1, 1, 6, 4]
//Output: One possible answer is [1, 4, 1, 5, 1, 6].
//
//Example 2:https://leetcode.com/problems/wiggle-sort-ii/submissions/
//Input: nums = [1, 3, 2, 2, 3, 1]
//Output: One possible answer is [2, 3, 1, 3, 1, 2].
//
//Note:
//You may assume all input has valid answer.
//Follow Up:
//Can you do it in O(n) time and/or in-place with O(1) extra space?

namespace Solution2019
{
	namespace WiggleSortII
	{
		namespace ONLogN {
			void wiggleSort(vector<int>& nums) {
				vector<int> sorted(nums);
				sort(sorted.begin(), sorted.end());

				int i1 = 0; // 1st half beginning
				int i2 = (nums.size() - 1) / 2 + 1; // 2nd half beginning
				for (int i = nums.size() - 1; i >= 0; i--) {
					if (i % 2 == 1) {
						nums[i] = sorted[i2];
						i2++;
					}
					else {
						nums[i] = sorted[i1];
						i1++;
					}
				}
			}
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

