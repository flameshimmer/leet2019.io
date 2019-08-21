#include "stdafx.h"
//Given a string, determine if it is a palindrome, 
//considering only alphanumeric characters and ignoring cases.
//
//Note: For the purpose of this problem, we define empty string as valid palindrome.
//
//Example 1:
//
//Input: "A man, a plan, a canal: Panama"
//Output: true
//Example 2:
//
//Input: "race a car"
//Output: false
//
namespace Solution2019
{
	namespace ValidPalindrome
	{
		bool ValidPalindrome(string s) {
			int len = s.size();
			if (len < 2) { return true; }
			int start = 0;
			int end = len - 1;
			while (start < end) {
				while (start < end && !isalnum(s[start])) { start++; }
				while (start < end && !isalnum(s[end])) { end--; }
				if (tolower(s[start]) != tolower(s[end])) { return false; }
				start++;
				end--;
			}
			return true;
		}

		void Main() {
			string test = "tst test test";
			print(ValidPalindrome("race a car"));
			print(ValidPalindrome("A man, a plan, a canal: Panama"));			
		}
	}
}

