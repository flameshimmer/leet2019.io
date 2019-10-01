#include "stdafx.h"
//Given a string S and a character C, return an array of integers 
//representing the shortest distance from the character C in the string.
//
//Example 1:
//Input: S = "loveleetcode", C = 'e'
//Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
// 
//Note:
//S string length is in [1, 10000].
//C is a single character, and guaranteed to be in string S.
//All letters in S and C are lowercase.

namespace Solution2019
{
	namespace ShortestDistancetoaCharacter
	{
		vector<int> shortestToChar(string S, char C) {
			int len = S.size();
			vector<int> result(len, len);
			int pos = -len;
			for (int i = 0; i < len; i++) {
				if (S[i] == C) { pos = i; }
				result[i] = min(result[i], abs(i - pos));
			}

			for (int i = len - 1; i >= 0; i--) {
				if (S[i] == C) { pos = i; }
				result[i] = min(result[i], abs(i - pos));
			}
			return result;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

