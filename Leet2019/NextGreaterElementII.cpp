#include "stdafx.h"

//Given a circular array (the next element of the last element is the first
//element of the array), print the Next Greater Number for every element. The
//Next Greater Number of a number x is the first greater number to its
//traversing-order next in the array, which means you could search circularly to
//find its next greater number. If it doesn't exist, output -1 for this number.
//
//Example 1:
//Input: [1,2,1]
//Output: [2,-1,2]
//Explanation: The first 1's next greater number is 2; 
//The number 2 can't find next greater number; 
//The second 1's next greater number needs to search circularly, which is also 2.
//
//Note: The length of given array won't exceed 10000.

namespace Solution2019
{
	namespace NextGreaterElementII
	{
		vector<int> nextGreaterElements(vector<int>& nums) {
			int len = nums.size();
			vector<int> result(len, -1);
			stack<int> s; //index;

			for (int i = 0; i < len * 2; i++) {
				int v = nums[i % len];
				while (!s.empty() && v > nums[s.top()]) {
					result[s.top()] = v;
					s.pop();
				}
				s.push(i % len);
			}
			return result;
		}

		vector<int> nextGreaterElementsAnother(vector<int>& nums) {
			vector<int> all = nums;
			all.insert(all.end(), nums.begin(), nums.end());
			stack<pair<int, int>> s; // index, value 
			unordered_map<int, int> map; // index, next greater value;
			for (int i = 0; i < all.size(); i++) {
				int v = all[i];
				while (!s.empty() && v > s.top().second) {
					map[s.top().first] = v;
					s.pop();
				}
				s.push({ i, v });
			}
			vector<int> result;
			for (int i = 0; i < nums.size(); i++) {
				result.push_back(map.find(i) == map.end() ? -1 : map[i]);
			}
			return result;
		}

		void Main() {
			vector<int> test = {1, 2, 1};
			print(nextGreaterElements(test));
		}
	}
}

