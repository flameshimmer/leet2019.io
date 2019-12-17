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
		namespace Generic {

			long long calc(stack<long long>& num, stack<char>& op) {
				long long a = num.top();
				num.pop();
				long long b = num.top();
				num.pop();
				char c = op.top();
				op.pop();
				switch (c) {
				case '+': return b + a;
				case '-': return b - a;
				case '*': return b * a;
				case '/': return b / a;
				default: return 0;
				}
			}

			int calculate(string s) {
				unordered_map<char, int> map;
				map['('] = -1;
				map['+'] = 0;
				map['-'] = 0;
				map['*'] = 1;
				map['/'] = 1;

				stack<long long> num;
				stack<char> op;
				int len = s.size();
				for (int i = 0; i < len; i++) {
					char c = s[i];
					if (i == 0 && c == '-') {
						num.push(-1);
						op.push('*');
					}
					else if (isdigit(c)) {
						long long val = c - '0';
						while (i + 1 < len && isdigit(s[i + 1])) {
							val = 10 * val + (s[i + 1] - '0');
							i++;
						}
						num.push(val);
					}
					else if (c == ' ') {
						continue;
					}
					else if (c == '(') {
						op.push(c);
						if (i + 1 < len && s[i + 1] == '-' && i + 2 < len && isdigit(s[i + 2])) {
							num.push(-1);
							op.push('*');
							i++;
						}
					}
					else if (c == ')') {
						while (op.top() != '(') {
							num.push(calc(num, op));
						}
						op.pop();
					}
					else {
						while (!op.empty() && map[c] <= map[op.top()]) {
							num.push(calc(num, op));
						}
						op.push(c);
					}
				}

				while (!op.empty()) {
					num.push(calc(num, op));
				}
				return int(num.top());
			}

		}

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
			//print(Generic::calculate("-1+4*3/3/3"));
			//print(Generic::calculate("1 + 1"));
			print(Generic::calculate("0-2147483648"));
		}
	}
}

