#include "stdafx.h"

//Given an array A of 0s and 1s, we may change up to K values from 0 to 1.
//Return the length of the longest (contiguous) subarray that contains only 1s. 
// 
//
//Example 1:
//Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
//Output: 6
//Explanation: 
//[1,1,1,0,0,1,1,1,1,1,1]
//Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.
//
//Example 2:
//Input: A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
//Output: 10
//Explanation: 
//[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
//Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.
// 
//
//Note:
//1 <= A.length <= 20000
//0 <= K <= A.length
//A[i] is 0 or 1  

namespace Solution2019
{
	namespace MaxConsecutiveOnesIII
	{
		int longestOnes(vector<int>& A, int K) {
			int len = A.size();
			if (len == 0) { return 0; }

			int result = 0;
			int start = 0;
			for (int end = 0; end < len; end++) {
				if (A[end] == 0) { K--; }
				while (K < 0) {
					if (A[start] == 0) { K++; }
					start++;
				}
				result = max(result, end - start + 1);
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

