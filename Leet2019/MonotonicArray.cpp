#include "stdafx.h"
//An array is monotonic if it is either monotone increasing or monotone decreasing.
//
//An array A is monotone increasing if for all i <= j, A[i] <= A[j].An array A is monotone decreasing if for all i <= j, A[i] >= A[j].
//
//Return true ifand only if the given array A is monotonic.
//
//
//
//Example 1:
//
//Input: [1, 2, 2, 3]
//	Output : true
//	Example 2 :
//
//	Input : [6, 5, 4, 4]
//	Output : true
//	Example 3 :
//
//	Input : [1, 3, 2]
//	Output : false
//	Example 4 :
//
//	Input : [1, 2, 4, 5]
//	Output : true
//	Example 5 :
//
//	Input : [1, 1, 1]
//	Output : true
//
//
//	Note :
//
//	1 <= A.length <= 50000
//	- 100000 <= A[i] <= 100000

namespace Solution2019
{
	namespace MonotonicArray
	{
		bool isMonotonic(vector<int>& A) {
			int len = A.size();
			if (len < 2) { return true; }

			int trend = 0;
			for (int i = 1; i < len; i++) {
				if (A[i] != A[i - 1]) {
					if (trend == 0) { trend = A[i] > A[i - 1] ? 1 : -1; }
					else if (trend == 1 && A[i] < A[i - 1]) { return false; }
					else if (trend == -1 && A[i] > A[i - 1]) { return false; }
				}
			}
			return true;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

