#include "stdafx.h"
//Given a string containing just the characters '(' and ')', find the
//length of the longest valid (well-formed) parentheses substring.
//
//Example 1:
//Input: "(()"
//Output: 2
//Explanation: The longest valid parentheses substring is "()"
//
//Example 2:
//Input: ")()())"
//Output: 4
//Explanation: The longest valid parentheses substring is "()()"

namespace Solution2019
{
	namespace LongestValidParentheses
	{
		int longestValidParentheses(string s) {
			int len = s.size();
			if (len < 2) { return 0; }

			stack<pair<int, int>> stack;
			s = ")" + s;
			int result = 0;
			for (int i = 0; i < len + 1; i++) {
				char c = s[i];
				if (stack.empty() || c == '(' || c == ')' && stack.top().first != '(') {
					stack.push(make_pair(c, i));
				}
				else {
					stack.pop();
					result = max(result, i - stack.top().second);
				}
			}
			return result;
		}

		int longestValidParenthesesAnother(string s) {
			int result = 0;
			int counter = 0;
			int len = s.size();
			int curLen = 0;

			for (int i = 0; i < len; i++) {
				if (s[i] == '(') {
					counter++;
					curLen++;
				}
				else {
					if (counter > 0) {
						counter--;
						curLen++;
						if (counter == 0) {
							result = max(result, curLen);
						}
					}
					else {
						counter = 0;
						curLen = 0;
					}
				}
			}

			counter = 0;
			curLen = 0;
			for (int i = len - 1; i >= 0; i--) {
				if (s[i] == ')') {
					counter++;
					curLen++;
				}
				else {
					if (counter > 0) {
						counter--;
						curLen++;
						if (counter == 0) {
							result = max(result, curLen);
						}
					}
					else {
						counter = 0;
						curLen = 0;
					}
				}
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

