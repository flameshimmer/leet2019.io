#include "stdafx.h"
//Implement a basic calculator to evaluate a simple expression string.
//
//The expression string may contain open ( and closing parentheses ), 
//the plus + or minus sign -, non-negative integers and empty spaces .
//
//Example 1:
//Input: "1 + 1"
//Output: 2
//
//Example 2:
//Input: " 2-1 + 2 "
//Output: 3
//
//Example 3:
//Input: "(1+(4+5+2)-3)+(6+8)"
//Output: 23
//
//Note:
//You may assume that the given expression is always valid.
//Do not use the eval built-in library function.

namespace Solution2019
{
	namespace BasicCalculator
	{
		namespace SignManipulation {
			int calculate(string s) {
				int len = s.size();
				if (len == 0) { return 0; }

				int local = 1;
				int global = 1;
				int result = 0;
				stack<int> stack;
				for (int i = 0; i < len; i++) {
					char c = s[i];
					switch (c) {
					case '+':
					case ' ':
						break;
					case '-':
						local = -1;
						break;
					case '(':
						global *= local;
						stack.push(local);
						local = 1;
						break;
					case ')':
						global /= stack.top();
						stack.pop();
						local = 1;
						break;
					default:
						long long val = 0;
						while (i < len && isdigit(s[i])) {
							val = val * 10 + s[i] - '0';
							i++;
						}
						i--;
						result += local * global * val;
						local = 1;
					}
				}
				return result;
			}
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

