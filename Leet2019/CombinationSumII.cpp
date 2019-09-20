#include "stdafx.h"
//Given a collection of candidate numbers (candidates) and a target 
//number (target), find all unique combinations in candidates where
//the candidate numbers sums to target.
//
//Each number in candidates may only be used once in the combination.
//
//Note:
//All numbers (including target) will be positive integers.
//The solution set must not contain duplicate combinations.
//
//Example 1:
//Input: candidates = [10,1,2,7,6,1,5], target = 8,
//A solution set is:
//[
//  [1, 7],
//  [1, 2, 5],
//  [2, 6],
//  [1, 1, 6]
//]
//
//Example 2:
//Input: candidates = [2,5,2,1,2], target = 5,
//A solution set is:
//[
//  [1,2,2],
//  [5]
//]

namespace Solution2019
{
	namespace CombinationSumII
	{
		void comboHelper(vector<int>& can, int start, int len, int sum, int target, vector<int>& result, vector<vector<int>>& results) {
			if (sum == target) { results.push_back(result); }
			if (sum >= target) { return; }

			for (int i = start; i < len; i++) {
				result.push_back(can[i]);
				comboHelper(can, i + 1, len, sum + can[i], target, result, results);
				result.pop_back();
				while (i+1 < len && can[i] == can[i + 1]) { i++; }
			}
		}

		vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
			sort(candidates.begin(), candidates.end());
			vector<vector<int>> results;
			vector<int> result;
			int len = candidates.size();
			int sum = 0;
			comboHelper(candidates, 0, len, sum, target, result, results);
			return results;
		}

		void Main() {
			vector<int> can = { 10,1,2,7,6,1,5 };
			print(combinationSum2(can, 8));
		}
	}
}

