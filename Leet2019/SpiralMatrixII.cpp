#include "stdafx.h"
//Given a positive integer n, generate a square matrix filled 
//with elements from 1 to n2 in spiral order.
//
//Example:
//
//Input: 3
//Output:
//[
// [ 1, 2, 3 ],
// [ 8, 9, 4 ],
// [ 7, 6, 5 ]
//]
namespace Solution2019
{
	namespace SpiralMatrixII
	{
		vector<vector<int>> generateMatrix(int n) {
			vector<vector<int>> result(n, vector<int>(n, 0));
			vector<vector<int>> dir = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
			vector<int> distance = { n, n - 1 };
			int curDir = 0;
			int row = 0;
			int col = -1;
			int i = 1;
			while (distance[curDir % 2]) {
				for (int j = 0; j < distance[curDir % 2]; j++) {
					row += dir[curDir][0];
					col += dir[curDir][1];
					result[row][col] = i;
					i++;
				}
				distance[curDir % 2]--;
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

