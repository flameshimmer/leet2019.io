#include "stdafx.h"

//Given a positive integer n, find the least number of perfect square numbers
//(for example, 1, 4, 9, 16, ...) which sum to n.
//
//Example 1:
//Input: n = 12
//Output: 3 
//Explanation: 12 = 4 + 4 + 4.
//
//Example 2:
//Input: n = 13
//Output: 2
//Explanation: 13 = 4 + 9. 

namespace Solution2019
{
	namespace PerfectSquares
	{
		int numSquares(int n) {
			if (n == 0) { return 0; }
			vector<int> dp(n + 1, 0);

			for (int i = 0; i <= n; i++) {
				dp[i] = i;
				for (int j = 2; j <= sqrt(i); j++) {
					dp[i] = min(dp[i], dp[i - j * j] + 1);
				}
			}
			return dp[n];
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

