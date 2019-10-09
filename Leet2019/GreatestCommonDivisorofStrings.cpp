#include "stdafx.h"
//For strings S and T, we say "T divides S" if and only
//if S = T + ... + T  (T concatenated with itself 1 or more times)
//
//Return the largest string X such that X divides str1 
//and X divides str2.
//
//Example 1:
//Input: str1 = "ABCABC", str2 = "ABC"
//Output: "ABC"
//
//Example 2:
//Input: str1 = "ABABAB", str2 = "ABAB"
//Output: "AB"
//
//Example 3:
//Input: str1 = "LEET", str2 = "CODE"
//Output: ""
// 
//Note:
//1 <= str1.length <= 1000
//1 <= str2.length <= 1000
//str1[i] and str2[i] are English uppercase letters.

namespace Solution2019
{
	namespace GreatestCommonDivisorofStrings
	{
		string gcdOfStrings(string str1, string str2) {
			if (str1.size() < str2.size()) { return gcdOfStrings(str2, str1); }
			else if (str2.empty()) { return str1; }
			else if (str1.substr(0, str2.size()) != str2) { return ""; }
			return gcdOfStrings(str1.substr(str2.size()), str2);
		}

		namespace Another {
			int gcd(int a, int b) {
				return (a == 0) ? b : gcd(b % a, a);
			}

			string gcdOfStrings(string str1, string str2) {
				int len1 = str1.size();
				int len2 = str2.size();
				int d = gcd(len1, len2);
				string s = str1.substr(0, d);
				string str = str1 + str2;
				for (int i = 0; i < len1 + len2; i += d) {
					if (str.substr(i, d) != s) { return ""; }
				}
				return s;
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

