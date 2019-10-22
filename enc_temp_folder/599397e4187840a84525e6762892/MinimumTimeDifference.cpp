#include "stdafx.h"
//Given a list of 24-hour clock time points in "Hour:Minutes" format,
//find the minimum minutes difference between any two time points in the list.
//
//Example 1:
//Input: ["23:59","00:00"]
//Output: 1
//
//Note:
//The number of time points in the given list is at least 2 and won't exceed 20000.
//The input time is legal and ranges from 00:00 to 23:59.

namespace Solution2019
{
	namespace MinimumTimeDifference
	{
		int getMin(string s) {
			int hour = stoi(s.substr(0, 2));
			int min = stoi(s.substr(3, 2));
			return hour * 60 + min;
		}

		int findMinDifference(vector<string>& timePoints) {
			int special = getMin("24:00");
			int minDiff = INT_MAX;
			for (int i = 1; i < timePoints.size(); i++)
			{
				int m1 = getMin(timePoints[i - 1]);
				int m2 = getMin(timePoints[i]);
				int diff = m2 - m1;
				if (diff < 0) {
					diff = special - m1 + m2;
				}
				minDiff = min(minDiff, diff);
			}

			return minDiff;
		}

		void Main() {
			vector<string> test = { "00:00","23:59","00:00" };
			print(findMinDifference(test));
		}
	}
}

