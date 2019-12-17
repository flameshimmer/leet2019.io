#include "stdafx.h"

//Given two sparse matrices A and B, return the result of AB.
//You may assume that A's column number is equal to B's row number.
//
//Example:
//Input:
//A = [
//  [ 1, 0, 0],
//  [-1, 0, 3]
//]
//B = [
//  [ 7, 0, 0 ],
//  [ 0, 0, 0 ],
//  [ 0, 0, 1 ]
//]
//Output:
//     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
//AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
//                  | 0 0 1 |

namespace Solution2019
{
	namespace SparseMatrixMultiplication
	{
		vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
			int rowCountA = A.size();
			if (rowCountA == 0) { return B; }
			int colCountA = A[0].size();
			if (colCountA == 0) { return {}; }
			int colCountB = B[0].size();
			if (colCountB == 0) { return A; }

			vector<vector<int>> result(rowCountA, vector<int>(colCountB, 0));

			for (int i = 0; i < rowCountA; i++) {
				for (int k = 0; k < colCountA; k++) {
					if (A[i][k] != 0) {
						for (int j = 0; j < colCountB; j++) {
							if (B[k][j] != 0) {
								result[i][j] += A[i][k] * B[k][j];
							}
						}
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

