#include "stdafx.h"
//Given an encoded string, return its decoded string.
//
//The encoding rule is: k[encoded_string], where the encoded_string inside 
//the square brackets is being repeated exactly k times. Note that k is 
//guaranteed to be a positive integer.
//
//You may assume that the input string is always valid; No extra white 
//spaces, square brackets are well-formed, etc.
//
//Furthermore, you may assume that the original data does not contain any 
//digits and that digits are only for those repeat numbers, k. 
//For example, there won't be input like 3a or 2[4].
//
//Examples:
//s = "3[a]2[bc]", return "aaabcbc".
//s = "3[a2[c]]", return "accaccacc".
//s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

namespace Solution2019
{
	namespace DecodeString
	{
		string decodeString(string str) {
			int len = str.size();
			if (len < 2) { return str; }

			stack<string> s;
			for (char c : str) {
				if (c == ']') {
					string cur = "";
					while (s.top() != "[") {
						cur = s.top() + cur;
						s.pop();
					}
					s.pop();
					int count = stoi(s.top());
					s.pop();
					string cur2 = "";
					for (int i = 0; i < count; i++) {
						cur2 += cur;
					}
					s.push(cur2);
				}
				else {
					s.push(string(1, c));
				}
			}
			string result = "";
			while (!s.empty()) {
				result += s.top();
				s.pop();
			}
			reverse(result.begin(), result.end());
			return result;
		}
		void Main() {
			print(decodeString("3[a]2[bc]"));
		}
	}
}

