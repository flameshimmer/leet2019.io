#include "stdafx.h"
//You are given an integer array nums and you have to return a new counts array. 
//The counts array has the property where counts[i] is the number of smaller 
//elements to the right of nums[i].
//
//Example:
//Input: [5,2,6,1]
//Output: [2,1,1,0] 
//Explanation:
//To the right of 5 there are 2 smaller elements (2 and 1).
//To the right of 2 there is only 1 smaller element (1).
//To the right of 6 there is 1 smaller element (1).
//To the right of 1 there is 0 smaller element.

namespace Solution2019
{
	namespace CountofSmallerNumbersAfterSelf
	{
		void merge(vector<pair<int, int>>::iterator begin, vector<pair<int, int>>::iterator end, vector<int>& result) {
			if (end - begin <= 1) { return; }

			auto mid = begin + (end - begin) / 2;
			auto j = mid;
			merge(begin, mid, result);
			merge(mid, end, result);
			for (auto i = begin; i < mid; i++) {
				while (j < end && i->first > j->first) {
					j++;
				}
				result[i->second] += j - mid;
			}
			inplace_merge(begin, mid, end);
		}

		vector<int> countSmaller(vector<int>& nums) {
			int len = nums.size();
			vector<int> result(len);
			vector<pair<int, int>> A;
			for (int i = 0; i < len; i++) {
				A.push_back({ nums[i], i });
			}
			merge(A.begin(), A.end(), result);
			return result;
		}
		void Main() {
			vector<int> test = {5, 2, 6, 1};
			print(countSmaller(test));
		}
	}
}

