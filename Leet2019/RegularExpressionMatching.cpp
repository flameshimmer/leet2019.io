#include "stdafx.h"
//Given an input string (s) and a pattern (p), implement regular
//expression matching with support for '.' and '*'.
//
//'.' Matches any single character.
//'*' Matches zero or more of the preceding element.
//The matching should cover the entire input string (not partial).
//
//Note:
//s could be empty and contains only lowercase letters a-z.
//p could be empty and contains only lowercase letters a-z, and 
//characters like . or *.
//
//Example 1:
//Input:
//s = "aa"
//p = "a"
//Output: false
//Explanation: "a" does not match the entire string "aa".
//
//Example 2:
//Input:
//s = "aa"
//p = "a*"
//Output: true
//Explanation: '*' means zero or more of the preceding element, 'a'.
//Therefore, by repeating 'a' once, it becomes "aa".
//
//Example 3:
//Input:
//s = "ab"
//p = ".*"
//Output: true
//Explanation: ".*" means "zero or more (*) of any character (.)".
//
//Example 4:
//Input:
//s = "aab"
//p = "c*a*b"
//Output: true
//Explanation: c can be repeated 0 times, a can be repeated 1 time. 
//Therefore, it matches "aab".
//
//Example 5:
//Input:
//s = "mississippi"
//p = "mis*is*p*."
//Output: false

namespace Solution2019
{
	namespace RegularExpressionMatching
	{
		namespace DP {
			bool matches(string& s, string& p, int i, int j) {
				return s[i] == p[j] || p[j] == '.';
			}
			bool isMatch(string s, string p) {
				int lens = s.size();
				int lenp = p.size();
				vector<vector<bool>> M(lens + 1, vector<bool>(lenp + 1, false));
				M[0][0] = true;

				for (int i = 0; i < lens + 1; i++) {
					for (int j = 1; j < lenp + 1; j++) {
						if (i - 1 >= 0 && matches(s, p, i - 1, j - 1) && M[i - 1][j - 1]) {
							M[i][j] = true;
							continue;
						}

						// if we want to match X*
						if (i - 1 >= 0 && j - 2 >= 0 && p[j - 1] == '*' && matches(s, p, i - 1, j - 2) && M[i - 1][j]) {
							M[i][j] = true;
							continue;
						}

						// if we don't want to matching X*
						if (j >= 2 && p[j - 1] == '*' && M[i][j - 2]) {
							M[i][j] = true;
							continue;
						}
					}
				}
				return M[lens][lenp];
			}
		}

		namespace C {
			bool matches(char* a, char* b) {
				return (*a != '\0' && *b != '\0') && (*a == *b || *b == '.');
			}

			bool isMatch(char* s, char* p) {
				if (*p == '\0') { return *s == '\0'; }

				if (p[1] != '*') {
					return matches(s, p) && isMatch(s + 1, p + 1);
				}

				while (matches(s, p)) {
					if (isMatch(s, p + 2)) { return true; }
					s++;
				}
				return isMatch(s, p + 2);
			}
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

