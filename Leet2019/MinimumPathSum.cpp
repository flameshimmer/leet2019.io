#include "stdafx.h"
//Given a m x n grid filled with non-negative numbers, find 
//a path from top left to bottom right which minimizes the sum 
//of all numbers along its path.
//
//Note: You can only move either down or right at any point in time.
//Example:
//Input:
//[
//  [1,3,1],
//  [1,5,1],
//  [4,2,1]
//]
//Output: 7
//Explanation: Because the path 1→3→1→1→1 minimizes the sum. 

namespace Solution2019
{
	namespace MinimumPathSum
	{
		int minPathSum(vector<vector<int>>& grid) {
			int rowCount = grid.size();
			if (rowCount == 0) { return 0; }
			int colCount = grid[0].size();

			vector<int> dp(grid[0].begin(), grid[0].end());
			for (int i = 1; i < colCount; i++) {
				dp[i] += dp[i - 1];
			}
			for (int i = 1; i < rowCount; i++) {
				dp[0] = grid[i][0];
				for (int j = 1; j < colCount; j++) {				
					dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
				}
			}
			return dp[colCount - 1];
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

