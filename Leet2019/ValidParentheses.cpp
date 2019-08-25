#include "stdafx.h"
//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
//
namespace Solution2019
{
	namespace ValidParentheses
	{
		bool Matches(char s1, char s2) {
			switch (s1) {
			case ')':
				return s2 == '(';
			case ']':
				return s2 == '[';
			case '}':
				return s2 == '{';
			}
			return false;
		}

		bool ValidParentheses(string str) {
			stack<char> s;
			for (char c : str) {
				if (c == ')' || c == ']' || c == '}') {
					if (s.empty() || !Matches(c, s.top())) { return false; }
					s.pop();
				}
				else {
					s.push(c);
				}
			}
			return s.empty();
		}


		void Main() {
			string test = "tst test test";
			print(ValidParentheses("()"));
			print(ValidParentheses("()[]{}"));
			print(ValidParentheses("(]"));
			print(ValidParentheses("[)"));
		}
	}
}

