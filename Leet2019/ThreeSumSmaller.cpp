#include "stdafx.h"
//Given an array of n integers nums and a target, 
//find the number of index triplets i, j, k with 
//0 <= i < j < k < n that satisfy the condition 
//nums[i] + nums[j] + nums[k] < target.
//
//Example:
//
//Input: nums = [-2,0,1,3], and target = 2
//Output: 2 
//Explanation: Because there are two triplets which sums are less than 2:
//             [-2,0,1]
//             [-2,0,3]
//Follow up: Could you solve it in O(n2) runtime? 

namespace Solution2019
{
	namespace ThreeSumSmaller
	{
		int threeSumSmaller(vector<int>& nums, int target) {
			int len = nums.size();
			if (len < 3) { return 0; }

			sort(nums.begin(), nums.end());
			int result = 0;
			for (int i = len - 1; i >= 2; i--) {
				int l = 0;
				int r = i - 1;
				while (l < r) {
					int sum = nums[l] + nums[r] + nums[i];
					if (sum < target) {
						result += r - l;
						l++;
					}
					else { r--; }
				}
			}
			return result;
		}
		void Main() {
			vector<int> test = { -2, 0, 1, 3 };

			print(threeSumSmaller(test, 2));
		}
	}
}

