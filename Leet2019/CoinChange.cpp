#include "stdafx.h"
//You are given coins of different denominations and a total amount 
//of money amount. Write a function to compute the fewest number of 
//coins that you need to make up that amount. If that amount of money 
//cannot be made up by any combination of the coins, return -1.
//
//Example 1:
//Input: coins = [1, 2, 5], amount = 11
//Output: 3 
//Explanation: 11 = 5 + 5 + 1
//
//Example 2:
//Input: coins = [2], amount = 3
//Output: -1
//Note:
//You may assume that you have an infinite number of each kind of coin.

namespace Solution2019
{
	namespace CoinChange
	{
		int coinChange(vector<int>& coins, int amount) {
			vector<long long> dp(amount + 1, INT_MAX);
			dp[0] = 0;
			for (int i = 1; i <= amount; i++) {
				for (int coinV : coins) {
					if (i >= coinV) {
						dp[i] = min(dp[i], dp[i - coinV] + 1);
					}
				}
			}
			return dp[amount] == INT_MAX ? -1 : (int)dp[amount];
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

