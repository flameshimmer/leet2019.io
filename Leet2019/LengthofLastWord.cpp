#include "stdafx.h"
//Given a string s consists of upper/lower-case alphabets and empty space 
//characters ' ', return the length of last word in the string.
//
//If the last word does not exist, return 0.
//
//Note: A word is defined as a character sequence consists of non-space characters only.
//
//Example:
//
//Input: "Hello World"
//Output: 5

namespace Solution2019
{
	namespace LengthofLastWord
	{
		int LengthofLastWord(string s) {
			int len = s.size();
			if (len == 0) { return 0; }

			int end = len - 1;
			while (end >= 0) {
				if (s[end] != ' ') { break; }
				end--;
			}
			int start = end;
			while (start >= 0) {
				if (s[start] == ' ') { break; }
				start--;
			}
			return end - start;
		}

		void Main() {
			print(LengthofLastWord("Hello World"));
		}
	}
}

