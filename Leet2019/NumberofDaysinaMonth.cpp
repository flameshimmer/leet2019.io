#include "stdafx.h"
//Given a year Y and a month M, return how 
//many days there are in that month.
//
//Example 1:
//Input: Y = 1992, M = 7
//Output: 31
//
//Example 2:
//Input: Y = 2000, M = 2
//Output: 29
//
//Example 3:
//Input: Y = 1900, M = 2
//Output: 28
//
//Note:
//1583 <= Y <= 2100
//1 <= M <= 12

namespace Solution2019
{
	namespace NumberofDaysinaMonth
	{
		int numberOfDays(int Y, int M) {
			int normalYear[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
			int leapYear[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

			bool isLeapYear = (Y % 4 == 0 && Y % 100 != 0) || Y % 400 == 0;
			if (isLeapYear) {
				return leapYear[M - 1];
			}
			return normalYear[M - 1];
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

