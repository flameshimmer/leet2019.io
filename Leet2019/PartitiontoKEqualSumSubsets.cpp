#include "stdafx.h"

//Given an array of integers nums and a positive integer k, find whether it's
//possible to divide this array into k non-empty subsets whose sums are all
//equal.
// 
//
//Example 1:
//Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
//Output: True
//Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3),
//(2,3) with equal sums.
// 
//
//Note:
//1 <= k <= len(nums) <= 16.
//0 < nums[i] < 10000. 

namespace Solution2019
{
	namespace PartitiontoKEqualSumSubsets
	{
		bool canPartitionKSubsets(vector<int>& nums, int k) {
			int sum = accumulate(nums.begin(), nums.end(), 0);
			if (k <= 0 || sum % k != 0) { return false; }

			vector<bool> visited(nums.size(), false);
			return canPartition(nums, visited, 0, k - 1, 0, sum / k);
		}

		bool canPartition(vector<int>& nums, vector<bool>& visited, int start, int k, int curSum, int target) {
			if (k == 0) { return true; }
			if (curSum == target) {
				return canPartition(nums, visited, 0, k - 1, 0, target);
			}

			for (int i = start; i < nums.size(); i++) {
				if (!visited[i]) {
					visited[i] = true;
					if (canPartition(nums, visited, i + 1, k, curSum + nums[i], target)) { return true; }
					visited[i] = false;
				}
			}
			return false;
		}

		namespace Faster {
			bool res = false;
			bool canPartitionKSubsets(std::vector<int>& nums, int k) {
				if (nums.size() < k) return false;
				sort(nums.begin(), nums.end(), std::greater<int>());
				int sum = 0, max = std::numeric_limits<int>::min();
				for (int i : nums) {
					sum += i;
					if (i > max) max = i;
				}
				if (sum % k != 0 || max > sum / k) return false;
				std::vector<int> bs(k, 0);
				BT(nums, sum / k, 0, bs);
				return res;
			}

			void BT(std::vector<int>& ns, int lim, int pos, std::vector<int>& buckets) {
				if (res) return; // stop immediately
				if (pos >= ns.size()) {
					res = true;
					return;
				}
				bool flag = false;
				for (int i = 0; i < buckets.size(); i++) {
					if (flag && buckets[i] == 0) continue; //pruning, avoid putting an element into empty buckets repeatedly
					if (buckets[i] == 0) flag = true;
					if (buckets[i] + ns[pos] > lim) continue;
					buckets[i] += ns[pos];
					BT(ns, lim, pos + 1, buckets);
					buckets[i] -= ns[pos];
				}
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

