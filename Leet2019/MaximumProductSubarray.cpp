#include "stdafx.h"
//Given an integer array nums, find the contiguous subarray
//within an array (containing at least one number) which has
//the largest product.
//
//Example 1:
//Input: [2,3,-2,4]
//Output: 6
//Explanation: [2,3] has the largest product 6.
//
//Example 2:
//Input: [-2,0,-1]
//Output: 0
//Explanation: The result cannot be 2, because [-2,-1] is 
//not a subarray. 

namespace Solution2019
{
	namespace MaximumProductSubarray
	{
		int maxProduct(vector<int>& nums) {
			int result = nums[0];
			int maxR = nums[0];
			int minR = nums[0];

			for (int i = 1; i < nums.size(); i++) {
				if (nums[i] < 0) {
					swap(maxR, minR);
				}
				maxR = max(maxR * nums[i], nums[i]);
				minR = min(minR * nums[i], nums[i]);
				result = max(result, maxR);
			}
			return result;
		}

		//The key point of this problem is : there are only two patterns.
		//One is "aBcD", and the other is "aBcDe", where I use lowercase
		//to denote a negative number, and use upper case to denote a positive number.
		//For the first pattern, the maximum product would be "aBcD";
		//and for the second pattern, the maximum product would be
		//"max (aBcD, BcDe)".
		int maxProductAnother(vector<int>& nums) {
			int len = nums.size();
			if (len == 0) { return 0; }

			int frontProduct = 1;
			int backProduct = 1;
			int result = INT_MIN;
			for (int i = 0; i < len; i++) {
				frontProduct *= nums[i];
				backProduct *= nums[len - 1 - i];
				result = max(result, max(frontProduct, backProduct));
				if (frontProduct == 0) { frontProduct = 1; }
				if (backProduct == 0) { backProduct = 1; }
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

