#include "stdafx.h"

//Given an integer matrix, find the length of the longest increasing path.
//From each cell, you can either move to four directions: left, right, up or
//down. You may NOT move diagonally or move outside of the boundary (i.e.
//wrap-around is not allowed).
//
//Example 1:
//Input: nums = 
//[
//  [9,9,4],
//  [6,6,8],
//  [2,1,1]
//] 
//Output: 4 
//Explanation: The longest increasing path is [1, 2, 6, 9].
//
//Example 2:
//Input: nums = 
//[
//  [3,4,5],
//  [3,2,6],
//  [2,2,1]
//] 
//Output: 4 
//Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is
//not allowed. 

namespace Solution2019
{
	namespace LongestIncreasingPathinaMatrix
	{
		namespace DFSAndMemoryTable {

			vector<pair<int, int>> dirs = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
			int dfs(vector<vector<int>>& matrix, int i, int j, int rowCount, int colCount, vector<vector<int>>& M) {
				if (M[i][j] != 0) { return M[i][j]; }
				int result = 1;
				for (pair<int, int>& dir : dirs) {
					int x = i + dir.first;
					int y = j + dir.second;
					if (x < 0 || x >= rowCount || y < 0 || y >= colCount || matrix[x][y] <= matrix[i][j]) { continue; }
					result = max(result, 1 + dfs(matrix, x, y, rowCount, colCount, M));
				}
				M[i][j] = result;
				return result;
			}

			int longestIncreasingPath(vector<vector<int>>& matrix) {
				int rowCount = matrix.size();
				if (rowCount == 0) { return 0; }
				int colCount = matrix[0].size();
				if (colCount == 0) { return 0; }

				vector<vector<int>> M(rowCount, vector<int>(colCount, 0));
				int result = 1;
				for (int i = 0; i < rowCount; i++) {
					for (int j = 0; j < colCount; j++) {
						result = max(result, dfs(matrix, i, j, rowCount, colCount, M));
					}
				}
				return result;
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

