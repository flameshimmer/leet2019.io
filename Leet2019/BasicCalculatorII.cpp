#include "stdafx.h"
//Implement a basic calculator to evaluate a simple expression string.
//
//The expression string contains only non-negative integers, +, -, *, 
/// operators and empty spaces . The integer division should truncate toward zero.
//
//Example 1:
//Input: "3+2*2"
//Output: 7
//
//Example 2:
//Input: " 3/2 "
//Output: 1
//
//Example 3:
//Input: " 3+5 / 2 "
//Output: 5
//
//Note:
//You may assume that the given expression is always valid.
//Do not use the eval built-in library function.

namespace Solution2019
{
	namespace BasicCalculatorII
	{
		int calculate(string s) {
			int len = s.size();
			if (len == 0) { return 0; }

			int result = 0;
			bool mul = false;
			bool div = false;
			bool isNeg = false;
			int prev = 0;
			for (int i = 0; i < len; i++) {
				char c = s[i];
				switch (c) {
				case '+':
					result += isNeg ? -prev : prev;
					isNeg = false;
				case ' ':
					break;
				case '-':
					result += isNeg ? -prev : prev;
					isNeg = true;
					break;
				case '*':
					mul = true;
					break;
				case '/':
					div = true;
					break;
				default:
					long long val = 0;
					while (i < len && isdigit(s[i])) {
						val = val * 10 + s[i] - '0';
						i++;
					}
					i--;
					if (mul) { prev *= val; }
					else if (div) { prev /= val; }
					else { prev = val; }
					mul = false;
					div = false;
				}
			}
			result += isNeg ? -prev : prev;
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

