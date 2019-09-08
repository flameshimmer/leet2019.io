#include "stdafx.h"
//Given an array A of non-negative integers, return an array consisting 
//of all the even elements of A, followed by all the odd elements of A.
//
//You may return any answer array that satisfies this condition.
//
//Example 1:
//Input: [3,1,2,4]
//Output: [2,4,3,1]
//The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
// 
//Note:
//1 <= A.length <= 5000
//0 <= A[i] <= 5000
namespace Solution2019
{
	namespace SortArrayByParity
	{
		vector<int> SortArrayByParitySlow(vector<int>& A) {
			vector<int> result;
			for (int i : A) {
				if (i % 2 == 0) {
					result.insert(result.begin(), i);
				} else {
					result.push_back(i);
				}
			}
			return result;
		}

		vector<int> SortArrayByParity(vector<int>& A) {
			int start = 0;
			int end = A.size() - 1;
			while (start < end) {
				if (A[start] % 2) {
					int tmp = A[end];
					A[end] = A[start];
					A[start] = tmp;
					end--;
				}
				else { start++; }
			}
			return A;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

