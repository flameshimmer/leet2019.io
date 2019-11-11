#include "stdafx.h"

//You have 4 cards each containing a number from 1 to 9. You need to judge
//whether they could operated through *, /, +, -, (, ) to get the value of 24.
//
//Example 1:
//Input: [4, 1, 8, 7]https://leetcode.com/problems/24-game/solution/
//Output: True
//Explanation: (8-4) * (7-1) = 24https://leetcode.com/problems/24-game/solution/
//
//Example 2:
//Input: [1, 2, 1, 2]
//Output: False
//
//Note:
//The division operator / represents real division, not integer division. For
//example, 4 / (1 - 2/3) = 12.
//Every operation done is between two numbers. In particular, we cannot use - as
//a unary operator. For example, with [1, 1, 1, 1] as input, the expression -1 -
//1 - 1 - 1 is not allowed.
//You cannot concatenate numbers together. For example, if the input is [1, 2, 1,
//2], we cannot write this as 12 + 12.

namespace Solution2019
{
	namespace TwoFourGame
	{
		vector<double> combine(double a, double b) {
			return { a / b, b / a, a + b, a - b, b - a, a * b };
		}

		bool judgePoint24(vector<int>& nums) {
			const double eps = 1e-4;
			vector<int> id = { 0, 1, 2, 3 };
			do {
				int a = nums[id[0]];
				int b = nums[id[1]];
				int c = nums[id[2]];
				int d = nums[id[3]];
				for (auto x : combine(a, b)) {
					for (auto y : combine(c, d)) {
						for (auto z : combine(x, y)) {
							if (abs(z - 24) < eps) { return true; }
						}
					}
				}

				for (auto x : combine(a, b)) {
					for (auto y : combine(x, c)) {
						for (auto z : combine(y, d)) {
							if (abs(z - 24) < eps) { return true; }
						}
					}
				}
			} while (next_permutation(id.begin(), id.end()));
			return false;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

