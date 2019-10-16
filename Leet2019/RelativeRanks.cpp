#include "stdafx.h"
//Given scores of N athletes, find their relative ranks and
//the people with the top three highest scores, who will be 
//awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".
//
//Example 1:
//Input: [5, 4, 3, 2, 1]
//Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
//Explanation: The first three athletes got the top three 
//highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
//For the left two athletes, you just need to output their
//relative ranks according to their scores.
//
//Note:
//N is a positive integer and won't exceed 10,000.
//All the scores of athletes are guaranteed to be unique.

namespace Solution2019
{
	namespace RelativeRanks
	{
		vector<string> findRelativeRanks(vector<int>& nums) {
			map<int, int, greater<int>> rank;
			for (int i = 0; i < nums.size(); i++) {
				rank[nums[i]] = i;
			}

			vector<string> result(nums.size());
			int i = 1;
			for (auto& p : rank) {
				if (i == 1) { result[p.second] = "Gold Medal"; }
				else if (i == 2) { result[p.second] = "Silver Medal"; }
				else if (i == 3) { result[p.second] = "Bronze Medal"; }
				else { result[p.second] = to_string(i); }
				i++;
			}
			return result;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

