#include "stdafx.h"
//Given an array of meeting time intervals consisting of 
//start and end times [[s1,e1],[s2,e2],...] (si < ei), 
//determine if a person could attend all meetings.
//
//Example 1:
//Input: [[0,30],[5,10],[15,20]]
//Output: false
//
//Example 2:
//Input: [[7,10],[2,4]]
//Output: true
//
//NOTE: input types have been changed on April 15, 2019. 
//Please reset to default code definition to get new method signature.
namespace Solution2019
{
	namespace MeetingRooms
	{
		bool canAttendMeetings(vector<vector<int>>& intervals) {
			auto comp = [](vector<int>& a, vector<int>& b) {
				if (a[0] == b[0]) { return a[1] < b[1]; }
				return a[0] < b[0];
			};

			sort(intervals.begin(), intervals.end(), comp);

			for (int i = 1; i < intervals.size(); i++) {
				if (intervals[i - 1][1] > intervals[i][0]) { return false; }
			}
			return true;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

