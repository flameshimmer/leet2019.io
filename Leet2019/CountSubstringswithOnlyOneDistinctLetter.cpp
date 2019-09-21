#include "stdafx.h"
//Given a string S, return the number of substrings that have only one distinct letter.
//
//Example 1:
//Input: S = "aaaba"
//Output: 8
//Explanation: The substrings with one distinct letter are "aaa", "aa", "a", "b".
//"aaa" occurs 1 time.
//"aa" occurs 2 times.
//"a" occurs 4 times.
//"b" occurs 1 time.
//So the answer is 1 + 2 + 4 + 1 = 8.
//Example 2:
//
//Input: S = "aaaaaaaaaa"
//Output: 55
// 
//Constraints:
//1 <= S.length <= 1000
//S[i] consists of only lowercase English letters. 

namespace Solution2019
{
	namespace CountSubstringswithOnlyOneDistinctLetter
	{
		int countLetters(string S) {
			int len = S.size();
			int start = 0;
			int end = 1;
			int result = 0;
			while (end <= len) {
				while (end < len && S[start] == S[end]) { end++; }
				result += (end - start) * (end - start + 1) / 2;
				start = end;
				end++;
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(countLetters("aaaba"));
		}
	}
}

