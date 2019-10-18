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

		string decodeString(const string& s, int len, int& i) {
			string result;

			while (i < len && s[i] != ']') {
				if (!isdigit(s[i])) {
					result += s[i];
					i++;
				}
				else {
					int n = 0;
					while (i < len && isdigit(s[i])) {
						n = n * 10 + (s[i] - '0');
						i++;
					}
					i++;
					string t = decodeString(s, len, i);
					i++;
					while (n > 0) {
						result += t;
						n--;
					}
				}
			}
			return result;
		}

		string decodeString(string s) {
			int i = 0;
			int len = s.size();
			return decodeString(s, len, i);
		}

		string decodeStringStack(string s) {
			string result;
			stack<int> countStack;
			stack<string> resStack;
			int i = 0;
			while (i < s.size()) {
				char c = s[i];
				if (isdigit(c)) {
					int count = 0;
					while (isdigit(s[i])) {
						count = 10 * count + (c - '0');
						i++;
					}
					countStack.push(count);
				}
				else if (c == '[') {
					resStack.push(result);
					result = "";
					i++;
				}
				else if (c == ']') {
					string temp = resStack.top();
					resStack.pop();
					for (int i = 0; i < countStack.top(); i++) {
						temp += result;
					}
					countStack.pop();
					result = temp;
					i++;
				}
				else {
					result += c;
					i++;
				}
			}
			return result;
		}


		void Main() {
			print(decodeStringStack("3[a2[c]]"));
		}
	}
}

