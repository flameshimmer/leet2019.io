#include "stdafx.h"

//Given an integer (signed 32 bits), write a function to check whether it is a
//power of 4.
//
//Example 1:
//Input: 16
//Output: true
//
//Example 2:
//Input: 5
//Output: false
//Follow up: Could you solve it without loops/recursion? 

namespace Solution2019
{
	namespace PowerofFour
	{
		bool isPowerOfFour(int num) {
			double d = log10(num) / log10(4);
			return num > 0 && ceil(d) == floor(d);
		}

		bool isPowerOfFourAnother(int num) {
			return num > 0 && (num & (num - 1)) == 0 && (num & 0x55555555) != 0;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

