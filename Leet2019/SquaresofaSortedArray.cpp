#include "stdafx.h"
//Given an array of integers A sorted in non-decreasing order, 
//return an array of the squares of each number, also in sorted non-decreasing order.
//
//Example 1:
//Input: [-4,-1,0,3,10]
//Output: [0,1,9,16,100]
//
//Example 2:
//Input: [-7,-3,2,3,11]
//Output: [4,9,9,49,121]
// 
//Note:
//1 <= A.length <= 10000
//-10000 <= A[i] <= 10000
//A is sorted in non-decreasing order.

namespace Solution2019
{
	vector<int> sortedSquaresSlow(vector<int>& A) {
		for (int i = 0; i < A.size(); i++) {
			A[i] = A[i] * A[i];
		}
		sort(A.begin(), A.end());
		return A;
	}

	vector<int> sortedSquares(vector<int>& A) {
		int len = A.size();
		vector<int> result(len);
		int start = 0;
		int end = len - 1;
		int i = len - 1;
		while (start <= end) {
			int s1 = A[start] * A[start];
			int s2 = A[end] * A[end];
			if (s1 >= s2) {
				result[i] = s1;
				start++;
			}
			else {
				result[i] = s2;
				end--;
			}
			i--;
		}
		return result;
	}
	namespace SquaresofaSortedArray
	{
		void Main() {
			string test = "tst test test";
			vector<int> A = { -4, -1, 0, 3, 10 };
			print(sortedSquares(A));
			A = { -7,-3,2,3,11 };
			print(sortedSquares(A));
		}
	}
}

