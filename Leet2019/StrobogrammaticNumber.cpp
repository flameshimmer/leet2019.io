#include "stdafx.h"

//A strobogrammatic number is a number that looks the same when rotated 180
//degrees (looked at upside down).
//Write a function to determine if a number is strobogrammatic. The number is
//represented as a string.
//
//Example 1:
//Input:  "69"
//Output: true
//
//Example 2:
//Input:  "88"
//Output: true
//
//Example 3:
//Input:  "962"
//Output: false

namespace Solution2019
{
	namespace StrobogrammaticNumber
	{
		bool match(char a, char b) {
			switch (a) {
			case '0':
				return b == '0';
			case '1':
				return b == '1';
			case '8':
				return b == '8';
			case '6':
				return b == '9';
			case '9':
				return b == '6';
			default:
				return false;
			}
		}

		bool isStrobogrammatic(string num) {
			int len = num.size();
			if (len == 0) { return true; }
			int start = 0;
			int end = len - 1;
			while (start <= end) {
				if (!match(num[start], num[end])) { return false; }
				start++;
				end--;
			}
			return true;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

