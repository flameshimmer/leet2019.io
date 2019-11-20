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
//update(3, 2, 2)
//sumRegion(2, 1, 4, 3) -> 10
//
//Note:
//The matrix is only modifiable by the update function.
//You may assume the number of calls to update and sumRegion function is
//distributed evenly.
//You may assume that row1 ≤ row2 and col1 ≤ col2.

namespace Solution2019
{
	namespace RangeSumQueryTwoDMutable
	{
		class NumMatrix {
			vector<vector<int>> tree;
			vector<vector<int>> num;
			int rowCount;
			int colCount;
		public:
			NumMatrix(vector<vector<int>>& matrix) : num(matrix) {
				rowCount = matrix.size();
				if (rowCount == 0) { return; }
				colCount = matrix[0].size();
				if (colCount == 0) { return; }

				tree = vector<vector<int>>(rowCount + 1, vector<int>(colCount + 1, 0));
				for (int i = 0; i < rowCount; i++) {
					for (int j = 0; j < colCount; j++) {
						updateTree(i + 1, j + 1, num[i][j]);
					}
				}
			}

			void update(int row, int col, int val) {
				updateTree(row + 1, col + 1, val - num[row][col]);
				num[row][col] = val;
			}

			int sumRegion(int row1, int col1, int row2, int col2) {
				return query(row2 + 1, col2 + 1) - query(row1, col2 + 1) - query(row2 + 1, col1) + query(row1, col1);
			}

			void updateTree(int row, int col, int val) {
				for (int i = row; i <= rowCount; i += i & (-i)) {
					for (int j = col; j <= colCount; j += j & (-j)) {
						tree[i][j] += val;
					}
				}
			}
			int query(int row, int col) {
				int sum = 0;
				for (int i = row; i > 0; i -= i & (-i)) {
					for (int j = col; j > 0; j -= j & (-j)) {
						sum += tree[i][j];
					}
				}
				return sum;
			}
		};

		/**
		 * Your NumMatrix object will be instantiated and called as such:
		 * NumMatrix* obj = new NumMatrix(matrix);
		 * obj->update(row,col,val);
		 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
		 */
		void Main() {
			vector<vector<int>> test = { {3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5} };
			NumMatrix* obj = new NumMatrix(test);
			print(obj->sumRegion(2, 1, 4, 3));
		}
	}
}

