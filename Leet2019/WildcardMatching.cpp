#include "stdafx.h"

//Given an input string (s) and a pattern (p), implement wildcard pattern
//matching with support for '?' and '*'.
//'?' Matches any single character.
//'*' Matches any sequence of characters (including the empty sequence).
//The matching should cover the entire input string (not partial).
//
//Note:
//s could be empty and contains only lowercase letters a-z.
//p could be empty and contains only lowercase letters a-z, and characters like ?
//or *.
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
//p = "*"
//Output: true
//Explanation: '*' matches any sequence.
//
//Example 3:
//Input:
//s = "cb"
//p = "?a"
//Output: false
//Explanation: '?' matches 'c', but the second letter is 'a', which does not
//match 'b'.
//
//Example 4:
//Input:
//s = "adceb"
//p = "*a*b"
//Output: true
//Explanation: The first '*' matches the empty sequence, while the second '*'
//matches the substring "dce".
//
//Example 5:
//Input:
//s = "acdcb"
//p = "a*c?b"
//Output: false 

namespace Solution2019
{
	namespace WildcardMatching
	{
		namespace UseC {
			bool isMatch(const char* s, const char* p) {
				const char* star = nullptr;
				const char* ss = s;

				while (*s) {
					if (*s == *p || *p == '?') { s++; p++; continue; }
					if (*p == '*') { star = p; p++; ss = s; continue; }
					if (star) { p = star + 1; ss++; s = ss; continue; }
					return false;
				}
				while (*p == '*') { p++; }
				return !*p;
			}

			bool isMatch(string s, string p) {
				return isMatch(s.c_str(), p.c_str());
			}
		}

		namespace TwoDimensionalDP {
			bool isMatch(string s, string p) {
				int lens = s.size();
				int lenp = p.size();

				vector<vector<bool>> M(lens + 1, vector<bool>(lenp + 1));
				M[0][0] = true;
				for (int i = 1; i < lenp + 1 && p[i - 1] == '*'; i++) {
					M[0][i] = true;
				}

				for (int i = 1; i < lens + 1; i++) {
					for (int j = 1; j < lenp + 1; j++) {
						if (s[i - 1] == p[j - 1] || p[j - 1] == '?') { M[i][j] = M[i - 1][j - 1]; }
						else if (p[j - 1] == '*') { M[i][j] = M[i - 1][j] || M[i][j - 1]; }
					}
				}
				return M[lens][lenp];
			}
		}

		namespace OneDimensionalDP {
			bool isMatch(string s, string p) {
				int lens = s.size();
				int lenp = p.size();
				vector<bool> M(lens + 1, false);
				M[0] = true;

				for (int j = 1; j < lenp + 1; j++) {
					bool pre = M[0];
					M[0] = (M[0] && p[j - 1] == '*');
					for (int i = 1; i < lens + 1; i++) {
						bool temp = M[i];
						if (p[j - 1] == '*') { M[i] = M[i - 1] || M[i]; }
						else { M[i] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && pre; }
						pre = temp;
					}
				}
				return M[lens];
			}
		}

		void Main() {
			string test = "tst test test";
			print(UseC::isMatch("addddceb","a*c?b"));
			print(UseC::isMatch("addddceeb", "a*c?b"));
			print(UseC::isMatch("acdcb", "a*c?b"));
		}
	}
}

