#include "stdafx.h"

//You want to build a house on an empty land which reaches all buildings in the
//shortest amount of distance. You can only move up, down, left and right. You
//are given a 2D grid of values 0, 1 or 2, where:
//Each 0 marks an empty land which you can pass by freely.
//Each 1 marks a building which you cannot pass through.
//Each 2 marks an obstacle which you cannot pass through.
//
//Example:
//Input: [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]
//1 - 0 - 2 - 0 - 1
//|   |   |   |   |
//0 - 0 - 0 - 0 - 0
//|   |   |   |   |
//0 - 0 - 1 - 0 - 0
//Output: 7 
//Explanation: Given three buildings at (0,0), (0,4), (2,2), and an obstacle at
//(0,2),
//             the point (1,2) is an ideal empty land to build a house, as the
//total 
//             travel distance of 3+3+1=7 is minimal. So return 7.
//
//Note:
//There will be at least one building. If it is not possible to build such house
//according to the above rules, return -1.

namespace Solution2019
{
	namespace ShortestDistancefromAllBuildings
	{
		vector<pair<int, int>> dirs = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
		void bfs(vector<vector<int>>& grid, int i, int j, int rowCount, int colCount, int level, vector<vector<int>>& distance, vector<vector<int>>& reach) {
			vector<vector<bool>> visited(rowCount, vector<bool>(colCount, false));
			queue<pair<int, int>> q;
			q.push({ i,j });
			visited[i][j] = true;
			while (!q.empty()) {
				int sz = q.size();
				level++;
				while (sz) {
					sz--;
					pair<int, int> ij = q.front();
					q.pop();
					reach[ij.first][ij.second]++;
					for (auto dir : dirs) {
						int x = ij.first + dir.first;
						int y = ij.second + dir.second;
						if (x >= 0 && x < rowCount &&
							y >= 0 && y < colCount &&
							grid[x][y] == 0 && !visited[x][y])
						{
							distance[x][y] += level;
							q.push({ x, y });
							visited[x][y] = true;
						}
					}
				}
			}
		}

		int shortestDistance(vector<vector<int>>& grid) {
			int rowCount = grid.size();
			if (rowCount == 0) { return -1; }
			int colCount = grid[0].size();
			if (colCount == 0) { return -1; }

			vector<vector<int>> distance(rowCount, vector<int>(colCount, 0));
			vector<vector<int>> reach(rowCount, vector<int>(colCount, 0));

			int building = 0;
			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					if (grid[i][j] == 1) {
						building++;
						bfs(grid, i, j, rowCount, colCount, 0, distance, reach);
					}
				}
			}
			int result = INT_MAX;
			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					if (grid[i][j] == 0 && reach[i][j] == building) {
						result = min(result, distance[i][j]);
					}
				}
			}
			return result == INT_MAX ? -1 : result;
		}

		void Main() {
			vector<vector<int>> test = { {1,0,2,0,1},{0,0,0,0,0},{0,0,1,0,0} };
			print(shortestDistance(test));
		}
	}
}

