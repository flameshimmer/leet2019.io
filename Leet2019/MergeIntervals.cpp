#include "stdafx.h"
//Given a collection of intervals, merge all overlapping intervals.
//
//Example 1:
//Input: [[1,3],[2,6],[8,10],[15,18]]
//Output: [[1,6],[8,10],[15,18]]
//Explanation: Since intervals [1,3] and [2,6] overlaps, 
//merge them into [1,6].
//
//Example 2:
//Input: [[1,4],[4,5]]
//Output: [[1,5]]
//Explanation: Intervals [1,4] and [4,5] are considered overlapping.
//
//NOTE: input types have been changed on April 15, 2019. 
//Please reset to default code definition to get new method signature.

namespace Solution2019
{
	namespace MergeIntervals
	{
		vector<vector<int>> merge(vector<vector<int>>& intervals) {
			vector<vector<int>> result;

			auto comp = [](vector<int>& a, vector<int>& b) {return a[0] < b[0]; };
			sort(intervals.begin(), intervals.end(), comp);

			for (vector<int> cur : intervals) {
				if (result.empty() || cur[0] > result.back()[1]) {
					result.push_back(cur);
				}
				else {
					result.back()[1] = max(result.back()[1], cur[1]);
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

