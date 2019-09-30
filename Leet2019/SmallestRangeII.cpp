#include "stdafx.h"
//Given an array A of integers, for each integer A[i]
//we need to choose either x = -K or x = K, and add 
//x to A[i] (only once).
//
//After this process, we have some array B.
//
//Return the smallest possible difference between the 
//maximum value of B and the minimum value of B.
//
//Example 1:
//Input: A = [1], K = 0
//Output: 0
//Explanation: B = [1]
//
//Example 2:
//Input: A = [0,10], K = 2
//Output: 6
//Explanation: B = [2,8]
//
//Example 3:
//Input: A = [1,3,6], K = 3
//Output: 3
//Explanation: B = [4,6,3]
// 
//Note:
//1 <= A.length <= 10000
//0 <= A[i] <= 10000
//0 <= K <= 10000

namespace Solution2019
{
	namespace SmallestRangeII
	{
		int smallestRangeII(vector<int>& A, int K) {
			int len = A.size();
			sort(A.begin(), A.end());
			int result = A[len - 1] - A[0];

			for (int i = 0; i < len - 1; i++) {
				int high = max(A[len - 1] - K, A[i] + K);
				int low = min(A[0] + K, A[i + 1] - K);
				result = min(result, high - low);
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

