#include "stdafx.h"
//A robot is located at the top - left corner of a m x n grid
//(marked 'Start' in the diagram below).
//
//The robot can only move either down or right at any point in time.
//The robot is trying to reach the bottom - right corner of the grid
//(marked 'Finish' in the diagram below).
//
//Now consider if some obstacles are added to the grids.
//How many unique paths would there be ?
//
//An obstacleand empty space is marked as 1 and 0 respectively in the grid.
//Note : m and n will be at most 100.
//
//Example 1 :
//Input :
//[
//	[0, 0, 0],
//	[0, 1, 0],
//	[0, 0, 0]
//]
//Output : 2
//Explanation :
//There is one obstacle in the middle of the 3x3 grid above.
//There are two ways to reach the bottom - right corner :
//1. Right->Right->Down->Down
//2. Down->Down->Right->Right

namespace Solution2019
{
	namespace UniquePathsII
	{
		int uniquePathsWithObstacles(vector<vector<int>>& G) {
			int rowCount = G.size();
			int colCount = G[0].size();
			vector<long long> dp(colCount, 0);
			dp[0] = 1;
			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					if (G[i][j] == 1) { dp[j] = 0; }
					else { dp[j] += (j - 1 >= 0 ? dp[j - 1] : 0); }
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

