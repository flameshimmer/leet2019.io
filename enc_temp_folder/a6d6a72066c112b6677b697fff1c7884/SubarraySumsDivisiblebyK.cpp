#include "stdafx.h"
//Given an array A of integers, return the number of 
//(contiguous, non-empty) subarrays that have a sum 
//divisible by K.
//
//Example 1:
//
//Input: A = [4,5,0,-2,-3,1], K = 5
//Output: 7
//Explanation: There are 7 subarrays with a sum
//divisible by K = 5:
//[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
// 
//Note:
//1 <= A.length <= 30000
//-10000 <= A[i] <= 10000
//2 <= K <= 10000

namespace Solution2019
{
	namespace SubarraySumsDivisiblebyK
	{
		int subarraysDivByK(vector<int>& A, int K) {
			int len = A.size();
			for (int i = 1; i < len; i++) {
				A[i] += A[i - 1];
			}

			vector<int> count(K, 0);
			for (int i = 0; i < len; i++) {
				count[(A[i] % K + K) % K]++;
			}


			int result = count[0];
			for (int i = 1; i < K; i++) {
				result += count[i] * (count[i] - 1) / 2;
			}
			return result;
		}

		void Main() {
			vector<int> test = { 8,9,7, 8, 9};
			print(subarraysDivByK(test, 8));
		}
	}
}

