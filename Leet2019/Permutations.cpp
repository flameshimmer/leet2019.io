#include "stdafx.h"
//Given a collection of distinct integers, return all possible permutations.
//
//Example:
//
//Input: [1,2,3]
//Output:
//[
//  [1,2,3],
//  [1,3,2],
//  [2,1,3],
//  [2,3,1],
//  [3,1,2],
//  [3,2,1]
//]

namespace Solution2019
{
	namespace Permutations
	{
		void helper(vector<int>& nums, int start, int len, vector<bool>& candidate, vector<int>& result, vector<vector<int>>& results) {
			if (start == len) {
				results.push_back(result);
				return;
			}

			for (int i = 0; i < len; i++) {
				if (candidate[i]) {
					result.push_back(nums[i]);
					candidate[i] = false;
					helper(nums, start + 1, len, candidate, result, results);
					result.pop_back();
					candidate[i] = true;
				}
			}
		}


		vector<vector<int>> permute(vector<int>& nums) {
			vector<vector<int>> results;
			int len = nums.size();
			if (len == 0) { return results; }

			vector<int> result;
			vector<bool> candidate(len, true);
			helper(nums, 0, len, candidate, result, results);
			return results;
		}

		void Main() {
			vector<int> test = { 1, 2, 3 };
			print(permute(test));
		}
	}
}

