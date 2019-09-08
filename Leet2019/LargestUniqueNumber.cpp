#include "stdafx.h"
//Given an array of integers A, return the largest integer that
//only occurs once. If no integer occurs once, return -1.
//
//Example 1:
//Input: [5,7,3,9,4,9,8,3,1]
//Output: 8
//Explanation: 
//The maximum integer in the array is 9 but it is repeated. 
//The number 8 occurs only once, so it's the answer.
//
//Example 2:
//Input: [9,9,8,8]
//Output: -1
//Explanation: 
//There is no number that occurs only once.
// 
//Note:
//1 <= A.length <= 2000
//0 <= A[i] <= 1000

namespace Solution2019
{
	namespace LargestUniqueNumber
	{
		int LargestUniqueNumber(vector<int> nums) {
			int len = nums.size();
			if (len == 0) { return -1; }
			int map[1001] = {0};

			for (int i : nums) { map[i]++; }
			for (int i = 1000; i >= 0; i--) {
				if (map[i] == 1) { return i; }
			}
			return -1;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

