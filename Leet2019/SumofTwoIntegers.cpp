#include "stdafx.h"
//Calculate the sum of two integers a and b, but you are 
//not allowed to use the operator + and -.
//
//Example 1:
//Input: a = 1, b = 2
//Output: 3
//
//Example 2:
//Input: a = -2, b = 3
//Output: 1

namespace Solution2019
{
	namespace SumofTwoIntegers
	{
		int getSum(int a, int b) {
			long long carry; // 64-bit
			while (b != 0) {
				carry = a & b;
				a = a ^ b;
				b = ((carry & 0xffffffff) << 1); // limited to 32 bits
			}
			return a;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

