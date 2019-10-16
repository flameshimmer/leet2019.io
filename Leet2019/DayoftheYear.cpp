#include "stdafx.h"
//Given a string date representing a Gregorian calendar date
//formatted as YYYY-MM-DD, return the day number of the year.
//
//Example 1:
//Input: date = "2019-01-09"
//Output: 9
//Explanation: Given date is the 9th day of the year in 2019.
//
//Example 2:
//Input: date = "2019-02-10"
//Output: 41
//
//Example 3:
//Input: date = "2003-03-01"
//Output: 60
//
//Example 4:
//Input: date = "2004-03-01"
//Output: 61
// 
//Constraints:
//date.length == 10
//date[4] == date[7] == '-', and all other date[i]'s are digits
//date represents a calendar date between Jan 1st, 1900 and Dec 31, 2019.

namespace Solution2019
{
	namespace DayoftheYear
	{
		int dayOfYear(string date) {
			int year = stoi(date.substr(0, 4));
			int month = stoi(date.substr(5, 2));
			int day = stoi(date.substr(8));
			int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

			int result = day;
			if (month > 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)) { result++; }
			for (int i = 0; i < month - 1; i++) {
				result += days[i];
			}
			return result;
		}

		int dayOfYearAnother(string date) {
			istringstream ss(date);
			string val;
			vector<int> date2;
			while (getline(ss, val, '-')) {
				date2.push_back(stoi(val));
			}

			int days1[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
			int days2[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

			int year = date2[0];
			int month = date2[1];
			int day = date2[2];
			bool leap = false;
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) { leap = true; }

			int result = day;
			for (int i = 0; i < month - 1; i++) {
				if (leap) {
					result += days2[i];
				}
				else {
					result += days1[i];
				}
			}
			return result;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

