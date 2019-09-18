#include "stdafx.h"
//Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array),
//some elements appear twice and others appear once.
//
//Find all the elements that appear twice in this array.
//
//Could you do it without extra space and in O(n) runtime?
//
//Example:
//Input:
//[4,3,2,7,8,2,3,1]
//
//Output:
//[2,3]

namespace Solution2019
{
	namespace FindAllDuplicatesinanArray
	{
		vector<int> findDuplicates(vector<int>& nums) {
			vector<int> result;
			for (int i = 0; i < nums.size(); i++) {
				int v = abs(nums[i]); ///---> notice abs!!!!!
				if (nums[v - 1] < 0) { result.push_back(v); }
				else { nums[v - 1] = -nums[v - 1]; }
			}
			return result;

		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

