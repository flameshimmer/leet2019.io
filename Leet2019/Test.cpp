#include "stdafx.h"
// Test template
//
//Input  : str = “abcba”
//	Output : Yes
//	we can remove character ‘c’ to make string palindrome
//
//	Input : str = “abcbea”
//	Output : Yes
//	we can remove character ‘e’ to make string palindrome
//
//	Input : str = “abecbea”
//	It is not possible to make this string palindrome
//	just by removing one character
namespace Solution2019
{
	namespace Test
	{
		bool isValidIpV4(istringstream& ss) {
			string num;
			int count = 0;
			while (getline(ss, num, '.')) {
				count++;
				int len = num.size();
				if (len == 0 || len > 3) { return false; }
				if (len > 1 && num[0] == '0') { return false; }
				int val = 0;
				for (char c : num) {
					if (!isdigit(c)) { return false; }
					val = val * 10 + (c - '0');
					if (val > 255) { return false; }
				}
			}
			if (count != 4) { return false; }
			return true;
		}

		bool isValidIpV6(istringstream& ss) {
			string validChar = "0123456789abcdefABCDEF";
			string num;
			int count = 0;
			while (getline(ss, num, ':')) {
				count++;
				int len = num.size();
				if (len == 0 || len > 4) { return false; }
				for (char c : num) {
					if (!isalnum(c) || validChar.find(c) == string::npos) { return false; }
				}
			}
			if (count != 8) { return false; }
			return true;
		}

		string validIPAddress(string IP) {
			istringstream ss(IP);
			if (isValidIpV4(ss)) { return "IPv4"; }
			istringstream ss2(IP);
			if (isValidIpV6(ss2)) { return "IPv6"; }
			return "Neither";
		}

		void Main() {
			print(validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334:"));
		}
	}
}
