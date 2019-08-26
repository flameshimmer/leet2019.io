#include "stdafx.h"
//Implement strStr().
//
//Return the index of the first occurrence of needle in haystack, 
//or -1 if needle is not part of haystack.
//
//Example 1:
//Input: haystack = "hello", needle = "ll"
//Output: 2
//
//Example 2:
//Input: haystack = "aaaaa", needle = "bba"
//Output: -1
//Clarification:
//
//What should we return when needle is an empty string? 
//This is a great question to ask during an interview.
//
//For the purpose of this problem, we will return 0 when 
//needle is an empty string. 
//This is consistent to C's strstr() and Java's indexOf().

namespace Solution2019
{
	namespace ImplementstrStr
	{
		int ImplementstrStr(string s, string t) {			
			int lent = t.size();
			if (lent == 0) { return 0; }
			int lens = s.size();
			if (lens < lent) { return -1; }
			
			int i = 0;
			
			while (i <= lens - lent) {
				int j = 0;
				while (j < lent) {
					if (s[i + j] != t[j]) { break; }
					j++;
				}
				if (j == lent) { return i; }
				i++;
			}
			return -1;
		}

		void Main() {
			print(ImplementstrStr("hello", "ll"));
			print(ImplementstrStr("aaaaa", "bba"));
		}
	}
}

