#include "stdafx.h"
//Given a matrix of m x n elements (m rows, n columns), 
//return all elements of the matrix in spiral order.
//
//Example 1:
//
//Input:
//[
// [ 1, 2, 3 ],
// [ 4, 5, 6 ],
// [ 7, 8, 9 ]
//]
//Output: [1,2,3,6,9,8,7,4,5]
//Example 2:
//
//Input:
//[
//  [1, 2, 3, 4],
//  [5, 6, 7, 8],
//  [9,10,11,12]
//]
//Output: [1,2,3,4,8,12,11,10,9,5,6,7]

namespace Solution2019
{
	namespace SpiralMatrix
	{
		vector<int> spiralOrder(vector<vector<int>>& matrix) {
			vector<int> result;
			int rowCount = matrix.size();
			if (rowCount == 0) { return result; }
			int colCount = matrix[0].size();
			if (colCount == 0) { return result; }

			vector<vector<int>> dir = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
			vector<int> dirLen = { colCount, rowCount - 1 };
			int curDir = 0;
			int row = 0;
			int col = -1;
			while (dirLen[curDir % 2]) {
				for (int i = 0; i < dirLen[curDir % 2]; i++) {
					row += dir[curDir][0];
					col += dir[curDir][1];
					result.push_back(matrix[row][col]);
				}
				dirLen[curDir % 2]--;
				curDir = (curDir + 1) % 4;
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

