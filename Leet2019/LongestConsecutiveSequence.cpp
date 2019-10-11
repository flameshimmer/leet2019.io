#include "stdafx.h"
/*Given an unsorted array of integers, find the length 
of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:
Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence 
is [1, 2, 3, 4]. Therefore its length is 4.*/ 

namespace Solution2019
{
	namespace LongestConsecutiveSequence
	{
		int longestConsecutive(vector<int>& nums) {
			int result = 0;
			unordered_map<int, int> map;
			for (int v : nums) {
				if (map.count(v) > 0) { continue; }

				int left = map.count(v - 1) ? map[v - 1] : 0;
				int right = map.count(v + 1) ? map[v + 1] : 0;
				int sum = left + right + 1;
				map[v] = sum;
				result = max(result, sum);
				map[v - left] = sum;
				map[v + right] = sum;
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

