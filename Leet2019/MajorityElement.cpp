#include "stdafx.h"
//Given an array of size n, find the majority element. 
//The majority element is the element that appears more than ⌊ n/2 ⌋ times.
//
//You may assume that the array is non-empty and the 
//majority element always exist in the array.
//
//Example 1:
//Input: [3,2,3]
//Output: 3
//
//Example 2:
//Input: [2,2,1,1,1,2,2]
//Output: 2 

namespace Solution2019
{
	namespace MajorityElement
	{
		int majorityElement(vector<int>& nums) {
			int halfLen = nums.size() / 2;
			int count = 0;
			int curMajor = nums[0];
			for (int i : nums) {
				if (i == curMajor) { count++; }
				else if (count == 0) { count = 1; curMajor = i; }
				else { count--; }
			}
			return curMajor;
		}
		int majorityElementWithMap(vector<int>& nums) {
			int halfLen = nums.size()/2;
			unordered_map<int, int> map;
			for (int i : nums) { 
				map[i]++; 
				if (map[i] > halfLen) { return i; }
			}
			return -1;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

