#include "stdafx.h"
//Given a 2d grid map of '1's (land) and '0's (water), 
//count the number of islands. An island is surrounded 
//by water and is formed by connecting adjacent lands 
//horizontally or vertically. You may assume all four 
//edges of the grid are all surrounded by water.
//
//Example 1:
//Input:
//11110
//11010
//11000
//00000
//Output: 1
//
//Example 2:
//Input:
//11000
//11000
//00100
//00011
//Output: 3 

namespace Solution2019
{
	namespace NumberofIslands
	{
		void helper(vector<vector<char>>& grid, int row, int col, int rowCount, int colCount) {
			if (row < 0 || row >= rowCount || col < 0 || col >= colCount || grid[row][col] == '0') { return; }
			grid[row][col] = '0';
			helper(grid, row - 1, col, rowCount, colCount);
			helper(grid, row + 1, col, rowCount, colCount);
			helper(grid, row, col - 1, rowCount, colCount);
			helper(grid, row, col + 1, rowCount, colCount);
		}


		int numIslands(vector<vector<char>>& grid) {
			int rowCount = grid.size();
			if (rowCount == 0) { return 0; }
			int colCount = grid[0].size();
			if (colCount == 0) { return 0; }

			int result = 0;
			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					if (grid[i][j] == '1') {
						result++;
						helper(grid, i, j, rowCount, colCount);
					}
				}
			}
			return result;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

