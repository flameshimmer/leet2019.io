#include "stdafx.h"
//Given a collection of integers that might contain duplicates,
//nums, return all possible subsets (the power set).
//
//Note: The solution set must not contain duplicate subsets.
//
//Example:
//
//Input: [1,2,2]
//Output:
//[
//  [2],
//  [1],
//  [1,2,2],
//  [2,2],
//  [1,2],
//  []
//]

namespace Solution2019
{
	void helper(vector<int>& nums, int start, int len, vector<int>& result, vector<vector<int>>& results) {
		results.push_back(result);

		if (start == len) { return; }
		for (int i = start; i < len; i++) {
			result.push_back(nums[i]);
			helper(nums, i + 1, len, result, results);
			result.pop_back();
			while (i + 1 < len && nums[i] == nums[i + 1]) { i++; }
		}
	}

	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		int len = nums.size();
		vector<int> result;
		vector<vector<int>> results;
		sort(nums.begin(), nums.end());

		helper(nums, 0, len, result, results);
		return results;
	}
	namespace SubsetsII
	{
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

