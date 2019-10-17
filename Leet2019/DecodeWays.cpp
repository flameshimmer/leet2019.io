#include "stdafx.h"
//A message containing letters from A-Z is being encoded to numbers 
//using the following mapping:
//
//'A' -> 1
//'B' -> 2
//...
//'Z' -> 26
//Given a non-empty string containing only digits, determine the total 
//number of ways to decode it.
//
//Example 1:
//
//Input: "12"
//Output: 2
//Explanation: It could be decoded as "AB" (1 2) or "L" (12).
//Example 2:
//
//Input: "226"
//Output: 3
//Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), 
//or "BBF" (2 2 6).

namespace Solution2019
{
	namespace DecodeWays
	{
		int numDecodings(string s) {
			if (s.empty() || s[0] == '0') { return 0; }

			int r2 = 1; // index -1
			int r1 = s[0] == '0' ? 0 : 1; // index 0

			for (int i = 1; i < s.size(); i++) {
				int r = 0;
				if (s[i] != '0') { r += r1; }

				if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') {
					r += r2;
				}
				r2 = r1;
				r1 = r;
			}
			return r1;
		}
		
		
		namespace Recursion {
			void helper(string& s, int start, int len, int& result) {
				if (start == len) {
					result++;
				}
				if (start >= len) { return; }

				if (s[start] == '0') { return; }
				helper(s, start + 1, len, result);
				if (s[start] == '1' || (s[start] == '2' && start + 1 < len && s[start + 1] <= '6')) {
					helper(s, start + 2, len, result);
				}
			}

			int numDecodings(string s) {
				int result = 0;
				int len = s.size();
				helper(s, 0, len, result);
				return result;
			}
		}

		void Main() {
			print(numDecodings("0"));
		}
	}
}

