#include "stdafx.h"
//Given an array nums sorted in non-decreasing order, 
//and a number target, return True if and only if target 
//is a majority element.
//
//A majority element is an element that appears more than 
//N/2 times in an array of length N.
//
//Example 1:
//Input: nums = [2,4,5,5,5,5,5,6,6], target = 5
//Output: true
//Explanation: 
//The value 5 appears 5 times and the length of the array is 9.
//Thus, 5 is a majority element because 5 > 9/2 is true.
//
//Example 2:
//Input: nums = [10,100,101,101], target = 101
//Output: false
//Explanation: 
//The value 101 appears 2 times and the length of the array is 4.
//Thus, 101 is not a majority element because 2 > 4/2 is false.
// 
//Note:
//1 <= nums.length <= 1000
//1 <= nums[i] <= 10^9
//1 <= target <= 10^9

namespace Solution2019
{
	namespace CheckIfaNumberIsMajorityElementinaSortedArray
	{
		bool CheckIfaNumberIsMajorityElementinaSortedArray(vector<int> nums, int target) {
			int start = 0;
			int end = nums.size() - 1;

			int leftBoundary = 0;
			while (start <= end) {
				int mid = start + (end - start) / 2;
				if (nums[mid] < target) {
					start = mid + 1;
				}
				else {
					end = mid - 1;
				}
			}
			leftBoundary = start;

			int rightBoundary = 0;
			start = 0;
			end = nums.size() - 1;
			while (start <= end) {
				int mid = start + (end - start) / 2;
				if (nums[mid] <= target) {
					start = mid + 1;
				}
				else {
					end = mid - 1;
				}
			}
			rightBoundary = end;
			return (rightBoundary - leftBoundary + 1) > (nums.size() / 2);
		}

		void Main() {
			string test = "tst test test";
			print(CheckIfaNumberIsMajorityElementinaSortedArray({ 2,4,5,5,5,5,5,6,6 }, 5));
		}
	}
}

