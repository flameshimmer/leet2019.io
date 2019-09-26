#include "stdafx.h"
//Given an array nums of n integers, are there elements
//a, b, c in nums such that a + b + c = 0? Find all 
//unique triplets in the array which gives the sum of zero.
//
//Note:
//The solution set must not contain duplicate triplets.
//
//Example:
//Given array nums = [-1, 0, 1, 2, -1, -4],
//A solution set is:
//[
//  [-1, 0, 1],
//  [-1, -1, 2]
//]

namespace Solution2019
{
	namespace ThreeSum
	{
		vector<vector<int>> threeSum(vector<int>& nums) {
			sort(nums.begin(), nums.end());
			int len = nums.size();

			vector<vector<int>> result;
			for (int i = len - 1; i >= 2; i--) {
				int l = 0;
				int r = i - 1;
				while (l < r) {
					int sum = nums[l] + nums[r] + nums[i];
					if (sum == 0) {
						while (l < r && nums[r - 1] == nums[r]) { r--; }
						while (l < r && nums[l + 1] == nums[l]) { l++; }
						result.push_back({ nums[l], nums[r], nums[i] });
						r--;
						l++;
					}
					else if (sum < 0) {
						l++;
					}
					else {
						r--;
					}
				}
				while (i - 1 >= 2 && nums[i - 1] == nums[i]) { i--; }
			}
			return result;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

