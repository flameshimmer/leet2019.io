#include "stdafx.h"
//In a given integer array nums, there is always exactly one largest element.
//Find whether the largest element in the array is at least twice 
//as much as every other number in the array.
//If it is, return the index of the largest element, otherwise return -1.
//
//Example 1:
//Input: nums = [3, 6, 1, 0]
//Output: 1
//Explanation: 6 is the largest integer, and for every other number in the array x,
//6 is more than twice as big as x.  The index of value 6 is 1, so we return 1.
// 
//
//Example 2:
//Input: nums = [1, 2, 3, 4]
//Output: -1
//Explanation: 4 isn't at least as big as twice the value of 3, so we return -1.
// 
//Note:
//nums will have a length in the range [1, 50].
//Every nums[i] will be an integer in the range [0, 99].
namespace Solution2019
{
	namespace LargestNumberAtLeastTwiceofOthers
	{
		int dominantIndex(vector<int>& nums) {
			int result = -1;
			long long max1 = INT_MIN;
			long long max2 = INT_MIN;

			for (int i = 0; i < nums.size(); i++) {
				int v = nums[i];
				if (v > max1) {
					max2 = max1;
					max1 = v;
					result = i;
				}
				else if (v > max2) {
					max2 = v;
				}
			}
			if (max1 >= max2 * 2) { return result; }
			return -1;

		}

		int dominantIndex(vector<int> nums) {
			int maxIndex = -1;
			int maxVal = INT_MIN;
			for (int i = 0; i < nums.size(); i++) {
				if (nums[i] > maxVal) { maxVal = nums[i]; maxIndex = i; }
			}
			for (int i = 0; i < nums.size(); i++) {
				if (i != maxIndex) {
					if (nums[i] * 2 > maxVal) {
						return -1;
					}
				}
			}
			return maxIndex;
		}

		void Main() {
			string test = "tst test test";
			print(dominantIndex({ 0,0,1,2 }));
		}
	}
}

