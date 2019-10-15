#include "stdafx.h"
//Given an array consisting of n integers, find the contiguous
//subarray whose length is greater than or equal to k that has
//the maximum average value. And you need to output the maximum
//average value.
//
//Example 1:
//Input: [1,12,-5,-6,50,3], k = 4
//Output: 12.75
//Explanation:
//when length is 5, maximum average value is 10.8,
//when length is 6, maximum average value is 9.16667.
//Thus return 12.75.
//
//Note:
//1 <= k <= n <= 10,000.
//Elements of the given array will be in range [-10,000, 10,000].
//The answer with the calculation error less than 10-5 will be accepted.

namespace Solution2019
{
	namespace MaximumAverageSubarrayII
	{
		bool isLarger(vector<int>& nums, double mid, int k) {
			double sum = 0;
			double prev_sum = 0;
			double min_sum = 0;
			for (int i = 0; i < nums.size(); i++) {
				sum += nums[i] - mid;
				if (i >= k) {
					prev_sum += nums[i - k] - mid;
					min_sum = min(min_sum, prev_sum);
				}
				if (i >= k - 1 && sum > min_sum) return false;
			}
			return true;
		}


		double findMaxAverage(vector<int>& nums, int k) {
			double left = INT_MAX;
			double right = INT_MIN;
			double mid = 0;

			for (int v : nums) {
				left = min(left, double(v));
				right = max(right, double(v));
			}

			while (left + 0.00001 < right) {
				mid = left + (right - left) / 2;
				if (isLarger(nums, mid, k)) {
					right = mid;
				}
				else { left = mid; }
			}
			return left;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

