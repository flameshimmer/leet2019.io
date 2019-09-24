#include "stdafx.h"
//Given two integer arrays A and B, return the maximum
//length of an subarray that appears in both arrays.
//
//Example 1:
//
//Input:
//A: [1,2,3,2,1]
//B: [3,2,1,4,7]
//Output: 3
//Explanation: 
//The repeated subarray with maximum length is [3, 2, 1].
// 
//
//Note:
//
//1 <= len(A), len(B) <= 1000
//0 <= A[i], B[i] < 100

namespace Solution2019
{
	namespace MaximumLengthofRepeatedSubarray
	{

		int findLength(vector<int>& A, vector<int>& B) {
			int lenA = A.size();
			int lenB = B.size();
			if (lenA == 0 || lenB == 0) { return 0; }

			int result = 0;
			vector<vector<int>> dp(lenA + 1, vector<int>(lenB + 1, 0));
			for (int i = 1; i < lenA+1; i++) {
				for (int j = 1; j < lenB+1; j++) {
					if (A[i-1] == B[j-1]) {
						dp[i][j] = dp[i - 1][j - 1] + 1;
						result = max(result, dp[i][j]);
					}
				}
			}
			return result;
		}
		void Main() {
			vector<int> A = { 1,2,3,2,1 };
			vector<int> B = { 3,2,1,4,7 };
			print(findLength(A, B));
		}
	}
}

