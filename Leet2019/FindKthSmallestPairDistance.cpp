#include "stdafx.h"
//Given an integer array, return the k-th smallest distance
//among all the pairs. The distance of a pair (A, B) is 
//defined as the absolute difference between A and B.
//
//Example:
//Input:
//nums = [1,3,1]
//k = 1
//Output: 0 
//Explanation:
//Here are all the pairs:
//(1,3) -> 2
//(1,1) -> 0
//(3,1) -> 2
//Then the 1st smallest distance pair is (1,1), and its distance is 0.
//
//Note:
//2 <= len(nums) <= 10000.
//0 <= nums[i] < 1000000.
//1 <= k <= len(nums) * (len(nums) - 1) / 2.

namespace Solution2019
{
	namespace FindKthSmallestPairDistance
	{
		int smallestDistancePair(vector<int>& nums, int k) {
			sort(nums.begin(), nums.end());
			int len = nums.size();
			int low = 0;
			int high = nums[len - 1] - nums[0];

			while (low < high) {
				int mid = low + (high - low) / 2;
				int count = 0;
				for (int i = 0, j = 0; i < len; i++) {
					while (j < len && nums[j] - nums[i] <= mid) { j++; }
					count += j - i - 1; //--> total length is j-i, but extra -1 here because i and j must be different, (i, i) is not vaild.
				}
				if (count < k) {
					low = mid + 1;
				}
				else {
					high = mid;
				}
			}
			return low;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

