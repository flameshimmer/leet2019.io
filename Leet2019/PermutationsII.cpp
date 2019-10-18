#include "stdafx.h"
//Given a collection of numbers that might contain duplicates, 
//return all possible unique permutations.
//
//Example:
//
//Input: [1,1,2]
//Output:
//[
//  [1,1,2],
//  [1,2,1],
//  [2,1,1]
//]

namespace Solution2019
{
	namespace PermutationsII
	{
		void helper(vector<int>& nums, int start, int len, vector<int>& candidate, vector<int>& result, vector<vector<int>>& results) {
			if (start == len) {
				results.push_back(result);
				return;
			}

			for (int i = 0; i < len; i++)
			{
				if (candidate[i]) {
					result.push_back(nums[i]);
					candidate[i] = false;
					helper(nums, start + 1, len, candidate, result, results);
					result.pop_back();
					candidate[i] = true;
					while (i + 1 < len && nums[i] == nums[i + 1]) { i++; }
				}
			}
		}

		vector<vector<int>> permuteUnique(vector<int>& nums) {
			vector<vector<int>> results;
			int len = nums.size();
			if (len == 0) { return results; }

			vector<int> result;
			vector<int> candidate(len, true);
			sort(nums.begin(), nums.end());
			helper(nums, 0, len, candidate, result, results);
			return results;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

