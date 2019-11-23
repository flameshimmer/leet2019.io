#include "stdafx.h"

//Given a matrix of integers A with R rows and C columns, find the maximum score
//of a path starting at [0,0] and ending at [R-1,C-1].
//The score of a path is the minimum value in that path.  For example, the value
//of the path 8 →  4 →  5 →  9 is 4.
//A path moves some number of times from one visited cell to any neighbouring
//unvisited cell in one of the 4 cardinal directions (north, east, west, south).
// 
//
//Example 1:
//Input: [[5,4,5],[1,2,6],[7,4,6]]
//Output: 4
//Explanation: 
//The path with the maximum score is highlighted in yellow. 
//
//Example 2:
//Input: [[2,2,1,2,2,2],[1,2,2,2,1,2]]
//Output: 2
//
//Example 3:
//Input:
//[[3,4,6,3,4],[0,2,1,1,7],[8,8,3,2,7],[3,2,4,9,8],[4,1,2,0,0],[4,6,5,4,3]]
//Output: 3
// 
//
//Note:
//1 <= R, C <= 100
//0 <= A[i][j] <= 10^9

namespace Solution2019
{
	namespace PathWithMaximumMinimumValue
	{
		int maximumMinimumPath(vector<vector<int>>& A) {
			vector<vector<int>> dirs = { {0, 1}, {0, -1}, {1, 0} , {-1, 0} };
			priority_queue<tuple<int, int, int>> pq;
			pq.push({ A[0][0], 0, 0 });
			int rowCount = A.size();
			int colCount = A[0].size();
			int result = A[0][0];

			A[0][0] = -1;
			while (!pq.empty()) {
				auto [a, i, j] = pq.top();
				pq.pop();
				result = min(result, a);
				if (i == rowCount - 1 && j == colCount - 1) {
					return result;
				}
				for (const auto& dir : dirs) {
					int x = i + dir[0];
					int y = j + dir[1];
					if (x < 0 || x >= rowCount || y < 0 || y >= colCount || A[x][y] < 0) { continue; }
					pq.push({ A[x][y], x, y });
					A[x][y] = -1;
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

