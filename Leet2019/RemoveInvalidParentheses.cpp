#include "stdafx.h"
//Remove the minimum number of invalid parentheses in order to 
//make the input string valid. Return all possible results.
//
//Note: The input string may contain letters other than the parentheses ( and ).
//
//Example 1:
//Input: "()())()"
//Output: ["()()()", "(())()"]
//
//Example 2:
//Input: "(a)())()"
//Output: ["(a)()()", "(a())()"]
//
//Example 3:
//Input: ")("
//Output: [""] 

namespace Solution2019
{
	namespace RemoveInvalidParentheses
	{
		void helper(string s, int istart, int jstart, char openParen, char closeParen, vector<string>& result) {
			int counter = 0;
			for (int i = istart; i < s.size(); i++) {
				if (s[i] == openParen) { counter++; }
				else if (s[i] == closeParen) { counter--; }
				if (counter >= 0) { continue; }

				for (int j = jstart; j <= i; j++) {
					// If s[j] is the first closeParen, drop s[j]
					// after dropping, i and j will auto be advanced into the next pos
					// so istart and jstart for next round is still i and j
					//
					// Essentially i is scanning position, and j is deleting position. 
					// The (j == jstart || s[j - 1] != closeParen ensures we delete
					// the left most ( to avoid duplicates
					if (s[j] == closeParen && (j == jstart || s[j - 1] != closeParen)) {
						helper(s.substr(0, j) + s.substr(j + 1), i, j, openParen, closeParen, result);
					}
				}
				return;
			}

			reverse(s.begin(), s.end());
			if (openParen == '(') {
				helper(s, 0, 0, ')', '(', result);
			}
			else {
				result.push_back(s);
			}
		}

		vector<string> removeInvalidParentheses(string s) {
			vector<string> result;
			helper(s, 0, 0, '(', ')', result);
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

