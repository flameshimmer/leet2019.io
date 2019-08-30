#include "stdafx.h"
//Given numRows, generate the first numRows of Pascal's triangle.
//Input: 5
//Output:
//[
//     [1],
//    [1,1],
//   [1,2,1],
//  [1,3,3,1],
// [1,4,6,4,1]
//]

namespace Solution2019
{
	namespace PascalsTriangle
	{
		vector<vector<int>> generate(int numRows) {
			vector<vector<int>> result;
			if (numRows == 0) { return result; }
			result.push_back({1});

			for (int i = 1; i < numRows; i++) {
				vector<int> lastRow = result.back();
				vector<int> curRow;
				int len = lastRow.size();
				for (int j = 0; j <= len; j++)
				{
					curRow.push_back((j == len ? 0 :lastRow[j]) + (j-1<0 ? 0 : lastRow[j - 1]));
				}
				result.push_back(curRow);
			}
			return result;
		}
		void Main() {
			print(generate(5));
		}
	}
}

