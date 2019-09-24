#include "stdafx.h"
//Given an array A of positive integers (not necessarily distinct), 
//return the lexicographically largest permutation that is smaller 
//than A, that can be made with one swap (A swap exchanges the 
//positions of two numbers A[i] and A[j]).  If it cannot be done, 
//then return the same array.
//
//Example 1:
//Input: [3,2,1]
//Output: [3,1,2]
//Explanation: Swapping 2 and 1.
//
//Example 2:
//Input: [1,1,5]
//Output: [1,1,5]
//Explanation: This is already the smallest permutation.
//
//Example 3:
//Input: [1,9,4,6,7]
//Output: [1,7,4,6,9]
//Explanation: Swapping 9 and 7.
//
//Example 4:
//Input: [3,1,1,3]
//Output: [1,3,1,3]
//Explanation: Swapping 1 and 3.
// 
//Note:
//1 <= A.length <= 10000
//1 <= A[i] <= 10000
namespace Solution2019
{
	namespace PreviousPermutationWithOneSwap
	{
		vector<int> prevPermOpt1(vector<int>& A) {
			int len = A.size();
			int i = len - 2;
			while (i >= 0 && A[i] <= A[i + 1]) { i--; }

			if (i < 0) { return A; }

			int j = len - 1;
			while (A[i] <= A[j]) { j--; }
			while (A[j] == A[j - 1]) { j--; }
			swap(A[i], A[j]);
			return A;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

