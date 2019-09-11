#include "stdafx.h"
//Given a matrix A, return the transpose of A.
//
//The transpose of a matrix is the matrix flipped over it's main
//diagonal, switching the row and column indices of the matrix.
//
//Example 1:
//Input: [[1,2,3],[4,5,6],[7,8,9]]
//Output: [[1,4,7],[2,5,8],[3,6,9]]
//
//Example 2:
//Input: [[1,2,3],[4,5,6]]
//Output: [[1,4],[2,5],[3,6]]
//
//Note:
//1 <= A.length <= 1000
//1 <= A[0].length <= 1000

namespace Solution2019
{
	namespace TransposeMatrix
	{
		vector<vector<int>> transpose(vector<vector<int>>& A) {
			int rowCount = A.size();
			int colCount = A[0].size();
			vector<vector<int>> result(colCount, vector<int>(rowCount, 0));
			for (int row = 0; row < rowCount; row++) {
				for (int col = 0; col < colCount; col++) {
					result[col][row] = A[row][col];					
				}
			}
			return result;
		}
		void Main() {
			vector<vector<int>> A = { {5}, {8} };
			transpose(A);
		}
	}
}

