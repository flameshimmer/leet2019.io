#include "stdafx.h"
//Given two binary strings, return their sum (also a binary string).
//
//The input strings are both non-empty and contains only characters 1 or 0.
//
//Example 1:
//
//Input: a = "11", b = "1"
//Output: "100"
//Example 2:
//
//Input: a = "1010", b = "1011"
//Output: "10101"

namespace Solution2019
{
	string addBinary(string a, string b) {
		int i = a.size();
		if (i == 0) { return b; }
		int j = b.size();
		if (j == 0) { return a; }

		i--; j--;
		
		string result;
		int carry = 0;
		while (i >= 0 || j >= 0 || carry > 0) {
			int sum = (i >= 0 ? a[i]-'0' : 0) + (j >= 0 ? b[j]-'0' : 0) + carry;
			result = to_string(sum % 2) + result;
			carry = sum / 2;
			i--;
			j--;
		}
		return result;
	}

	namespace AddBinary
	{
		void Main() {
			print(addBinary("11", "1"));
			print(addBinary("1010", "1011"));
		}
	}
}

