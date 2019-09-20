#include "stdafx.h"
//Given a set of candidate numbers (candidates) (without duplicates)
//and a target number (target), find all unique combinations in 
//candidates where the candidate numbers sums to target.
//
//The same repeated number may be chosen from candidates unlimited 
//number of times.
//
//Note:
//All numbers (including target) will be positive integers.
//The solution set must not contain duplicate combinations.
//Example 1:
//
//Input: candidates = [2,3,6,7], target = 7,
//A solution set is:
//[
//  [7],
//  [2,2,3]
//]
//Example 2:
//
//Input: candidates = [2,3,5], target = 8,
//A solution set is:
//[
//  [2,2,2,2],
//  [2,3,3],
//  [3,5]
//]

namespace Solution2019
{
	namespace CombinationSum
	{
		void comboSumHelper(vector<int>& can, int start, int len, int sum, int target, vector<int>& result, vector<vector<int>>& results) {
			if (sum == target) { 
				results.push_back(result); 
			}
			if (sum >= target) { return; }

			for (int i = start; i < len; i++) {
				result.push_back(can[i]);
				comboSumHelper(can, i, len, sum + can[i], target, result, results);
				result.pop_back();
			}			
		}

		vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
			int len = candidates.size();
			vector<vector<int>> results;
			vector<int> result;
			if (len == 0) { return results; }

			int sum = 0;
			comboSumHelper(candidates, 0, len, sum, target, result, results);
			return results;
		}

		void Main() {
			vector<int> candidate = { 2, 3, 5 };
			print(combinationSum(candidate, 8));
		}
	}
}

