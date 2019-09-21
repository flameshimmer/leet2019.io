#include "stdafx.h"
//Implement function ToLowerCase() that has a string parameter str,
//and returns the same string in lowercase.
//
//Example 1:
//Input: "Hello"
//Output: "hello"
//
//Example 2:
//Input: "here"
//Output: "here"
//
//Example 3:
//Input: "LOVELY"
//Output: "lovely"
namespace Solution2019
{
	namespace ToLowerCase
	{
		string toLowerCase(string str) {
			string result;
			for (char c : str) {
				if (c >= 'A' && c <= 'Z') { c += 32; }
				result += c;
			}
			return result;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

