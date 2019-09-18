#include "stdafx.h"
//Given a non-empty array of integers, return the third maximum number 
//in this array. If it does not exist, return the maximum number. 
//The time complexity must be in O(n).
//
//Example 1:
//Input: [3, 2, 1]
//Output: 1
//Explanation: The third maximum is 1.
//
//Example 2:
//Input: [1, 2]
//Output: 2
//Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
//
//Example 3:
//Input: [2, 2, 3, 1]
//Output: 1
//Explanation: Note that the third maximum here means the third maximum distinct number.
//Both numbers with value 2 are both considered as second maximum.

namespace Solution2019
{
	namespace ThirdMaximumNumber
	{
		int thirdMax(vector<int>& nums) {
			set<int> set;
			for (int v : nums) {
				set.insert(v);
				if (set.size() > 3) { set.erase(set.begin()); }
			}
			return set.size() == 3 ? *set.begin() : *set.rbegin();
		}
		
		int thirdMaxAnother(vector<int>& nums) {
			int len = nums.size();
			unordered_set<int> set;
			int maxV = nums[0];
			for (int v : nums) { set.insert(v); maxV = max(maxV, v); }
			if (set.size() < 3) { return maxV; }

			int max1 = INT_MIN;
			int max2 = INT_MIN;
			int max3 = INT_MIN;
			for (int v : set) {
				if (v > max1) {
					max3 = max2;
					max2 = max1;
					max1 = v;
				}
				else if (v > max2) {
					max3 = max2;
					max2 = v;
				}
				else if (v > max3) {
					max3 = v;
				}
			}
			return max3;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

