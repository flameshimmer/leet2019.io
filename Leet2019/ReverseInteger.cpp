#include "stdafx.h"
//Given a 32-bit signed integer, reverse digits of an integer.
//
//Example 1:
//Input: 123
//Output: 321

//Example 2:
//Input: -123
//Output: -321

//Example 3:
//Input: 120
//Output: 21
//Note:
//Assume we are dealing with an environment which could only store integers 
//within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of
//this problem, assume that your function returns 0 when the reversed integer overflows.

namespace Solution2019
{
	namespace ReverseInteger
	{
		int ReverseIntegerWithLonglong(int val) {
			long long result = 0;
			while (val != 0) {
				result = result * 10 + val % 10;
				val /= 10;
			}
			if (result > INT_MAX || result < INT_MIN) { return 0; }
			return (int)result;
		}

		int ReverseInteger(int val) {
			int result = 0;
			while (val != 0) {
				int remain = val % 10;
				val /= 10;
				if (result > INT_MAX / 10 || result == INT_MAX / 10 && remain > 7) { return 0; }
				if (result < INT_MIN / 10 || result == INT_MIN / 10 && remain < -8) { return 0; }
				result = result * 10 + remain;
			}
			return result;
		}
		
		void Main() {
			string test = "tst test test";
			print(ReverseInteger(123));
			print(ReverseInteger(-123));
			print(ReverseInteger(120));
		}
	}
}

