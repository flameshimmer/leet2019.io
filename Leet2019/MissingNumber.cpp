#include "stdafx.h"
//Given an array containing n distinct numbers taken from
//0, 1, 2, ..., n, find the one that is missing from the array.
//
//Example 1:
//Input: [3,0,1]
//Output: 2
//
//Example 2:
//Input: [9,6,4,2,3,5,7,0,1]
//Output: 8
//
//Note:
//Your algorithm should run in linear runtime complexity. 
//Could you implement it using only constant extra space complexity?

namespace Solution2019
{
	namespace MissingNumber
	{
		int MissingNumber(vector<int>& A) {
			int len = A.size();
			int sum = 0;
			for (int i : A) { sum += i; }
			int expected = (0 + len) * (len + 1) / 2;
			return expected - sum;
		}
		int MissingNumberBitManipulation(vector<int>& A) {
			int len = A.size();
			int result = len;
			for (int i = 0; i < len; i ++ ) {
				result ^= i ^ A[i];
			}
			return result;
		}

		void Main() {
			vector<int> test = { 9,6,4,2,3,5,7,0,1 };
			print(MissingNumberBitManipulation(test));
		}
	}
}

