/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return[0, 1].
*/
#include "stdafx.h"
namespace Solution2019
{
	namespace TwoSum
	{
		static bool compare(const pair<int, int>& p1, const pair<int, int>& p2)
		{
			return p1.first < p2.first;
		}
		vector<int> TwoSumSortFirst(vector<int> nums, int target) {
			vector<int> result;
			if (nums.size() < 2) { return result; }

			vector<pair<int, int>> newArray;
			for (int i = 0; i < nums.size(); i++)
			{
				newArray.push_back(make_pair(nums[i], i));
			}
			sort(newArray.begin(), newArray.end(), compare);

			int start = 0;
			int end = nums.size() - 1;
			while (start < end) {
				int sum = newArray[start].first + newArray[end].first;
				if (sum == target) {
					result.push_back(newArray[start].second);
					result.push_back(newArray[end].second);
					break;
				}
				else if (sum < target) { start++; }
				else { end--; }
			}
			return result;
		}
		
		vector<int> TwoSum(vector<int> nums, int target)
		{
			vector<int> result;
			int len = nums.size();
			if (len < 2) { return result; }

			unordered_map<int, int> map;
			for (int i = 0; i < len; i++) {
				int curTarget = target - nums[i];
				if (map.find(curTarget) != map.end()) {
					result.push_back(map[curTarget]);
					result.push_back(i);					
				}
				map[nums[i]] = i;
			}
			return result;
		}


		void Main() {
			vector<int> nums = {3, 2, 4};
			
			print(TwoSum(nums, 6));
		}
	}
}