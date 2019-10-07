#include "stdafx.h"
//Implement next permutation, which rearranges numbers into 
//the lexicographically next greater permutation of numbers.
//
//If such arrangement is not possible, it must rearrange it
//as the lowest possible order (ie, sorted in ascending order).
//
//The replacement must be in-place and use only constant extra memory.
//
//Here are some examples. Inputs are in the left-hand column
//and its corresponding outputs are in the right-hand column.
//
//1,2,3 → 1,3,2
//3,2,1 → 1,2,3
//1,1,5 → 1,5,1

namespace Solution2019
{
	namespace NextPermutation
	{
		void nextPermutation(vector<int>& nums) {
			int len = nums.size();
			if (len < 2) { return; }

			int i = len - 2;
			for (; i >= 0; i--) {
				if (nums[i] < nums[i + 1]) { break; }
			}
			if (i < 0) { sort(nums.begin(), nums.end()); return; }

			int j = len - 1;
			for (; j > i; j--) {
				if (nums[j] > nums[i]) { break; }
			}
			swap(nums[i], nums[j]);
			reverse(nums.begin() + i + 1, nums.end());
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

