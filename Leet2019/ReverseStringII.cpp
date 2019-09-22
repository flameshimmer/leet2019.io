#include "stdafx.h"
//Given a string and an integer k, you need to reverse the first k 
//characters for every 2k characters counting from the start of the 
//string. If there are less than k characters left, reverse all of
//them. If there are less than 2k but greater than or equal to k 
//characters, then reverse the first k characters and left the
//other as original.
//
//Example:
//Input: s = "abcdefg", k = 2
//Output: "bacdfeg"
//Restrictions:
//The string consists of lower English letters only.
//Length of the given string and k will in the range [1, 10000]

namespace Solution2019
{
	namespace ReverseStringII
	{
		string reverseStr(string s, int k) {
			int len = s.size();
			for (int i = 0; i < len; i += 2 * k) {
				int j = min(i + k - 1, len - 1);
				reverse(s.begin() + i, s.begin() + j+1);
			}
			return s;
		}

		string reverseStrAnother(string s, int k) {
			int len = s.size();
			int start = 0;
			int end = 0;
			while (end < len) {
				while (end < len && (end - start + 1) <= 2*k) { end++; }
				if (end == len && (end - start) < k) {
					reverse(s.begin() + start, s.begin() + end); 	
				} else {
					reverse(s.begin() + start, s.begin() + start + k);
				}			
				start = end;
			}
			return s;
		}

		void Main() {
			string test = "tst test test";
			print(reverseStr("a", 2));
			print(reverseStr("abcdefg", 2));
		}
	}
}

