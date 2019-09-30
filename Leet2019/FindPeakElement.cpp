#include "stdafx.h"
/*A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], 
find a peak element and return its index.

The array may contain multiple peaks, in that case 
return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.

Example 1:
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function 
should return the index number 2.

Example 2:
Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5 
Explanation: Your function can return either index 
number 1 where the peak element is 2, or index 
number 5 where the peak element is 6.

Note:
Your solution should be in logarithmic complexity.*/ 

namespace Solution2019
{
	namespace FindPeakElement
	{
		int findPeakElement(vector<int>& A) {
			int len = A.size();
			int start = 0;
			int end = len - 1;
			while (start < end) {
				int mid = start + (end - start) / 2;
				if (A[mid] < A[mid + 1]) {
					start = mid + 1;
				}
				else {
					end = mid;
				}
			}
			return start;
		}


		void Main() {
			vector<int> test = { 1, 2,3 ,1 };
			print(findPeakElement(test));
		}
	}
}

