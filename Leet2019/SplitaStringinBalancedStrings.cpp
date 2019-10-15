#include "stdafx.h"
//Balanced strings are those who have equal quantity 
//of 'L' and 'R' characters.
//Given a balanced string s split it in the maximum 
//amount of balanced strings.
//Return the maximum amount of splitted balanced strings.
//
//Example 1:
//Input: s = "RLRRLLRLRL"
//Output: 4
//Explanation: s can be split into "RL", "RRLL", "RL", "RL", 
//each substring contains same number of 'L' and 'R'.
//
//Example 2:
//Input: s = "RLLLLRRRLR"
//Output: 3
//Explanation: s can be split into "RL", "LLLRRR", "LR", each
//substring contains same number of 'L' and 'R'.
//
//Example 3:
//Input: s = "LLLLRRRR"
//Output: 1
//Explanation: s can be split into "LLLLRRRR".

namespace Solution2019
{
	namespace SplitaStringinBalancedStrings
	{
		int balancedStringSplit(string s) {
			int count = 0;
			int result = 0;
			for (char c : s) {
				count += (c == 'L' ? 1 : -1);
				if (count == 0) { result++; }
			}
			return result;
		}

		namespace useStack {
			bool match(char a, char b) {
				if (a == 'L') return b == 'R';
				if (a == 'R') return b == 'L';
				return false;
			}

			int balancedStringSplit(string str) {
				int len = str.size();
				if (len == 0) { return 0; }

				int result = 0;
				stack<char> s;

				for (char c : str) {
					if (s.empty() || !match(c, s.top())) {
						s.push(c);
					}
					else {
						s.pop();
						if (s.empty()) { result++; }
					}
				}
				return result;
			}
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

