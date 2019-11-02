#include "stdafx.h"

//Implement pow(x, n), which calculates x raised to the power n (xn).
//
//Example 1:
//Input: 2.00000, 10
//Output: 1024.00000
//
//Example 2:
//Input: 2.10000, 3
//Output: 9.26100
//
//Example 3:
//Input: 2.00000, -2
//Output: 0.25000
//Explanation: 2-2 = 1/22 = 1/4 = 0.25
//
//Note:
//-100.0 < x < 100.0
//n is a 32-bit signed integer, within the range [−231, 231 − 1]

namespace Solution2019
{
	namespace Pow
	{
		double myPowIterative(double x, int n) {
			double result = 1;
			long long p = n;
			if (p < 0) {
				p = -p;
				x = 1 / x;
			}
			while (p) {
				// x will be mutliplied twice if p is odd
				// x will be multipled once if p is even
				if (p % 2 == 1) { result *= x; }
				x *= x;
				p /= 2;
			}
			return result;
		}

		double myPow(double x, int n) {
			if (n == 0) { return 1; }

			long long n2 = n;
			if (n2 < 0) {
				n2 = -n2;
				x = 1 / x;
			}
			return (n % 2 == 0) ? myPow(x * x, n2 / 2) : x * myPow(x * x, n2 / 2);
		}


		void Main() {
			string test = "tst test test";
			print(myPowIterative(2, 4));
		}
	}
}

