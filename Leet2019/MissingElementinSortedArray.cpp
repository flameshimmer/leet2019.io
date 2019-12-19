#include "stdafx.h"

//Given a sorted array A of unique numbers, find the K-th missing number starting
//from the leftmost number of the array.
// 
//
//Example 1:
//Input: A = [4,7,9,10], K = 1
//Output: 5
//Explanation: 
//The first missing number is 5.
//
//Example 2:
//Input: A = [4,7,9,10], K = 3
//Output: 8
//Explanation: 
//The missing numbers are [5,6,8,...], hence the third missing number is 8.
//
//Example 3:
//Input: A = [1,2,4], K = 3
//Output: 6
//Explanation: 
//The missing numbers are [3,5,6,7,...], hence the third missing number is 6.
// 
//
//Note:
//1 <= A.length <= 50000
//1 <= A[i] <= 1e7
//1 <= K <= 1e8

namespace Solution2019
{
	namespace MissingElementinSortedArray
	{
		int missingElement(vector<int>& nums, int k) {
			int start = 0;
			int end = nums.size();
			while (start < end) {
				int mid = start + (end - start) / 2;
				if (nums[mid] - nums[0] >= mid + k) {
					end = mid;
				}
				else {
					start = mid + 1;
				}
			}
			return nums[0] + start + k - 1;
		}

		namespace TooSlow {
			int missingElement(vector<int>& nums, int k) {
				for (int i = 1; i < nums.size(); i++) {
					int diff = nums[i] - nums[i - 1] - 1;
					if (k > diff) { k -= diff; }
					else {
						return nums[i - 1] + k;
					}
				}
				return nums.back() + k;
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

