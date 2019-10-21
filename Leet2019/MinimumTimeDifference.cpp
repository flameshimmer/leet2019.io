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
		int findMinDifference(vector<string>& times) {
			vector<int> temp;
			for (string t : times) {
				temp.push_back(stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2)));
			}

			sort(temp.begin(), temp.end());
			temp.push_back(temp[0] + 24 * 60);

			int minDiff = INT_MAX;
			for (int i = 1; i < temp.size(); i++) {
				minDiff = min(minDiff, temp[i] - temp[i - 1]);
			}
			return minDiff;
		}

		namespace Another {
			int timeDiff(string& t1, string& t2) {
				int h1 = stoi(t1.substr(0, 2));
				int m1 = stoi(t1.substr(3, 2));
				int h2 = stoi(t2.substr(0, 2));
				int m2 = stoi(t2.substr(3, 2));
				return (h2 - h1) * 60 + (m2 - m1);
			}

			int findMinDifference(vector<string>& times) {
				int len = times.size();
				sort(times.begin(), times.end());
				int minDiff = INT_MAX;

				for (int i = 0; i < len; i++) {
					int diff = abs(timeDiff(times[(i - 1 + len) % len], times[i]));
					diff = min(diff, 1440 - diff);
					minDiff = min(minDiff, diff);
				}
				return minDiff;
			}
		}

		void Main() {
			vector<string> test = { "23:59","00:00" };
			print(findMinDifference(test));
		}
	}
}

