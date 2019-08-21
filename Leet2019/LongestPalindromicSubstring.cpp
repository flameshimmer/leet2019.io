#include "stdafx.h"


//Given a string s, find the longest palindromic substring in s.
//You may assume that the maximum length of s is 1000.
//
//Example 1:
//
//Input : "babad"
//Output : "bab"
//	 Note : "aba" is also a valid answer.
//			Example 2 :
//
//		Input : "cbbd"
//			Output : "bb"
//
//
namespace Solution2019
{
	namespace LongestPalindromicSubstring
	{
		string LongestPalindromicSubstring(string s) {
			int len = s.size();
			if (len < 2) { return s; }

			int longest = 0;
			int head = 0;
			for (int i = 0; i < len; i++)
			{
				int start = i;
				while (i + 1 < len && s[i] == s[i + 1]) { i++; }
				int end = i;

				while (start >= 0 && end < len && s[start] == s[end]) {
					start--;
					end++;
				}
				if (end - start - 1 > longest) {
					longest = end - start - 1;
					head = start + 1;
				}
			}
			return s.substr(head, longest);
		}


		void Main() {			
			print(LongestPalindromicSubstring("bbb"));
			print(LongestPalindromicSubstring("aa"));
			print(LongestPalindromicSubstring("c"));
			print(LongestPalindromicSubstring("babad"));
			print(LongestPalindromicSubstring("cbbd"));
		}
	}
}

