#include "stdafx.h"

//Given a non-empty string s, you may delete at most one character. 
//Judge whether you can make it a palindrome.
//
//Example 1:
//Input: "aba"
//Output: True
//Example 2:
//Input: "abca"
//Output: True
//Explanation: You could delete the character 'c'.
//Note:
//The string will only contain lowercase characters a-z. 
//The maximum length of the string is 50000.

namespace Solution2019
{
	namespace ValidPalindromeII
	{
		bool IsPalindrome(string s, int start, int end) {
			while (start < end) {
				if (s[start] != s[end]) { return false; }
				start++; end--;
			}
			return true;
		}

		bool ValidPalindromeII(string s) {
			int len = s.size();
			if (len < 3) { return true; }

			int start = 0;
			int end = len - 1;
			while (start < end) {
				if (s[start] != s[end]) {
					return IsPalindrome(s, start + 1, end) || IsPalindrome(s, start, end - 1);
				}				
				start++;
				end--;
			}
			return true;		
		}


		void Main() {			
			print(ValidPalindromeII("aba"));
			print(ValidPalindromeII("abac"));
			print(ValidPalindromeII("abca"));
			print(ValidPalindromeII("abdca"));
		}
	}
}

