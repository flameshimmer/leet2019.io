#include "stdafx.h"

//Given a string s, you are allowed to convert it to a palindrome by adding
//characters in front of it. Find and return the shortest palindrome you can find
//by performing this transformation.
//
//Example 1:
//Input: "aacecaaa"
//Output: "aaacecaaa"
//
//Example 2:
//Input: "abcd"
//Output: "dcbabcd" 

namespace Solution2019
{
	namespace ShortestPalindrome
	{
		namespace KMP {
			string shortestPalindrome(string s) {
				string rs = s;
				reverse(rs.begin(), rs.end());
				string l = s + "#" + rs;

				vector<int> p(l.size(), 0);
				for (int i = 1; i < l.size(); i++) {
					int j = p[i - 1];
					while (j > 0 && l[i] != l[j]) {
						j = p[j - 1];
					}
					p[i] = (j += (l[i] == l[j]));
				}
				return rs.substr(0, s.size() - p[l.size() - 1]) + s;
			}
		}

		namespace Recursion {
			string shortestPalindrome(string s) {
				int len = s.size();
				int j = 0;
				for (int i = len - 1; i >= 0; i--) {
					if (s[i] == s[j]) { j++; }
				}

				if (j == len) { return s; }
				string suffix = s.substr(j);
				string reversedSuffix = suffix;
				reverse(reversedSuffix.begin(), reversedSuffix.end());
				return reversedSuffix + shortestPalindrome(s.substr(0, j)) + suffix;
			}
		}

		namespace ONSquare {
			bool helper(string& s, int i, int j, int len) {
				while (i >= 0 && j < len) {
					if (s[i] != s[j]) { return false; }
					i--;
					j++;
				}
				return i == -1 && j == len;
			}

			bool isPalindrome(string& s) {
				int len = s.size();
				if (len < 2) { return true; }
				if (len % 2 == 0) { return helper(s, len / 2 - 1, len / 2, len); }
				else { return helper(s, len / 2 - 1, len / 2 + 1, len); }
			}

			string shortestPalindrome(string s) {
				string chopped = "";
				string old = s;
				while (!isPalindrome(s)) {
					chopped.push_back(s.back());
					s.pop_back();
				}
				return chopped + old;
			}
		}
		void Main() {
			string test = "tst test test";
			print(Recursion::shortestPalindrome("adcba"));
			print(Recursion::shortestPalindrome("cabacdefg"));
			print(Recursion::shortestPalindrome("abcd"));
		}
	}
}

