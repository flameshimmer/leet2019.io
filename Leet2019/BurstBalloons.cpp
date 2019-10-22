#include "stdafx.h"
//Given n balloons, indexed from 0 to n-1. Each balloon is painted with a 
//number on it represented by array nums. You are asked to burst all the 
//balloons. If the you burst balloon i you will get 
//nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent
//indices of i. After the burst, the left and right then becomes adjacent.
//
//Find the maximum coins you can collect by bursting the balloons wisely.
//
//Note:
//You may imagine nums[-1] = nums[n] = 1. They are not real therefore you
//can not burst them.
//0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
//
//Example:
//Input: [3,1,5,8]
//Output: 167 
//Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
//             coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167 

namespace Solution2019
{
	namespace BurstBalloons
	{
		int maxCoins(vector<int>& nums) {
			int n = nums.size();
			nums.insert(nums.begin(), 1);
			nums.push_back(1);
			vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

			for (int len = 1; len <= n; len++) {
				// last index is n, n-start+1 = len --> start = n+1-len
				for (int start = 1; start <= n + 1 - len; start++) {
					int end = start + len - 1;
					for (int k = start; k <= end; k++) {
						dp[start][end] = max(dp[start][end], nums[start - 1] * nums[k] * nums[end + 1] + dp[start][k - 1] + dp[k + 1][end]);
					}
				}
			}
			return dp[1][n];
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

