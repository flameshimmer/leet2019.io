#include "stdafx.h"

//Given an unsorted array of integers, find the length of longest increasing
//subsequence.
//
//Example:
//Input: [10,9,2,5,3,7,101,18]
//Output: 4 
//Explanation: The longest increasing subsequence is [2,3,7,101], therefore the
//length is 4. 
//
//Note:
//There may be more than one LIS combination, it is only necessary for you to
//return the length.
//Your algorithm should run in O(n2) complexity.
//Follow up: Could you improve it to O(n log n) time complexity?

namespace Solution2019
{
	namespace LongestIncreasingSubsequence
	{
		namespace NlogN {
			int lengthOfLIS(vector<int>& nums) {
				vector<int> result;
				for (int i = 0; i < nums.size(); i++) {
					auto it = lower_bound(result.begin(), result.end(), nums[i]);
					if (it == result.end()) { result.push_back(nums[i]); }
					else { *it = nums[i]; }
				}
				return result.size();
			}
		}

		namespace DP {
			int lengthOfLIS(vector<int>& nums) {
				int len = nums.size();
				if (len == 0) { return 0; }

				vector<int> dp(len, 1);
				int result = 1;
				for (int i = 1; i < len; i++) {
					for (int j = 0; j < i; j++) {
						if (nums[j] < nums[i]) {
							dp[i] = max(dp[i], dp[j] + 1);
						}
					}
					result = max(result, dp[i]);
				}
				return result;
			}
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

