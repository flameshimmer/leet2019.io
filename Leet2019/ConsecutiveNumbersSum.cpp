#include "stdafx.h"
//Given a positive integer N, how many ways can we write it as
//a sum of consecutive positive integers?
//
//Example 1:
//Input: 5
//Output: 2
//Explanation: 5 = 5 = 2 + 3
//
//Example 2:
//Input: 9
//Output: 3
//Explanation: 9 = 9 = 4 + 5 = 2 + 3 + 4
//
//Example 3:
//Input: 15
//Output: 4
//Explanation: 15 = 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
//Note: 1 <= N <= 10 ^ 9.

namespace Solution2019
{
	namespace ConsecutiveNumbersSum
	{
		//这道题的要求的另一种说法: 把N表示成一个等差数列（公差为1）的和
		//我们不妨设这个数列的首项是x，项数为m，则这个数列的和就是[x + (x + (m - 1))]m / 2 = mx + m(m - 1) / 2 = N
		//接下来，一个很自然的想法就是，枚举m，通过上式判断对于相应的m是否存在合法的x。
		//x = ((N - m(m - 1) / 2)) / m 
		//又可以写成 m*x = ((N - m(m - 1) / 2))
		//显然枚举的复杂度是O(sqrt(N))。因为m能取到的最大值显然是sqrt(n)数量级的
		int consecutiveNumbersSum(int N) {
			int result = 0;
			for (int m = 1;; m++) {
				int mx = N - m * (m - 1) / 2;
				if (mx <= 0) { break; }
				if (mx % m == 0) {
					result++;
				}
			}
			return result;
		}

		void Main() {
			print(consecutiveNumbersSum(5));
		}
	}
}

