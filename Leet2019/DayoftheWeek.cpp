#include "stdafx.h"
//Given a date, return the corresponding day of the week for that date.
//
//The input is given as three integers representing the day, month and
//year respectively.
//
//Return the answer as one of the following values {"Sunday", "Monday", 
//"Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}.
//
//Example 1:
//Input: day = 31, month = 8, year = 2019
//Output: "Saturday"
//
//Example 2:
//Input: day = 18, month = 7, year = 1999
//Output: "Sunday"
//
//Example 3:
//Input: day = 15, month = 8, year = 1993
//Output: "Sunday"
// 
//Constraints:
//The given dates are valid dates between the years 1971 and 2100.

namespace Solution2019
{
	namespace DayoftheWeek
	{
		int daysOfMonth[2][12] = {
	   31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
	   31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
		};

		bool isLeapYear(int year) {
			return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
		}

		int daysSince1970(int year, int month, int day) {
			int result = 0;
			for (int i = 1970; i < year; i++) {
				result += isLeapYear(i) ? 366 : 365;
			}
			for (int i = 0; i < month - 1; i++) {
				result += daysOfMonth[!isLeapYear(year)][i];
			}
			result += day-1;
			return result;
		}
		
		
		string dayOfTheWeek(int day, int month, int year) {
			string weekName[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
			int daysLastSunday = daysSince1970(2019,9, 8);
			int daysTarget = daysSince1970(year, month, day);
			int daysOff = (((daysTarget - daysLastSunday) % 7) + 7) % 7;
			return weekName[daysOff];
		}

		void Main() {
			//print(dayOfTheWeek(9, 9, 2019));
			print(dayOfTheWeek(31, 8, 2019));
		}
	}
}

