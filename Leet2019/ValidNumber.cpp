#include "stdafx.h"

//Validate if a given string can be interpreted as a decimal number.
//Some examples:
//"0" => true
//" 0.1 " => true
//"abc" => false
//"1 a" => false
//"2e10" => true
//" -90e3   " => true
//" 1e" => false
//"e3" => false
//" 6e-1" => true
//" 99e2.5 " => false
//"53.5e93" => true
//" --6 " => false
//"-+3" => false
//"95a54e53" => false
//
//Note: It is intended for the problem statement to be ambiguous. You should
//gather all requirements up front before implementing one. However, here is a
//list of characters that can be in a valid decimal number:
//Numbers 0-9
//Exponent - "e"
//Positive/negative sign - "+"/"-"
//Decimal point - "."
//Of course, the context of these characters also matters in the input.
//
//Update (2015-02-10):
//The signature of the C++ function had been updated. If you still see your
//function signature accepts a const char * argument, please click the reload
//button to reset your code definition. 

namespace Solution2019
{
	namespace ValidNumber
	{
		bool isNumber(string s) {
			int len = s.size();
			if (len == 0) { return false; }

			int i = 0;
			while (i < len && s[i] == ' ') { i++; }

			if (s[i] == '+' || s[i] == '-') { i++; }

			int cDot = 0;
			int cDigit = 0;

			while (isdigit(s[i]) || s[i] == '.') {
				s[i] == '.' ? cDot++ : cDigit++;
				i++;
			}
			if (cDot > 1 || cDigit < 1) { return false; }

			if (s[i] == 'e' || s[i] == 'E') {
				i++;
				if (s[i] == '-' || s[i] == '+') { i++; }
				cDot = 0;
				cDigit = 0;
				while (isdigit(s[i]) || s[i] == '.') {
					s[i] == '.' ? cDot++ : cDigit++;
					i++;
				}
				if (cDot > 0 || cDigit < 1) { return false; }
			}

			while (i < len && s[i] == ' ') { i++; }
			return i == len;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

