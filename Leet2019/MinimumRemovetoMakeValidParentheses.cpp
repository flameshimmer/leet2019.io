#include "stdafx.h"

//Given a string s of '(' , ')' and lowercase English characters. 
//Your task is to remove the minimum number of parentheses ( '(' or ')', in any
//positions ) so that the resulting parentheses string is valid and return any
//valid string.
//Formally, a parentheses string is valid if and only if:
//It is the empty string, contains only lowercase characters, or
//It can be written as AB (A concatenated with B), where A and B are valid
//strings, or
//It can be written as (A), where A is a valid string.
// 
//
//Example 1:
//Input: s = "lee(t(c)o)de)"
//Output: "lee(t(c)o)de"
//Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
//
//Example 2:
//Input: s = "a)b(c)d"
//Output: "ab(c)d"
//
//Example 3:
//Input: s = "))(("
//Output: ""
//Explanation: An empty string is also valid.
//
//Example 4:
//Input: s = "(a(b(c)d)"
//Output: "a(b(c)d)"
// 
//Constraints:
//1 <= s.length <= 10^5
//s[i] is one of  '(' , ')' and lowercase English letters. 

namespace Solution2019
{
	namespace MinimumRemovetoMakeValidParentheses
	{
		string minRemoveToMakeValid(string str) {
			int len = str.size();
			string result = str;
			stack<int> s;
			for (int i = 0; i < len; i++) {
				if (str[i] == '(') { s.push(i); }
				else if (str[i] == ')') {
					if (s.empty()) { result[i] = '*'; }
					else { s.pop(); }
				}
			}
			while (!s.empty()) {
				result[s.top()] = '*';
				s.pop();
			}
			result.erase(remove(result.begin(), result.end(), '*'), result.end());
			return result;
		}

		string minRemoveToMakeValidAnother(string str) {
			int len = str.size();
			if (len == 0) { return str; }

			vector<int> remove;
			stack<int> s;
			for (int i = 0; i < len; i++) {
				if (str[i] == '(') {
					s.push(i);
				}
				else if (str[i] == ')') {
					if (s.empty()) { remove.push_back(i); }
					else { s.pop(); }
				}
			}
			while (!s.empty()) {
				remove.push_back(s.top());
				s.pop();
			}
			sort(remove.begin(), remove.end(), greater<int>());
			string result = str;
			for (int v : remove) {
				result.erase(v, 1);
			}
			return result;
		}

		void Main() {
			print(minRemoveToMakeValid("lee(t(c)o)de)"));
		}
	}
}

