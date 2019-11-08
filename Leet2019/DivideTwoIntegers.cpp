#include "stdafx.h"

//Given two integers dividend and divisor, divide two integers without using
//multiplication, division and mod operator.
//Return the quotient after dividing dividend by divisor.
//The integer division should truncate toward zero.
//
//Example 1:
//Input: dividend = 10, divisor = 3
//Output: 3
//
//Example 2:
//Input: dividend = 7, divisor = -3
//Output: -2
//
//Note:
//Both dividend and divisor will be 32-bit signed integers.
//The divisor will never be 0.
//Assume we are dealing with an environment which could only store integers
//within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose
//of this problem, assume that your function returns 231 − 1 when the division
//result overflows.

namespace Solution2019
{
	namespace DivideTwoIntegers
	{
		int divide(int A, int B) {
			if (A == INT_MIN && B == -1) { return INT_MAX; }
			long long a = labs(A);
			long long b = labs(B);
			long long result = 0;
			int sign = (A > 0) ^ (B> 0) ? -1 : 1;
			while (a >= b) {
				long long tmp = b;
				long long m = 1;
				while (a >= tmp << 1) {
					tmp <<= 1;
					m <<= 1;
				}
				a -= tmp;
				result += m;
			}
			return sign * result;
		}

		void Main() {
			string test = "tst test test";
			print(divide(-1, -1));
		}
	}
}

