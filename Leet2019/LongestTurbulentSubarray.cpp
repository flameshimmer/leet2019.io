#include "stdafx.h"
//A subarray A[i], A[i+1], ..., A[j] of A is said to be turbulent if and only if:
//
//For i <= k < j, A[k] > A[k+1] when k is odd, and A[k] < A[k+1] when k is even;
//OR, for i <= k < j, A[k] > A[k+1] when k is even, and A[k] < A[k+1] when k is odd.
//That is, the subarray is turbulent if the comparison sign 
//flips between each adjacent pair of elements in the subarray.
//
//Return the length of a maximum size turbulent subarray of A.
//
//Example 1:
//Input: [9,4,2,10,7,8,8,1,9]
//Output: 5
//Explanation: (A[1] > A[2] < A[3] > A[4] < A[5])
//
//Example 2:
//Input: [4,8,12,16]
//Output: 2
//
//Example 3:
//Input: [100]
//Output: 1
// 
//Note:
//1 <= A.length <= 40000
//0 <= A[i] <= 10^9

namespace Solution2019
{
	namespace LongestTurbulentSubarray
	{
		int maxTurbulenceSize(vector<int>& A) {
			int len = A.size();
			if (len < 2) { return len; }

			int start = 0;
			int end = 1;
			int result = 1;
			while (end < len) {
				long diff = A[end] - A[end - 1];
				if (diff == 0) { start = end; }
				else if (end == len - 1 || (diff * (A[end + 1] - A[end]) >= 0)) {
					result = max(result, end - start + 1);
					start = end;
				}
				end++;
			}
			return result;
		}

		namespace DP {
			int maxTurbulenceSize(vector<int>& A) {
				int len = A.size();
				if (len < 2) { return len; }

				vector<int> greater(len, 1);
				vector<int> lesser(len, 1);

				for (int i = len - 2; i >= 0; i--) {
					if (A[i] > A[i + 1]) {
						greater[i] = lesser[i + 1] + 1;
					}
					else if (A[i] < A[i + 1]) {
						lesser[i] = greater[i + 1] + 1;
					}
				}

				int result = 0;
				for (int i = 0; i < len; i++) {
					result = max(result, max(greater[i], lesser[i]));
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

