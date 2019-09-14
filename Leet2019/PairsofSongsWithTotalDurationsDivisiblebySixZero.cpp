#include "stdafx.h"
//In a list of songs, the i-th song has a duration of time[i] seconds. 
//
//Return the number of pairs of songs for which their total duration 
//in seconds is divisible by 60.  Formally, we want the number of 
//indices i < j with (time[i] + time[j]) % 60 == 0.
//
//Example 1:
//Input: [30,20,150,100,40]
//Output: 3
//Explanation: Three pairs have a total duration divisible by 60:
//(time[0] = 30, time[2] = 150): total duration 180
//(time[1] = 20, time[3] = 100): total duration 120
//(time[1] = 20, time[4] = 40): total duration 60
//
//Example 2:
//Input: [60,60,60]
//Output: 3
//Explanation: All three pairs have a total duration of 120, which is divisible by 60.
// 
//Note:
//1 <= time.length <= 60000
//1 <= time[i] <= 500

namespace Solution2019
{
	namespace PairsofSongsWithTotalDurationsDivisiblebySixZero
	{
		int numPairsDivisibleBy60(vector<int>& time) {
			vector<int> counts(60, 0);
			int result = 0;
			for (int i : time) {
				result += counts[(60 - i % 60) % 60];
				counts[i % 60]++;
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

