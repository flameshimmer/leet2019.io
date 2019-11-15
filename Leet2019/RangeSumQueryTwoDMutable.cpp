#include "stdafx.h"

//Given a 2D matrix matrix, find the sum of the elements inside the rectangle
//defined by its upper left corner (row1, col1) and lower right corner (row2,
//col2).
//Range Sum Query 2D
//The above rectangle (with the red border) is defined by (row1, col1) = (2, 1)
//and (row2, col2) = (4, 3), which contains sum = 8.
//
//Example:
//Given matrix = [
//  [3, 0, 1, 4, 2],
//  [5, 6, 3, 2, 1],
//  [1, 2, 0, 1, 5],
//  [4, 1, 0, 1, 7],
//  [1, 0, 3, 0, 5]
//]
//sumRegion(2, 1, 4, 3) -> 8
//sumRegion(1, 1, 2, 2) -> 11
//sumRegion(1, 2, 2, 4) -> 12
//
//Note:
//You may assume that the matrix does not change.
//There are many calls to sumRegion function.
//You may assume that row1 ≤ row2 and col1 ≤ col2.

namespace Solution2019
{
	namespace RangeSumQueryTwoDMutable
	{
		class NumMatrix {
		private:
			vector<vector<int>> m;
			int a(int i, int j) {
				return (i >= 0 && j >= 0) ? m[i][j] : 0;
			}
		public:
			NumMatrix(vector<vector<int>>& matrix) {
				m = matrix;
				for (int i = 0; i < m.size(); i++) {
					for (int j = 0; j < m[0].size(); j++) {
						m[i][j] += a(i - 1, j) + a(i, j - 1) - a(i - 1, j - 1);
					}
				}
			}

			int sumRegion(int row1, int col1, int row2, int col2) {
				return a(row2, col2) - a(row1 - 1, col2) - a(row2, col1 - 1) + a(row1 - 1, col1 - 1);
			}
		};

		void Main() {
			vector<vector<int>> test = { {3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5} };
			NumMatrix* obj = new NumMatrix(test);
			print(obj->sumRegion(2, 1, 4, 3));

		}
	}
}

