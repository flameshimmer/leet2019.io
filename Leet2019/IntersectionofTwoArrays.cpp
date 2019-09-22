#include "stdafx.h"
//Given two arrays, write a function to compute their intersection.
//
//Example 1:
//
//Input: nums1 = [1,2,2,1], nums2 = [2,2]
//Output: [2]
//Example 2:
//
//Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//Output: [9,4]
//Note:
//
//Each element in the result must be unique.
//The result can be in any order.

namespace Solution2019
{
	namespace IntersectionofTwoArrays
	{
		vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
			unordered_set<int> set1;
			unordered_set<int> set2;
			for (int v : nums1) { set1.insert(v); }
			for (int v : nums2) { set2.insert(v); }
			vector<int> result;
			for (int v : set1) {
				if (set2.find(v) != set2.end()) { result.push_back(v); }
			}
			return result;
		}

		vector<int> intersectionAnother(vector<int>& nums1, vector<int>& nums2) {
			unordered_set<int> set1;
			for (int v : nums1) { set1.insert(v); }
			vector<int> result;
			for (int v : nums2) {
				if (set1.find(v) != set1.end()) { result.push_back(v); set1.erase(v); }
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

