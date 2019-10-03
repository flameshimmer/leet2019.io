#include "stdafx.h"
//You are given a map in form of a two-dimensional integer
//grid where 1 represents land and 0 represents water.
//
//Grid cells are connected horizontally/vertically (not diagonally). 
//The grid is completely surrounded by water, and there is exactly 
//one island (i.e., one or more connected land cells).
//
//The island doesn't have "lakes" (water inside that isn't connected
//to the water around the island). One cell is a square with side
//length 1. The grid is rectangular, width and height don't exceed 100. 
//Determine the perimeter of the island.
//
//Example:
//Input:
//[[0,1,0,0],
// [1,1,1,0],
// [0,1,0,0],
// [1,1,0,0]]
//
//Output: 16
//Explanation: The perimeter is the 16 yellow stripes in the image below:

 

namespace Solution2019
{
	namespace IslandPerimeter
	{
		int islandPerimeter(vector<vector<int>>& G) {
			int rowCount = G.size();
			if (rowCount == 0) { return 0; }
			int colCount = G[0].size();
			if (colCount == 0) { return 0; }

			int result = 0;
			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					if (G[i][j] == 0) { continue; }
					int nc = 0;
					if (i - 1 >= 0 && G[i - 1][j] == 1) { nc++; }
					if (i + 1 < rowCount && G[i + 1][j] == 1) { nc++; }
					if (j - 1 >= 0 && G[i][j - 1] == 1) { nc++; }
					if (j + 1 < colCount && G[i][j + 1] == 1) { nc++; }
					result += 4 - nc;
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

