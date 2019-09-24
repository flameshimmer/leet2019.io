#include "stdafx.h"
//Given two strings S and T, return if they are equal when both 
//are typed into empty text editors. # means a backspace character.
//
//Example 1:
//Input: S = "ab#c", T = "ad#c"
//Output: true
//Explanation: Both S and T become "ac".
//
//Example 2:
//Input: S = "ab##", T = "c#d#"
//Output: true
//Explanation: Both S and T become "".
//
//Example 3:
//Input: S = "a##c", T = "#a#c"
//Output: true
//Explanation: Both S and T become "c".
//
//Example 4:
//Input: S = "a#c", T = "b"
//Output: false
//Explanation: S becomes "c" while T becomes "b".
//Note:
//
//1 <= S.length <= 200
//1 <= T.length <= 200
//S and T only contain lowercase letters and '#' characters.
//Follow up:
//
//Can you solve it in O(N) time and O(1) space?

namespace Solution2019
{
	namespace BackspaceStringCompare
	{
		bool backspaceCompare(string S, string T) {
			int i1 = S.size() - 1;
			int i2 = T.size() - 1;
			int skip1 = 0;
			int skip2 = 0;
			while (i1 >= 0 || i2 >= 0) {
				while (i1 >= 0) {
					if (S[i1] == '#') { skip1++; i1--; }
					else if (skip1 > 0) { skip1--; i1--; }
					else { break; }
				}
				while (i2 >= 0) {
					if (T[i2] == '#') { skip2++; i2--; }
					else if (skip2 > 0) { skip2--; i2--; }
					else { break; }
				}
				if (i1 >= 0 && i2 >= 0 && S[i1] != T[i2]) { return false; }
				if ((i1 >= 0) != (i2 >= 0)) { return false; }
				i1--;
				i2--;
			}
			return true;
		}

		namespace ON {
			string helper(string s) {
				string result = "";
				for (char c : s) {
					if (c == '#' && result.size() > 0) { result.pop_back(); }
					else if (c != '#') { result.push_back(c); }
				}
				return result;
			}

			bool backspaceCompare(string S, string T) {
				string r1 = helper(S);
				string r2 = helper(T);
				return r1 == r2;
			}
		}


		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

