#include "stdafx.h"
//Given a non-empty array of non-negative integers nums, the degree
//of this array is defined as the maximum frequency of any one of its elements.
//
//Your task is to find the smallest possible length of a (contiguous)
//subarray of nums, that has the same degree as nums.
//
//Example 1:
//Input: [1, 2, 2, 3, 1]
//Output: 2
//Explanation: 
//The input array has a degree of 2 because both elements 1 and 2 appear twice.
//Of the subarrays that have the same degree:
//[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
//The shortest length is 2. So return 2.
//
//Example 2:
//Input: [1,2,2,3,1,4,2]
//Output: 6
//
//Note:
//nums.length will be between 1 and 50,000.
//nums[i] will be an integer between 0 and 49,999.

namespace Solution2019
{
	namespace DegreeofanArray
	{
		int DegreeofanArray(vector<int> A) {
			unordered_map<int, pair<int, int>> map;
			int result = 1;
			int degree = 1;
			for (int i = 0; i < A.size(); i++) {
				int v = A[i];
				if (map.find(v) == map.end()) { map[v] = make_pair(1, i); }
				else {
					map[v].first++;
					if (map[v].first > degree) {
						degree = map[v].first;
						result = i - map[v].second + 1;
					}
					else if (map[v].first == degree) {
						result = min(result, i - map[v].second + 1);
					}
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

