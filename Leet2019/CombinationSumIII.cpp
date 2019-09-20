#include "stdafx.h"
//Find all possible combinations of k numbers that add up to a number n, 
//given that only numbers from 1 to 9 can be used and each combination 
//should be a unique set of numbers.
//
//Note:
//All numbers will be positive integers.
//The solution set must not contain duplicate combinations.
//Example 1:
//
//Input: k = 3, n = 7
//Output: [[1,2,4]]
//Example 2:
//
//Input: k = 3, n = 9
//Output: [[1,2,6], [1,3,5], [2,3,4]] 

namespace Solution2019
{
	namespace CombinationSumIII
	{
		void comboHelper(int start, int maxLen, int target, int sum, vector<int>& result, vector<vector<int>>& results) {
			int curLen = result.size();
			if (curLen == maxLen && sum == target) { results.push_back(result); }
			if (curLen >= maxLen || sum > target) { return; }

			for (int i = start; i <= 9; i++) {
				result.push_back(i);
				comboHelper(i + 1, maxLen, target, sum + i, result, results);
				result.pop_back();
			}
		}

		vector<vector<int>> combinationSum3(int k, int n) {
			vector<vector<int>> results;
			vector<int> result;
			int sum = 0;
			
			comboHelper(1, k, n, sum, result, results);
			return results;
		}

		void Main() {			
			print(combinationSum3(3, 9));
		}
	}
}

