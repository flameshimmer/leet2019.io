#include "stdafx.h"
//Given an array nums of n integers and an integer 
//target, are there elements a, b, c, and d in nums
//such that a + b + c + d = target? Find all unique 
//quadruplets in the array which gives the sum of target.
//
//Note:
//
//The solution set must not contain duplicate quadruplets.
//
//Example:
//
//Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
//
//A solution set is:
//[
//  [-1,  0, 0, 1],
//  [-2, -1, 1, 2],
//  [-2,  0, 0, 2]
//] 

namespace Solution2019
{
	namespace FourSum
	{
		vector<vector<int>> fourSum(vector<int>& nums, int target) {
			int len = nums.size();
			vector<vector<int>> result;
			if (len < 4) { return result; }

			sort(nums.begin(), nums.end());
			for (int i = len - 1; i >= 3; i--) {
				for (int j = i - 1; j >= 2; j--) {
					int l = 0;
					int r = j - 1;
					while (l < r) {
						int sum = nums[l] + nums[r] + nums[i] + nums[j];
						if (sum == target) {
							result.push_back({ nums[l], nums[r], nums[i], nums[j] });
							while (l < r && nums[l] == nums[l + 1]) { l++; }
							while (l < r && nums[r - 1] == nums[r]) { r--; }
							l++;
							r--;
						}
						else if (sum < target) {
							l++;
						}
						else {
							r--;
						}
					}
					while (j >= 2 && nums[j] == nums[j - 1]) { j--; }
				}
				while (i >= 3 && nums[i] == nums[i - 1]) { i--; }
			}
			return result;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

