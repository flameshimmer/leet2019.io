#include "stdafx.h"
//Given an array of integers arr, write a function that 
//returns true if and only if the number of occurrences 
//of each value in the array is unique.
//
//Example 1:
//Input: arr = [1,2,2,1,1,3]
//Output: true
//Explanation: The value 1 has 3 occurrences, 2 has 2 
//and 3 has 1. No two values have the same number of occurrences.
//
//Example 2:
//Input: arr = [1,2]
//Output: false
//Example 3:
//
//Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
//Output: true
// 
//Constraints:
//1 <= arr.length <= 1000
//-1000 <= arr[i] <= 1000

namespace Solution2019
{
	namespace UniqueNumerofOccurrence
	{
		bool uniqueOccurrences(vector<int>& arr) {
			unordered_map<int, int> map1;
			for (int v : arr) { map1[v]++; }
			unordered_set<int> set1;
			for (auto& p : map1) {
				if (set1.count(p.second)) { return false; }
				set1.insert(p.second);
			}
			return true;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

