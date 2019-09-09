#include "stdafx.h"
//Given an array A of non-negative integers, half of 
//the integers in A are odd, and half of the integers are even.
//
//Sort the array so that whenever A[i] is odd, i is odd; 
//and whenever A[i] is even, i is even.
//
//You may return any answer array that satisfies this condition.
//
//
//Example 1:
//Input: [4,2,5,7]
//Output: [4,5,2,7]
//Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
// 
//Note:
//2 <= A.length <= 20000
//A.length % 2 == 0
//0 <= A[i] <= 1000

namespace Solution2019
{
	namespace SortArrayByParityII
	{
		vector<int> SortArrayByParityII(vector<int>& A) {
			int end = 1;
			for (int start = 0;start < A.size(); start += 2) {
				if (A[start] % 2 != 0) {
					while (A[end] % 2 == 1) { end += 2; }

					int tmp = A[start];
					A[start] = A[end];
					A[end] = tmp;
				}
			}
			return A;
		}

		void Main() {
			string test = "tst test test";
			vector<int> A = { 4, 2, 5, 7 };
			print(SortArrayByParityII(A));
		}
	}
}

