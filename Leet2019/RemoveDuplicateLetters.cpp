#include "stdafx.h"

//Given a string which contains only lowercase letters, remove duplicate letters
//so that every letter appears once and only once. You must make sure your result
//is the smallest in lexicographical order among all possible results.
//
//Example 1:
//Input: "bcabc"
//Output: "abc"
//
//Example 2:
//Input: "cbacdcbc"
//Output: "acdb"

namespace Solution2019
{
	namespace RemoveDuplicateLetters
	{
		string removeDuplicateLetters(string s) {
			int count[26] = { 0 };
			bool used[26] = { false };
			for (char c : s) {
				count[c - 'a']++;
			}

			string result = "";
			for (char c : s) {
				count[c - 'a']--;
				if (used[c - 'a']) { continue; }
				while (!result.empty() && c < result.back() && count[result.back() - 'a'] > 0) {
					used[result.back() - 'a'] = false;
					result.pop_back();
				}
				result += c;
				used[c - 'a'] = true;
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

