#include "stdafx.h"
//In a row of seats, 1 represents a person sitting in that seat, 
//and 0 represents that the seat is empty. 
//
//There is at least one empty seat, and at least one person sitting.
//
//Alex wants to sit in the seat such that the distance between
//him and the closest person to him is maximized. 
//
//Return that maximum distance to closest person.
//
//Example 1:
//Input: [1,0,0,0,1,0,1]
//Output: 2
//Explanation: 
//If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.
//If Alex sits in any other open seat, the closest person has distance 1.
//Thus, the maximum distance to the closest person is 2.
//
//Example 2:
//Input: [1,0,0,0]
//Output: 3
//Explanation: 
//If Alex sits in the last seat, the closest person is 3 seats away.
//This is the maximum distance possible, so the answer is 3.
//Note:
//
//1 <= seats.length <= 20000
//seats contains only 0s or 1s, at least one 0, and at least one 1.

namespace Solution2019
{
	namespace MaximizeDistancetoClosestPerson
	{
		int maxDistToClosest(vector<int>& seats) {
			int maxLen = 0;
			int len = seats.size();

			int end = 0;
			int start = 0;
			while (end < len) {
				while (end < len && seats[end] == 1) { end++; }
				if (end == len) { break; }
				start = end;
				while (end < len && seats[end] == 0) { end++; }
				if (start == 0 || end == len) { maxLen = max(maxLen, end - start); }
				else { maxLen = max(maxLen, (end - start + 1) / 2); }
			}
			return maxLen;
		}

		void Main() {
			vector<int> seats = { 1,0,0,1 };
			print(maxDistToClosest(seats));
		}
	}
}

