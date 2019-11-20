#include "stdafx.h"

//In a given grid, each cell can have one of three values:
//the value 0 representing an empty cell;
//the value 1 representing a fresh orange;
//the value 2 representing a rotten orange.
//Every minute, any fresh orange that is adjacent (4-directionally) to a rotten
//orange becomes rotten.
//Return the minimum number of minutes that must elapse until no cell has a fresh
//orange.  If this is impossible, return -1 instead.
// 
//
//Example 1:
//Input: [[2,1,1],[1,1,0],[0,1,1]]
//Output: 4
//
//Example 2:
//Input: [[2,1,1],[0,1,1],[1,0,1]]
//Output: -1
//Explanation:  The orange in the bottom left corner (row 2, column 0) is never
//rotten, because rotting only happens 4-directionally.
//
//Example 3:
//Input: [[0,2]]
//Output: 0
//Explanation:  Since there are already no fresh oranges at minute 0, the answer
//is just 0.
// 
//
//Note:
//1 <= grid.length <= 10
//1 <= grid[0].length <= 10
//grid[i][j] is only 0, 1, or 2.

namespace Solution2019
{
	namespace RottingOranges
	{
		int orangesRotting(vector<vector<int>>& grid) {
			int rowCount = grid.size();
			if (rowCount == 0) { return 0; }
			int colCount = grid[0].size();
			if (colCount == 0) { return 0; }

			int fresh = 0;
			queue<pair<int, int>> q;
			vector<vector<bool>> visited(rowCount, vector<bool>(colCount, false));
			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					if (grid[i][j] == 1) { fresh++; }
					else if (grid[i][j] == 2) { q.push({ i, j }); visited[i][j] = true; }
				}
			}

			int result = 0;
			while (!q.empty() && fresh > 0) {
				int sz = q.size();
				result++;
				while (sz) {
					sz--;
					auto [i, j] = q.front();
					q.pop();
					if (i - 1 >= 0 && !visited[i - 1][j] && grid[i - 1][j] == 1) { q.push({ i - 1, j }); visited[i - 1][j] = true; fresh--; }
					if (i + 1 < rowCount && !visited[i + 1][j] && grid[i + 1][j] == 1) { q.push({ i + 1, j }); visited[i + 1][j] = true; fresh--; }
					if (j - 1 >= 0 && !visited[i][j - 1] && grid[i][j - 1] == 1) { q.push({ i, j - 1 }); visited[i][j - 1] = true; fresh--; }
					if (j + 1 < colCount && !visited[i][j + 1] && grid[i][j + 1] == 1) { q.push({ i, j + 1 }); visited[i][j + 1] = true; fresh--; }
				}
			}
			return fresh == 0 ? result : -1;
		}

		void Main() {
			vector<vector<int>> test = { {2,1,1},{1,1,0},{0,1,1} };
			print(orangesRotting(test));
		}
	}
}

