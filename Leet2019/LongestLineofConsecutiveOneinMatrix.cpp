#include "stdafx.h"
//Given a 01 matrix M, find the longest line of consecutive one in 
//the matrix.The line could be horizontal, vertical, diagonal or anti - diagonal.
//Example:
//Input:
//[[0, 1, 1, 0],
//[0, 1, 1, 0],
//[0, 0, 0, 1]]
//Output : 3
//Hint : The number of elements in the given matrix will not exceed 10, 000.

namespace Solution2019
{
	namespace LongestLineofConsecutiveOneinMatrix
	{
		int longestLine(vector<vector<int>>& M) {
			int rowCount = M.size();
			if (rowCount == 0) { return 0; }
			int colCount = M[0].size();
			if (colCount == 0) { return 0; }

			int result = 0;
			vector<int> col(colCount, 0);
			vector<int> diag(rowCount + colCount, 0);
			vector<int> antiDiag(rowCount + colCount, 0);

			for (int i = 0; i < rowCount; i++) {
				int row = 0;
				for (int j = 0; j < colCount; j++) {
					if (M[i][j] == 1) {
						row++;
						col[j]++;
						diag[j - i + rowCount] ++; // + rowCount because j-i can be negative
						antiDiag[j + i]++;
						result = max(result, row);
						result = max(result, col[j]);
						result = max(result, diag[j - i + rowCount]);
						result = max(result, antiDiag[j + i]);
					}
					else {
						row = 0;
						col[j] = 0;
						diag[j - i + rowCount] = 0;
						antiDiag[j + i] = 0;
					}
				}
			}
			return result;
		}

		namespace DP {
			int longestLine(vector<vector<int>>& M) {
				int rowCount = M.size();
				if (rowCount == 0) { return 0; }
				int colCount = M[0].size();
				if (colCount == 0) { return 0; }

				vector<vector<vector<int>>> dp(rowCount, vector<vector<int>>(colCount, vector<int>(4, 0)));
				int result = 0;
				for (int i = 0; i < rowCount; i++) {
					for (int j = 0; j < colCount; j++) {
						if (M[i][j] == 0) { continue; }
						for (int k = 0; k < 4; k++) { dp[i][j][k] = 1; }

						if (j - 1 >= 0) { dp[i][j][0] += dp[i][j - 1][0]; }
						if (i - 1 >= 0 && j - 1 > 0) { dp[i][j][1] += dp[i - 1][j - 1][1]; }
						if (i - 1 >= 0) { dp[i][j][2] += dp[i - 1][j][2]; }
						if (i - 1 >= 0 && j + 1 < colCount) { dp[i][j][3] += dp[i - 1][j + 1][3]; }
						result = max(result, max(dp[i][j][0], dp[i][j][1]));
						result = max(result, max(dp[i][j][2], dp[i][j][3]));
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

