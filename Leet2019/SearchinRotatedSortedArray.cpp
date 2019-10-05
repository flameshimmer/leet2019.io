#include "stdafx.h"
//Suppose an array sorted in ascending order is 
//rotated at some pivot unknown to you beforehand.
//
//(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
//
//You are given a target value to search. If found in 
//the array return its index, otherwise return -1.
//
//You may assume no duplicate exists in the array.
//
//Your algorithm's runtime complexity must be in the order of O(log n).
//
//Example 1:
//Input: nums = [4,5,6,7,0,1,2], target = 0
//Output: 4
//
//Example 2:
//Input: nums = [4,5,6,7,0,1,2], target = 3
//Output: -1
namespace Solution2019
{
	namespace SearchinRotatedSortedArray
	{
		int search(vector<int>& nums, int target) {
			int len = nums.size();
			if (len == 0) { return -1; }

			int start = 0;
			int end = nums.size() - 1;
			while (start < end) {
				int mid = start + (end - start) / 2;
				if (nums[mid] == target) { return mid; }
				if (nums[start] <= nums[mid]) {
					if (nums[start] <= target && target < nums[mid]) {
						end = mid - 1;
					}
					else {
						start = mid + 1;
					}
				}
				else if (nums[mid] <= nums[end]) {
					if (nums[mid] < target && target <= nums[end]) {
						start = mid + 1;
					}
					else {
						end = mid - 1;
					}
				}
			}
			return nums[start] == target ? start : -1;
		}

		void Main() {
			vector<int> test = { 5, 1, 3};
			print(search(test, 3));
			//vector<int> test = { 4,5,6,7,0,1,2 };
		}
	}
}

