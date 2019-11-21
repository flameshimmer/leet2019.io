#include "stdafx.h"

//In an N by N square grid, each cell is either empty (0) or blocked (1).
//A clear path from top-left to bottom-right has length k if and only if it is
//composed of cells C_1, C_2, ..., C_k such that:
//Adjacent cells C_i and C_{i+1} are connected 8-directionally (ie., they are
//different and share an edge or corner)
//C_1 is at location (0, 0) (ie. has value grid[0][0])
//C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1])
//If C_i is located at (r, c), then grid[r][c] is empty (ie. grid[r][c] == 0).
//Return the length of the shortest such clear path from top-left to
//bottom-right.  If such a path does not exist, return -1.
// 
//
//Example 1:
//Input: [[0,1],[1,0]]
//Output: 2
//
//Example 2:
//Input: [[0,0,0],[1,1,0],[1,1,0]]
//Output: 4
// 
//
//Note:
//1 <= grid.length == grid[0].length <= 100
//grid[r][c] is 0 or 1

namespace Solution2019
{
	namespace ShortestPathinBinaryMatrix
	{
		int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
			int rowCount = grid.size();
			if (rowCount == 0) { return -1; }
			int colCount = grid[0].size();
			if (colCount == 0) { return -1; }
			if (grid[0][0] == 1 || grid[rowCount - 1][colCount - 1] == 1) { return -1;  //---> notice this special case!!!!
			if (rowCount == 1 && colCount == 1) { return 1; } //---> notice this special case!!!!

			vector<vector<bool>> visited(rowCount, vector<bool>(colCount, false));
			queue<pair<int, int>> q;
			q.push({ 0, 0 });
			visited[0][0] = true;
			int result = 1;

			pair<int, int> dirs[8] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
			while (!q.empty()) {
				int sz = q.size();
				result++;
				while (sz) {
					sz--;
					auto [i, j] = q.front();
					q.pop();
					for (pair<int, int>& dir : dirs) {
						int x = i + dir.first;
						int y = j + dir.second;
						if (x == rowCount - 1 && y == colCount - 1) { return result; }
						if (x < 0 || x >= rowCount || y < 0 || y >= colCount || visited[x][y] || grid[x][y]) { continue; }
						visited[x][y] = true;
						q.push({ x, y });
					}
				}
			}
			return -1;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

