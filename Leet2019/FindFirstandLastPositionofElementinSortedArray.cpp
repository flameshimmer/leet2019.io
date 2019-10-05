#include "stdafx.h"
//Given an array of integers nums sorted in ascending order, 
//find the starting and ending position of a given target value.
//
//Your algorithm's runtime complexity must be in the order of O(log n).
//
//If the target is not found in the array, return [-1, -1].
//
//Example 1:
//Input: nums = [5,7,7,8,8,10], target = 8
//Output: [3,4]
//
//Example 2:
//Input: nums = [5,7,7,8,8,10], target = 6
//Output: [-1,-1]

namespace Solution2019
{
	namespace FindFirstandLastPositionofElementinSortedArray
	{
		int findLower(vector<int>& A, int target) {
			int start = 0;
			int end = A.size() - 1;
			while (start < end) {
				int mid = start + (end - start) / 2;
				if (target <= A[mid]) {
					end = mid;
				}
				else {
					start = mid + 1;
				}
			}
			return A[start] == target ? start : -1;
		}

		int findUpper(vector<int>& A, int target) {
			int start = 0;
			int end = A.size() - 1;
			while (start < end) {
				int mid = start + (end - start) / 2 + 1;
				if (target >= A[mid]) {
					start = mid;
				}
				else {
					end = mid - 1;
				}
			}
			return A[start] == target ? start : -1;
		}

		/* Very interesting finding:
		mid index calc logic is bias towards left side index, this is helpful when looking
		for the lower bound value. When searching for upper bound we need to use mid+1 to
		make the bias towards the right side index. This will ensure we don't stuck in
		permanent loop when looking of uppper bound. */

		vector<int> searchRange(vector<int>& nums, int target) {
			int len = nums.size();
			if (len == 0) { return { -1, -1 }; }
			return { findLower(nums, target), findUpper(nums, target) };
		}

		namespace UsingLowerBoundUpperBound {
			vector<int> searchRange(vector<int>& nums, int target) {
				auto lower = lower_bound(nums.begin(), nums.end(), target);
				if (lower == nums.end() || *lower != target) {
					return { -1, -1 };
				}

				auto upper = upper_bound(nums.begin(), nums.end(), target);
				return { lower - nums.begin(), upper - nums.begin() - 1 };
			}
		}

		void Main() {
			vector<int> test = { 5,7,7,8,8,10 };
			print(searchRange(test, 8));
		}
	}
}

