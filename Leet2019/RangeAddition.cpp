#include "stdafx.h"
//Assume you have an array of length n initialized with all 
//0's and are given k update operations.
//
//Each operation is represented as a triplet: [startIndex, endIndex, inc]
//which increments each element of subarray A[startIndex ... endIndex]
//(startIndex and endIndex inclusive) with inc.
//
//Return the modified array after all k operations were executed.
//
//Example:
//
//Input: length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
//Output: [-2,0,3,5,3]
//Explanation:
//
//Initial state:
//[0,0,0,0,0]
//
//After applying operation [1,3,2]:
//[0,2,2,2,0]
//
//After applying operation [2,4,3]:
//[0,2,5,5,3]
//
//After applying operation [0,2,-2]:
//[-2,0,3,5,3]

namespace Solution2019
{
	namespace RangeAddition
	{
		vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
			vector<int> nums(length+1, 0);
			for (vector<int> update : updates) {
				nums[update[0]] += update[2];
				nums[update[1] + 1] -= update[2];
			}
			int sum = 0;
			vector<int> result;
			for (int i = 0; i < length; i++) {
				sum += nums[i];
				result.push_back(sum);
			}
			return result;
		}

		vector<int> getModifiedArrayTooSlow(int length, vector<vector<int>>& updates) {
			vector<int> result(length, 0);
			for (vector<int> update : updates) {
				for (int i = update[0]; i <= update[1]; i++) {
					result[i] += update[2];
				}
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

