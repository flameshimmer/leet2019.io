#include "stdafx.h"
//Given an input string, reverse the string word by word.
//
//Example 1:
//Input: "the sky is blue"
//Output: "blue is sky the"
//
//Example 2:
//Input: "  hello world!  "
//Output: "world! hello"
//Explanation: Your reversed string should not 
//contain leading or trailing spaces.
//
//Example 3:
//Input: "a good   example"
//Output: "example good a"
//Explanation: You need to reduce multiple spaces 
//between two words to a single space in the reversed string.
// 
//Note:
//A word is defined as a sequence of non-space characters.
//Input string may contain leading or trailing spaces. 
//However, your reversed string should not contain 
//leading or trailing spaces.
//You need to reduce multiple spaces between two words 
//to a single space in the reversed string.
// 
//Follow up:
//For C programmers, try to solve it in-place in O(1) extra space. 

namespace Solution2019
{
	namespace ReverseWordsinaString
	{
		string reverseWords(string s) {
			while (s.back() == ' ') { s.pop_back(); }
			reverse(s.begin(), s.end());
			int len = s.size();

			int start = 0;
			int end = 0;
			while (end < len) {
				while (end < len && s[end] == ' ') { end++; }
				if (end == len) { break; }

				start = end;
				while (end < len && s[end] != ' ') { end++; }
				reverse(s.begin() + start, s.begin() + end);
			}

			while (s.back() == ' ') { s.pop_back(); }

			start = 0;
			end = 0;
			while (end < len) {
				if (s[end] != ' ' || (end + 1 < len && s[end + 1] != ' ')) {
					s[start] = s[end];
					start++;
				}
				end++;
			}

			return s.substr(0, start);
		}

		string reverseWordsAnother(string s) {
			int start = 0;
			int end = 0;
			int temp = 0;
			int len = s.size();
			int wordCount = 0;

			while (end < len) {
				while (end < len && s[end] == ' ') { end++; }
				if (end == len) { break; }
				if (wordCount > 0) { s[start] = ' '; start++; }

				temp = start;
				while (end < len && s[end] != ' ') {
					s[start] = s[end];
					start++;
					end++;
				}
				reverse(s.begin() + temp, s.begin() + start);
				wordCount++;
			}
			s.resize(start);
			reverse(s.begin(), s.end());
			return s;
		}
		void Main() {
			string test = "  hello world!  ";
			print(reverseWordsAnother(test));
		}
	}
}

