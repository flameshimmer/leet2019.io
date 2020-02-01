#include "stdafx.h"

//You are given a list of non-negative integers, a1, a2, ..., an, and a target,
//S. Now you have 2 symbols + and -. For each integer, you should choose one from
//+ and - as its new symbol.
//Find out how many ways to assign symbols to make sum of integers equal to
//target S.
//
//Example 1:
//Input: nums is [1, 1, 1, 1, 1], S is 3. 
//Output: 5
//Explanation: 
//-1+1+1+1+1 = 3
//+1-1+1+1+1 = 3
//+1+1-1+1+1 = 3
//+1+1+1-1+1 = 3
//+1+1+1+1-1 = 3
//There are 5 ways to assign symbols to make the sum of nums be target 3.
//
//Note:
//The length of the given array is positive and will not exceed 20.
//The sum of elements in the given array will not exceed 1000.
//Your output answer is guaranteed to be fitted in a 32-bit integer.

namespace Solution2019
{
	namespace TargetSum
	{
		namespace Recursion {
			void helper(vector<int>& nums, int start, int len, int curSum, int target, int& result) {
				if (start == len) {
					if (curSum == target) { result++; }
					return;
				}

				helper(nums, start + 1, len, curSum + nums[start], target, result);
				helper(nums, start + 1, len, curSum - nums[start], target, result);
			}

			int findTargetSumWays(vector<int>& nums, int S) {
				int len = nums.size();
				int sum = 0;
				int result = 0;
				helper(nums, 0, len, sum, S, result);
				return result;
			}
		}

		namespace DP {
			
			int subsetSum(vector<int>& nums, int s) {
				vector<int> dp(s + 1, 0);
				dp[0] = 1;
				for (int n : nums) {
					for (int i = s; i >= n; i--) {
						dp[i] += dp[i - n];
					}
				}
				return dp[s];
			}

			int findTargetSumWays(vector<int>& nums, int S) {
				int sum = accumulate(nums.begin(), nums.end(), 0);
				if (sum < S || (sum + S) % 2 != 0) { return 0; }
				return subsetSum(nums, (sum + S) / 2);
			}
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

