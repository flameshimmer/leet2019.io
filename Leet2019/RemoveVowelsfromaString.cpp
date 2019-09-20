#include "stdafx.h"
//Given a string S, remove the vowels 'a', 'e', 'i', 'o', and 'u' from it, and return the new string.
//
//Example 1:
//Input: "leetcodeisacommunityforcoders"
//Output: "ltcdscmmntyfrcdrs"
//Example 2:
//
//Input: "aeiou"
//Output: ""
// 
//Note:
//S consists of lowercase English letters only.
//1 <= S.length <= 1000 

namespace Solution2019
{
	namespace RemoveVowelsfromaString
	{
		string removeVowels(string S) {
			string result = "";
			for (char c : S) {
				if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
					continue;
				}
				result += c;
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

