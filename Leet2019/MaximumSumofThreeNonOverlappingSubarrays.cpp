#include "stdafx.h"
//In a given array nums of positive integers, find three 
//non-overlapping subarrays with maximum sum.
//
//Each subarray will be of size k, and we want to maximize
//the sum of all 3*k entries.
//
//Return the result as a list of indices representing the 
//starting position of each interval (0-indexed). If there 
//are multiple answers, return the lexicographically 
//smallest one.
//
//Example:
//Input: [1,2,1,2,6,7,5,1], 2
//Output: [0, 3, 5]
//Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond 
//to the starting indices [0, 3, 5].
//We could have also taken [2, 1], but an answer of [1, 3, 5]
//would be lexicographically larger.
// 
//Note:
//nums.length will be between 1 and 20000.
//nums[i] will be between 1 and 65535.
//k will be between 1 and floor(nums.length / 3).

namespace Solution2019
{
	namespace MaximumSumofThreeNonOverlappingSubarrays
	{
		vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
			int n = nums.size();
			int maxsum = 0;
			vector<int> sum = { 0 };
			vector<int> posLeft(n, 0);
			vector<int> posRight(n, n - k);
			vector<int> ans(3, 0);

			for (int i : nums) { sum.push_back(sum.back() + i); }

			for (int i = k, tot = sum[k] - sum[0]; i < n; i++) {
				if (sum[i + 1] - sum[i + 1 - k] > tot) {
					posLeft[i] = i + 1 - k;
					tot = sum[i + 1] - sum[i + 1 - k];
				}
				else {
					posLeft[i] = posLeft[i - 1];
				}
			}
			for (int i = n - 1 - k, tot = sum[n] - sum[n - k]; i >= 0; i--) {
				if (sum[i + k] - sum[i] >= tot) {
					posRight[i] = i;
					tot = sum[i + k] - sum[i];
				}
				else {
					posRight[i] = posRight[i + 1];
				}
			}

			for (int i = k; i <= n - 2 * k; i++) {
				int l = posLeft[i - 1];
				int r = posRight[i + k];
				int tot = (sum[i + k] - sum[i]) + (sum[l + k] - sum[l]) + (sum[r + k] - sum[r]);
				if (tot > maxsum) {
					maxsum = tot;
					ans = { l, i, r };
				}
			}
			return ans;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

