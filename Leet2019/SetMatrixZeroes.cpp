#include "stdafx.h"
//Given a m x n matrix, if an element is 0, 
//set its entire row and column to 0. Do it in-place.
//
//Example 1:
//Input: 
//[
//  [1,1,1],
//  [1,0,1],
//  [1,1,1]
//]
//Output: 
//[
//  [1,0,1],
//  [0,0,0],
//  [1,0,1]
//]
//
//Example 2:
//Input: 
//[
//  [0,1,2,0],
//  [3,4,5,2],
//  [1,3,1,5]
//]
//Output: 
//[
//  [0,0,0,0],
//  [0,4,5,0],
//  [0,3,1,0]
//]
//Follow up:
//
//A straight forward solution using O(mn) 
//space is probably a bad idea.
//A simple improvement uses O(m + n) space, 
//but still not the best solution.
//Could you devise a constant space solution?

namespace Solution2019
{
	namespace SetMatrixZeroes
	{
		void setZeroes(vector<vector<int>>& matrix) {
			int rowCount = matrix.size();
			if (rowCount == 0) { return; }
			int colCount = matrix[0].size();
			if (colCount == 0) { return; }

			bool firstRowZero = false;
			for (int i = 0; i < colCount; i++) {
				if (matrix[0][i] == 0) { firstRowZero = true; break; }
			}
			bool firstColZero = false;
			for (int i = 0; i < rowCount; i++) {
				if (matrix[i][0] == 0) { firstColZero = true; break; }
			}

			for (int i = 1; i < rowCount; i++) {
				for (int j = 1; j < colCount; j++) {
					if (matrix[i][j] == 0) {
						matrix[0][j] = 0;
						matrix[i][0] = 0;
					}
				}
			}

			for (int i = 1; i < rowCount; i++) {
				for (int j = 1; j < colCount; j++) {
					if (matrix[0][j] == 0 || matrix[i][0] == 0) {
						matrix[i][j] = 0;
					}
				}
			}
			if (firstRowZero) {
				for (int i = 0; i < colCount; i++) { matrix[0][i] = 0; }
			}
			if (firstColZero) {
				for (int i = 0; i < rowCount; i++) { matrix[i][0] = 0; }
			}
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

