#include "stdafx.h"

//Given an integer n, return the number of trailing zeroes in n!.
//
//Example 1:
//Input: 3
//Output: 0
//Explanation: 3! = 6, no trailing zero.
//
//Example 2:
//Input: 5
//Output: 1
//Explanation: 5! = 120, one trailing zero.
//
//Note: Your solution should be in logarithmic time complexity.

namespace Solution2019
{
	namespace FactorialTrailingZeroes
	{
		// 10 = 2*5, n! is not lack of 2, so result is bound by 5
		// 5 appears every 5 numbers. 
		// sometimes a number have many 5s as factor. Like 5^2, 5^3
		// So the question is the sum of how many numbers have 5 + 
		// how many number has 2 of 5 as factor + how many numbers 
		// have 3 of 5 factors
		int trailingZeroes(int n) {
			int count = 0;
			for (long long i = 5; n / i > 0; i *= 5) {
				count += n / i;
			}
			return count;
		}

		int trailingZeroesAnother(int n) {
			int count = 0;
			while (n != 0) {
				int temp = n / 5;
				count += temp;
				n = temp;
			}
			return count;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

