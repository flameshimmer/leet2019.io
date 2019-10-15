#include "stdafx.h"
/*Given an unsorted integer array, find the 
smallest missing positive integer.

Example 1:
Input: [1,2,0]
Output: 3

Example 2:
Input: [3,4,-1,1]
Output: 2

Example 3:
Input: [7,8,9,11,12]
Output: 1

Note:
Your algorithm should run in O(n) time 
and uses constant extra space.*/ 

namespace Solution2019
{
	namespace FirstMissingPositive
	{
		int firstMissingPositive(vector<int>& A) {
			int len = A.size();

			for (int i = 0; i < len; i++) {
				while (A[i] > 0 && A[i] <= len && A[i] != A[A[i] - 1]) {
					swap(A[i], A[A[i] - 1]);
				}
			}

			for (int i = 0; i < len; i++) {
				if (A[i] != i + 1) {
					return i + 1;
				}
			}
			return len + 1;
		}

		int firstMissingPositiveAnother(vector<int>& A) {
			int len = A.size();
			if (len == 0) { return 1; }

			bool foundOne = false;
			for (int v : A) {
				if (v == 1) { foundOne = true; break; }
			}

			if (!foundOne) { return 1; }

			for (int i = 0; i < len; i++) {
				if (A[i] <= 0 || A[i] > len) { A[i] = 1; }
			}

			for (int i = 0; i < len; i++) {
				int v = abs(A[i]);
				if (v == len) { A[0] = -abs(A[0]); }
				else { A[v] = -abs(A[v]); }
			}

			// Note that need to check 1 to len-1 before checking 0!!!
			// after checking all, then check A[0]
			// because A[0] is representing position len.
			for (int i = 1; i < len; i++) {
				if (A[i] > 0) {
					return i;
				}
			}

			if (A[0] > 0) { return len; }
			return len + 1;
		}

		void Main() {
			vector<int> test = { 0,-1, 3, 1 };
			print(firstMissingPositiveAnother(test));
		}
	}
}

