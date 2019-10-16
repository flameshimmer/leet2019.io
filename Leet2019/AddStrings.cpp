#include "stdafx.h"
//Given two non-negative integers num1 and num2 represented
//as string, return the sum of num1 and num2.
//
//Note:
//The length of both num1 and num2 is < 5100.
//Both num1 and num2 contains only digits 0-9.
//Both num1 and num2 does not contain any leading zero.
//You must not use any built-in BigInteger library or 
//convert the inputs to integer directly.

namespace Solution2019
{
	namespace AddStrings
	{
		string addStrings(string num1, string num2) {
			reverse(num1.begin(), num1.end());
			reverse(num2.begin(), num2.end());

			int i = 0;
			string result = "";
			int carry = 0;
			while (i < num1.size() || i < num2.size() || carry) {
				int n1 = i < num1.size() ? num1[i] - '0' : 0;
				int n2 = i < num2.size() ? num2[i] - '0' : 0;
				int sum = n1 + n2 + carry;
				result += to_string(sum % 10);
				carry = sum / 10;
				i++;
			}
			reverse(result.begin(), result.end());
			return result;
		}

		string addStringsAnother(string num1, string num2) {
			int len1 = num1.size();
			int len2 = num2.size();
			int i = 1;
			string result = "";
			int carry = 0;

			while (len1 - i >= 0 || len2 - i >= 0 || carry) {
				int n1 = len1 - i >= 0 ? num1[len1 - i] - '0' : 0;
				int n2 = len2 - i >= 0 ? num2[len2 - i] - '0' : 0;
				int sum = n1 + n2 + carry;
				result = to_string(sum % 10) + result;
				carry = sum / 10;
				i++;
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

