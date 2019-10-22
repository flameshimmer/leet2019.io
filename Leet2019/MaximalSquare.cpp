#include "stdafx.h"
//Given a 2D binary matrix filled with 0's and 1's, find the largest 
//square containing only 1's and return its area.
//
//Example:
//
//Input:
//
//1 0 1 0 0
//1 0 1 1 1
//1 1 1 1 1
//1 0 0 1 0
//
//Output : 4

namespace Solution2019
{
	namespace MaximalSquare
	{
		int maximalSquare(vector<vector<char>>& matrix) {
			int rowCount = matrix.size();
			if (rowCount == 0) { return 0; }
			int colCount = matrix[0].size();
			if (colCount == 0) { return 0; }

			vector<vector<int>> M(rowCount, vector<int>(colCount, 0));

			int result = 0;
			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					M[i][j] = matrix[i][j] - '0';
					if (M[i][j] == 0) { continue; }
					if (i > 0 && j > 0) {
						M[i][j] = min(min(M[i - 1][j], M[i][j - 1]), M[i - 1][j - 1]) + 1;
					}
					result = max(result, M[i][j] * M[i][j]);
				}
			}
			return result;
		}

		int maximalSquareAnother(vector<vector<char>>& matrix) {
			int rowCount = matrix.size();
			if (rowCount == 0) { return 0; }
			int colCount = matrix[0].size();
			if (colCount == 0) { return 0; }

			vector<vector<int>> sums(rowCount + 1, vector<int>(colCount + 1, 0));
			for (int i = 1; i < rowCount + 1; i++) {
				for (int j = 1; j < colCount + 1; j++) {
					sums[i][j] = matrix[i - 1][j - 1] - '0'
						+ sums[i - 1][j]
						+ sums[i][j - 1]
						- sums[i - 1][j - 1];

				}
			}

			int result = 0;
			for (int i = 1; i < rowCount + 1; i++) {
				for (int j = 1; j < colCount + 1; j++) {
					for (int k = min(rowCount + 1 - i, colCount + 1 - j); k > 0; k--) {
						int sum = sums[i + k - 1][j + k - 1]
							- sums[i + k - 1][j - 1]
							- sums[i - 1][j + k - 1]
							+ sums[i - 1][j - 1];
						if (sum == k * k) {
							result = max(result, sum);
						}
					}
				}
			}
			return result;
		}
		void Main() {
			vector<vector<char>> test = { {'1', '1'} };
			print(maximalSquare(test));
		}
	}
}

