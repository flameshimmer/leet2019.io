#include "stdafx.h"
//Given an array of non-negative integers, you are 
//initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump 
//length at that position.
//
//Your goal is to reach the last index in the minimum number of jumps.
//
//Example:
//Input: [2,3,1,1,4]
//Output: 2
//Explanation: The minimum number of jumps to reach the last index is 2.
//Jump 1 step from index 0 to 1, then 3 steps to the last index.
//
//Note:
//You can assume that you can always reach the last index.
namespace Solution2019
{
	namespace JumpGameII
	{
		int jump(vector<int>& nums) {
			int len = nums.size();
			if (len == 0) { return 0; }

			int start = 0;
			int end = 0;
			int result = 0;
			int reach = 0;
			for (int i = 0; i < len; i++) {
				while (reach < len - 1) {
					result++;
					for (int i = start; i <= end; i++) {
						reach = max(reach, i + nums[i]);
					}
					start = end + 1;
					end = reach;
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

