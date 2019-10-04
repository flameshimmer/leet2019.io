#include "stdafx.h"
//Given a sorted integer array without duplicates, 
//return the summary of its ranges.
//
//Example 1:
//Input:  [0,1,2,4,5,7]
//Output: ["0->2","4->5","7"]
//Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
//
//Example 2:
//Input:  [0,2,3,4,6,8,9]
//Output: ["0","2->4","6","8->9"]
//Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.

namespace Solution2019
{
	namespace SummaryRanges
	{
		vector<string> summaryRanges(vector<int>& nums) {
			vector<string> result;
			int len = nums.size();
			if (len == 0) { return result; }

			int start = 0;
			int end = 0;
			while (end < len) {
				while (end + 1 < len && nums[end] + 1 == nums[end + 1]) { end++; }
				if (start == end) {
					result.push_back(to_string(nums[start]));
				}
				else {
					result.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
				}
				end++;
				start = end;
			}
			return result;
		}

		vector<string> summaryRangesAnother(vector<int>& nums) {
			vector<string> result;
			int len = nums.size();
			if (len == 0) { return result; }

			int l = 0;
			for (int r = 1; r <= len; r++) {
				if (r == len || nums[r] != nums[r - 1] + 1) { ////--------------->>> For 2 pointer type issue, remember to check when r out of bound!!!!
					if (r - 1 == l) { result.push_back(to_string(nums[l])); }
					else {
						result.push_back(to_string(nums[l]) + "->" + to_string(nums[r - 1]));
					}
					l = r;
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

