#include "stdafx.h"

//Given two integers representing the numerator and denominator of a fraction,
//return the fraction in string format.
//If the fractional part is repeating, enclose the repeating part in parentheses.
//
//Example 1:
//Input: numerator = 1, denominator = 2
//Output: "0.5"
//
//Example 2:
//Input: numerator = 2, denominator = 1
//Output: "2"
//
//Example 3:
//Input: numerator = 2, denominator = 3
//Output: "0.(6)"

namespace Solution2019
{
	namespace FractiontoRecurringDecimal
	{
		string fractionToDecimal(int numerator, int denominator) {
			if (!numerator) { return "0"; }
			string result;
			if (numerator > 0 ^ denominator > 0) { result += '-'; }
			long long n = labs(numerator);
			long long d = labs(denominator);
			result += to_string(n / d);
			long long r = n % d;
			if (!r) { return result; }

			result += '.';
			unordered_map<long long, int> insertPos; // remain, pos
			while (r) {
				if (insertPos.find(r) != insertPos.end()) {
					result.insert(insertPos[r], "(");
					result += ')';
					break;
				}
				insertPos[r] = result.size();
				r *= 10;
				result += to_string(r / d);
				r %= d;
			}
			return result;
		}

		void Main() {
			print(fractionToDecimal(7, -12));
			print(fractionToDecimal(1, 2));
			print(fractionToDecimal(2, 3));
		}
	}
}

