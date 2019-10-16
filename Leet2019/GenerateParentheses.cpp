#include "stdafx.h"
//Given n pairs of parentheses, write a function to 
//generate all combinations of well-formed parentheses.
//
//For example, given n = 3, a solution set is:
//
//[
//  "((()))",
//  "(()())",
//  "(())()",
//  "()(())",
//  "()()()"
//]

namespace Solution2019
{
	namespace GenerateParentheses
	{
		void helper(int sp, int ep, int n, string& result, vector<string>& results) {
			if (sp > n || ep > n || ep > sp) { return; }
			if (sp == n && ep == n) {
				results.push_back(result);
				return;
			}
			result.push_back('(');
			helper(sp + 1, ep, n, result, results);
			result.pop_back();

			result.push_back(')');
			helper(sp, ep + 1, n, result, results);
			result.pop_back();
		}

		void helperAnother(int sp, int ep, int n, string& result, vector<string>& results) {
			if (sp == n && ep == n) {
				results.push_back(result);
				return;
			}

			if (sp < n) {
				result.push_back('(');
				helper(sp + 1, ep, n, result, results);
				result.pop_back();
			}

			if (ep < sp) {
				result.push_back(')');
				helper(sp, ep + 1, n, result, results);
				result.pop_back();
			}
		}

		vector<string> generateParenthesis(int n) {
			vector<string> results;
			if (n == 0) { return results; }

			string result = "";
			helper(0, 0, n, result, results);
			return results;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

