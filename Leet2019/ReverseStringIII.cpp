#include "stdafx.h"
//Given a string, you need to reverse the order of characters 
//in each word within a sentence while still preserving 
//whitespaceand initial word order.
//
//Example 1:
//Input: "Let's take LeetCode contest"
//Output : "s'teL ekat edoCteeL tsetnoc"
//Note : In the string, each word is separated by single 
//spaceand there will not be any extra space in the string.
namespace Solution2019
{
	namespace ReverseStringIII
	{
		string reverseWords(string s) {
			int len = s.size();
			if (len < 2) { return s; }
			int start = 0;
			int end = 0;
			while (end < len) {
				while (end < len && s[end] == ' ') { end++; }
				start = end;
				while (end < len && s[end] != ' ') { end++; }
				if (start != end) { reverse(s.begin() + start, s.begin() + end); }
			}
			return s;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

