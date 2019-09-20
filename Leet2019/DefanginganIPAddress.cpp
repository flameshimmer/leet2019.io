#include "stdafx.h"
#include <regex>
//Given a valid (IPv4) IP address, return a defanged version of that IP address.
//
//A defanged IP address replaces every period "." with "[.]".
//
//Example 1:
//Input: address = "1.1.1.1"
//Output: "1[.]1[.]1[.]1"
//Example 2:
//
//Input: address = "255.100.50.0"
//Output: "255[.]100[.]50[.]0"
// 
//Constraints:
//The given address is a valid IPv4 address.

namespace Solution2019
{
	namespace DefanginganIPAddress
	{
		string defangIPaddr(string address) {
			string result = "";
			for (char c : address) {
				if (c != '.') { result += c; }
				else {
					result += "[.]";
				}
			}
			return result;
		}

		string defangIPaddrRegex(string address) {
			return regex_replace(address, regex("[.]"), "[.]");
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

