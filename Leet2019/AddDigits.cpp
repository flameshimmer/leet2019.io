#include "stdafx.h"
//Given a non-negative integer num, repeatedly add all 
//its digits until the result has only one digit.
//
//Example:
//
//Input: 38
//Output: 2 
//Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
//             Since 2 has only one digit, return it.
//Follow up:
//Could you do it without any loop/recursion in O(1) runtime?

namespace Solution2019
{
	namespace AddDigits
	{
		int addDigits(int num) {
			while (num >= 10) {
				int n = num;
				num = 0;
				while (n) {
					num += n % 10;
					n /= 10;
				}
			}
			return num;
		}

		int addDigitsFollowUp(int num) {
			if (num == 0) { return 0; }
			int result = num % 9;
			return result == 0 ? 9 : result;
		}

		int addDigitsFollowUp2(int num) {
			return 1 + (num - 1) % 9;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

