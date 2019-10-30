#include "stdafx.h"

//Given two non-negative integers num1 and num2 represented as strings, return
//the product of num1 and num2, also represented as a string.
//
//Example 1:
//Input: num1 = "2", num2 = "3"
//Output: "6"
//
//Example 2:
//Input: num1 = "123", num2 = "456"
//Output: "56088"
//
//Note:
//The length of both num1 and num2 is < 110.
//Both num1 and num2 contain only digits 0-9.
//Both num1 and num2 do not contain any leading zero, except the number 0 itself.
//You must not use any built-in BigInteger library or convert the inputs to
//integer directly.

namespace Solution2019
{
	namespace MultiplyStrings
	{
		string multiply(string num1, string num2) {
			int len1 = num1.size();
			int len2 = num2.size();
			string result(len1 + len2, '0');

			for (int i = len1 - 1; i >= 0; i--) {
				int carry = 0;
				for (int j = len2 - 1; j >= 0; j--) {
					int sum = (num1[i] - '0') * (num2[j] - '0') + carry + (result[i + j + 1] - '0');
					result[i + j + 1] = sum % 10 + '0';
					carry = sum / 10;
				}
				result[i] += carry; // this should be += instead of = because carry is an it, and result[i] is a char!!!
			}

			size_t startpos = result.find_first_not_of("0");
			if (startpos != string::npos) {
				return result.substr(startpos);
			}
			return "0"; // case of all 0s. Should return a single 0
		}

		namespace TraditionalHandCalculation {
			string add(string s1, string s2) {
				int len1 = s1.size();
				int len2 = s2.size();
				int i1 = len1 - 1;
				int i2 = len2 - 1;
				string result;
				int carry = 0;
				int sum = 0;
				while (i1 >= 0 || i2 >= 0 || carry > 0) {
					sum = carry;
					if (i1 >= 0) { sum += s1[i1] - '0'; }
					if (i2 >= 0) { sum += s2[i2] - '0'; }
					result.insert(result.begin(), (sum % 10) + '0');
					carry = sum / 10;
					i1--;
					i2--;
				}
				return result;
			}

			string mul(string s, char c) {
				int cv = c - '0';
				int carry = 0;
				int sum = 0;
				int i = s.size() - 1;
				string result;
				while (i >= 0 || carry > 0) {
					sum = carry;
					if (i >= 0) { sum += (s[i] - '0') * cv; }
					result.insert(result.begin(), (sum % 10) + '0');
					carry = sum / 10;
					i--;
				}
				return result;
			}

			string multiply(string num1, string num2) {
				if (num1 == "0" || num2 == "0") { return "0"; }

				string result = "0";
				string append = "";
				string mulResult;
				for (int i = num2.size() - 1; i >= 0; i--) {
					mulResult = mul(num1, num2[i]) + append;
					result = add(result, mulResult);
					append += '0';
				}
				return result;
			}
		}
		void Main() {
			string test = "tst test test";
			print(multiply("2", "3"));
			print(multiply("123", "456"));
		}
	}
}

