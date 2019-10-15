#include "stdafx.h"
#include <numeric>
//Given an array A of integers, we must modify the array in 
//the following way: we choose an i and replace A[i] with -A[i], 
//and we repeat this process K times in total.  
//(We may choose the same index i multiple times.)
//
//Return the largest possible sum of the array after modifying it in this way.
//
//Example 1:
//Input: A = [4,2,3], K = 1
//Output: 5
//Explanation: Choose indices (1,) and A becomes [4,-2,3].
//
//Example 2:
//Input: A = [3,-1,0,2], K = 3
//Output: 6
//Explanation: Choose indices (1, 2, 2) and A becomes [3,1,0,2].
//
//Example 3:
//Input: A = [2,-3,-1,5,-4], K = 2
//Output: 13
//Explanation: Choose indices (1, 4) and A becomes [2,3,-1,5,4].
// 
//Note:
//1 <= A.length <= 10000
//1 <= K <= 10000
//-100 <= A[i] <= 100 

namespace Solution2019
{
	namespace MaximizeSumOfArrayAfterKNegations
	{
		int largestSumAfterKNegations(vector<int>& A, int K) {
			sort(A.begin(), A.end());
			int len = A.size();
			for (int i = 0; i < len && A[i] < 0 && K > 0; i++) {
				A[i] = -A[i];
				K--;
			}

			int sum = accumulate(A.begin(), A.end(), 0);
			int smallest = *min_element(A.begin(), A.end());
			if (K % 2) { sum -= smallest * 2; }
			return sum;
		}

		void Main() {
			vector<int> test = { -8,3,-5,-3,-5,-2 };
			print(largestSumAfterKNegations(test, 6));
		}
	}
}

