#include "stdafx.h"
//Given a set of distinct integers, nums, return 
//all possible subsets (the power set).
//
//Note: The solution set must not contain duplicate subsets.
//
//Example:
//
//Input: nums = [1,2,3]
//Output:
//[
//  [3],
//  [1],
//  [2],
//  [1,2,3],
//  [1,3],
//  [2,3],
//  [1,2],
//  []
//]

namespace Solution2019
{
	namespace Subsets
	{
		void subsetInternal(vector<int>& nums, int start, int len, vector<int>& result, vector<vector<int>>& results) {
			results.push_back(result);

			if (start == len) { return; }

			for (int i = start; i < len; i++) {
				result.push_back(nums[i]);
				subsetInternal(nums, i + 1, len, result, results);
				result.pop_back();
				while (start+1 < len && nums[start] == nums[start + 1]) { start++; }
			}			
		}


		vector<vector<int>> subsets(vector<int>& nums) {
			int len = nums.size();
			sort(nums.begin(), nums.end());
			vector<vector<int>> results;
			vector<int> result;

			subsetInternal(nums, 0, len, result, results);
			return results;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

