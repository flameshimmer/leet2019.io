#include "stdafx.h"
//Given an integer array nums, find the contiguous subarray 
//(containing at least one number) which has the largest sum and return its sum.
//
//Example:
//
//Input: [-2,1,-3,4,-1,2,1,-5,4],
//Output: 6
//Explanation: [4,-1,2,1] has the largest sum = 6.
//Follow up:
//
//If you have figured out the O(n) solution, try coding another 
//solution using the divide and conquer approach, which is more subtle. 

namespace Solution2019
{
	namespace MaximumSubarray
	{
		int maxSubArray(vector<int>& nums) {
			int len = nums.size();
			if (len == 0) { return 0; }

			int maxSum = nums[0];
			int sum = nums[0];
			for (int i = 1; i < len; i++) {
				sum = max(0, sum) + nums[i];  
				maxSum = max(maxSum, sum);
			}
			return maxSum;
		}

		int maxSubArrayModifyInputArray(vector<int>& nums) {
			int result = nums[0];
			for (int i = 1; i < (int)nums.size(); i++) {
				nums[i] = max(nums[i], nums[i - 1] + nums[i]);
				result = max(result, nums[i]);
			}
			return result;
		}

		int maxSubArrayDivideAndConquerInternal(vector<int>& nums, int start, int end) {
			if (start == end) { return nums[start]; }
			int mid = start + (end - start) / 2;
			int maxL = maxSubArrayDivideAndConquerInternal(nums, start, mid);
			int maxR = maxSubArrayDivideAndConquerInternal(nums, mid + 1, end);
			int maxMidL = INT_MIN;
			int curSum = 0;
			for (int i = mid; i >= start; i--) {
				curSum += nums[i];
				maxMidL = max(maxMidL, curSum);
			}

			int maxMidR = INT_MIN;
			curSum = 0;
			for (int j = mid + 1; j <= end; j++) {
				curSum += nums[j];
				maxMidR = max(maxMidR, curSum);
			}
			return max(max(maxL, maxR), maxMidL + maxMidR);
		}

		int maxSubArrayDivideAndConquer(vector<int>& nums) {
			int len = nums.size();
			if (len == 0) { return 0; }
			return maxSubArrayDivideAndConquerInternal(nums, 0, len-1);		
		}

		void Main() {
			string test = "tst test test";
			vector<int> input = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
			print(maxSubArrayDivideAndConquer(input));
		}
	}
}

