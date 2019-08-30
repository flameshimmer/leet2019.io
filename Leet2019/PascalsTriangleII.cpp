#include "stdafx.h"
//Given a non-negative index k where k ≤ 33, return 
//the kth index row of the Pascal's triangle.
//
//Note that the row index starts from 0.
//
//In Pascal's triangle, each number is the sum of the two numbers directly above it.
//     [1],
//    [1,1],
//   [1,2,1],
//  [1,3,3,1],
// [1,4,6,4,1]
//
//Example:
//Input: 3
//Output: [1,3,3,1]
//Follow up:
//
//Could you optimize your algorithm to use only O(k) extra space?

namespace Solution2019
{
	namespace PascalsTriangleII
	{
		vector<int> PascalsTriangleII(int rowIndex)
		{
			vector<int> result(rowIndex + 1, 1);
			for (int i = 2; i <= rowIndex; i++) {
				for (int j = i - 1; j >= 1; j--) {
					result[j] += result[j - 1];
				}
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(PascalsTriangleII(3));
		}
	}
}

