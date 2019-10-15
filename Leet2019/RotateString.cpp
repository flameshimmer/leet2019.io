#include "stdafx.h"
/*We are given two strings, A and B.

A shift on A consists of taking string A and moving the 
leftmost character to the rightmost position. For example, 
if A = 'abcde', then it will be 'bcdea' after one shift on A. 
Return True if and only if A can become B after some number
of shifts on A.

Example 1:
Input: A = 'abcde', B = 'cdeab'
Output: true

Example 2:
Input: A = 'abcde', B = 'abced'
Output: false
Note:

A and B will have length at most 100.*/ 

namespace Solution2019
{
	namespace RotateString
	{
		bool rotateString(string A, string B) {
			return A.size() == B.size() && (A + A).find(B) != string::npos;
		}

		bool rotateStringAnother(string A, string B) {
			B += B;
			auto pos = B.find(A);
			if (pos == string::npos) { return false; }

			string s1 = B.substr(0, pos);
			string s2 = B.substr(pos + A.size());
			return s2 + s1 == A;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

