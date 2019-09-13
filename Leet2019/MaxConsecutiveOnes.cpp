#include "stdafx.h"
//Given a binary array, find the maximum number of consecutive 1s in this array.
//
//Example 1:
//Input: [1, 1, 0, 1, 1, 1]
//	Output : 3
//	Explanation : The first two digits or the last three digits are consecutive 1s.
//	The maximum number of consecutive 1s is 3.
//	Note :
//
//	The input array will only contain 0 and 1.
//	The length of input array is a positive integer and will not exceed 10, 000

namespace Solution2019
{
	namespace MaxConsecutiveOnes
	{
		int findMaxConsecutiveOnes(vector<int>& nums) {
			int len = nums.size();
			if (len == 0) { return 0; }

			int result = 0;
			int cur = 0;
			for (int i : nums) {
				if (i != 1) {
					result = max(result, cur);
					cur = 0;
				}
				else {
					cur++;
				}
			}
			result = max(result, cur);
			return result;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

