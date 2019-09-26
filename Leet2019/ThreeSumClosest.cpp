#include "stdafx.h"
//Given an array nums of n integersand an integer target, 
//find three integers in nums such that the sum is closest 
//to target.Return the sum of the three integers.
//You may assume that each input would have exactly one solution.
//
//Example:
//Given array nums = [-1, 2, 1, -4], and target = 1.
//The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

namespace Solution2019
{
	namespace ThreeSumClosest
	{
		int threeSumClosest(vector<int>& nums, int target) {
			sort(nums.begin(), nums.end());
			int len = nums.size();
			if (len < 3) { return 0; }

			int result = nums[0] + nums[1] + nums[2];
			int diff = abs(result - target);
			for (int i = len - 1; i >= 2; i--) {
				int l = 0;
				int r = i - 1;
				while (l < r) {
					int sum = nums[l] + nums[r] + nums[i];
					int curDiff = abs(sum - target);
					if (curDiff == 0) { return target; }
					if (curDiff < diff) {
						result = sum;
						diff = curDiff;
					}
					else if (sum < target) {
						l++;
					}
					else {
						r--;
					}
				}
			}
			return result;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

