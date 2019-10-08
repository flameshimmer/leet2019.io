#include "stdafx.h"
//Given a sorted integer array nums, where the range of 
//elements are in the inclusive range [lower, upper], 
//return its missing ranges.
//
//Example:
//Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
//Output: ["2", "4->49", "51->74", "76->99"]

namespace Solution2019
{
	namespace MissingRanges
	{
		string getRange(int start, int end) {
			return start == end ? to_string(start) : to_string(start) + "->" + to_string(end);
		}

		vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
			vector<string> result;
			long int prev = (long)lower - 1;

			int len = nums.size();
			for (int i = 0; i <= len; i++) {
				long int cur;
				if (i == len) { cur = (long)upper + 1; }
				else { cur = (long)nums[i]; }
				if (cur - prev >= 2) {
					result.push_back(getRange(prev + 1, cur - 1));
				}
				prev = cur;
			}

			return result;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

