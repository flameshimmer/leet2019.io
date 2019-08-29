#include "stdafx.h"
//Implement int sqrt(int x).
//
//Compute and return the square root of x, where x is 
//guaranteed to be a non-negative integer.
//
//Since the return type is an integer, the decimal digits are
//truncated and only the integer part of the result is returned.
//
//Example 1:
//Input: 4
//Output: 2
//
//Example 2:
//Input: 8
//Output: 2
//
//Explanation: The square root of 8 is 2.82842..., and since 
//             the decimal part is truncated, 2 is returned.

namespace Solution2019
{
	namespace Sqrt
	{
		int Sqrt(int x) {
			if (x < 2) { return x; }
			long long start = 1; 
			long long end = x;
			while (start <= end) {
				long long mid = start + (end - start) / 2;
				long long sq = mid* mid;
				if (sq == x) { return mid; }
				else if (sq < x) { start = mid + 1; }
				else { end = mid - 1; }
			}
			return end;
		}

		int SqrtRecursion(int x) {
			if (x < 2) { return x; }
			int left = SqrtRecursion(x >> 2) << 1;
			int right = left + 1;
			return (long long)right*right > x ? left : right;		
		}

		int SqrtNewtonsMethod(int x) {
			if (x < 2) { return x; }
			double x0 = x;
			double x1 = (x0 + x / x0) / 2.0;
			while (abs(x0 - x1) >= 1) {
				x0 = x1;
				x1 = (x0 + x / x0) / 2.0;
			}	
			return (int)x1;
		}

		void Main() {
			string test = "tst test test";
			
			print(Sqrt(INT_MIN));
			print(Sqrt(8));
			print(Sqrt(4));
		}
	}
}

