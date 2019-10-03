#include "stdafx.h"
//You are given two arrays (without duplicates) nums1 
//and nums2 where nums1’s elements are subset of nums2.
//Find all the next greater numbers for nums1's elements 
//in the corresponding places of nums2.
//
//The Next Greater Number of a number x in nums1 is the 
//first greater number to its right in nums2. If it does 
//not exist, output -1 for this number.
//
//Example 1:
//Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
//Output: [-1,3,-1]
//Explanation:
//For number 4 in the first array, you cannot find the 
//next greater number for it in the second array, so output -1.
//For number 1 in the first array, the next greater 
//number for it in the second array is 3.
//For number 2 in the first array, there is no next 
//greater number for it in the second array, so output -1.
//
//Example 2:
//Input: nums1 = [2,4], nums2 = [1,2,3,4].
//Output: [3,-1]
//Explanation:
//For number 2 in the first array, the next greater 
//number for it in the second array is 3.
//For number 4 in the first array, there is no next 
//greater number for it in the second array, so output -1.
//
//Note:
//All elements in nums1 and nums2 are unique.
//The length of both nums1 and nums2 would not exceed 1000.

namespace Solution2019
{
	namespace NextGreaterElementI
	{
		vector<int> nextGreaterElementWithStack(vector<int>& nums1, vector<int>& nums2) {
			unordered_map<int, int> map;
			stack<int> s;
			for (int v : nums2) {
				while (!s.empty() && v > s.top()) {
					map[s.top()] = v;
					s.pop();
				}
				s.push(v);
			}
			vector<int> result;
			for (int v : nums1) {
				result.push_back(map.count(v) ? map[v] : -1);
			}
			return result;
		}

		vector<int> nextGreaterElementBruteForce(vector<int>& nums1, vector<int>& nums2) {
			unordered_map<int, int> map;
			for (int i = 0; i < nums2.size(); i++) {
				map[nums2[i]] = i;
			}

			vector<int> result;
			for (int v : nums1) {
				bool found = false;
				for (int i = map[v] + 1; i < nums2.size(); i++) {
					if (nums2[i] > v) { result.push_back(nums2[i]); found = true; break; }
				}
				if (!found) { result.push_back(-1); }
			}
			return result;
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

