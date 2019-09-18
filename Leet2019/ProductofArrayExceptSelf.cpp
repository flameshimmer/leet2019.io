#include "stdafx.h"
//Given an array nums of n integers where n > 1,  return an array 
//output such that output[i] is equal to the product of all the 
//elements of nums except nums[i].
//
//Example:
//Input:  [1,2,3,4]
//Output: [24,12,8,6]
//Note: Please solve it without division and in O(n).
//
//Follow up:
//Could you solve it with constant space complexity? (The output array 
//does not count as extra space for the purpose of space complexity analysis.)
namespace Solution2019
{
	namespace ProductofArrayExceptSelf
	{
		vector<int> productExceptSelf(vector<int>& nums) {			
			int len = nums.size();
			vector<int> result(len, 0);
			result[0] = 1;
			for (int i = 1; i < len; i++) {
				result[i] = result[i - 1] * nums[i - 1];
			}
			int right = 1;
			for (int j = len - 1; j >= 0; j--) {
				result[j] *= right;
				right *= nums[j];
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

