#include "stdafx.h"
//Given an array of integers where 1 ≤ a[i] ≤ n(n = size of array), some elements appear twiceand others appear once.
//
//Find all the elements of[1, n] inclusive that do not appear in this array.
//
//Could you do it without extra spaceand in O(n) runtime ? You may assume the returned list does not count as extra space.
//
//Example :
//
//	Input :
//	[4, 3, 2, 7, 8, 2, 3, 1]
//
//Output :
//	[5, 6]
//
namespace Solution2019
{
	namespace FindAllNumbersDisappearedinanArray
	{
		vector<int> findDisappearedNumbers(vector<int>& nums) {
			int len = nums.size();
			vector<int> result;
			if (len == 0) { return result; }

			for (int val : nums) {
				int index = abs(val) - 1;
				nums[index] = nums[index] > 0 ? -nums[index] : nums[index];
			}
			for (int i = 0; i < len; i++) {
				if (nums[i] > 0) { result.push_back(i + 1); }
			}
			return result;
		}

		vector<int> findDisappearedNumbersAnotherWay(vector<int>& nums) {
			vector<int> result;
			int len = nums.size();
			if (len == 0) { return result; }

			for (int i = 0; i < nums.size(); i++) {
				nums[i]--;
			}

			for (int i = 0; i < nums.size(); i++) {
				int fill = -1;
				int j = i;
				while (j >= 0 && nums[j] != j) {
					swap(nums[j], fill);
					j = fill;
				}
			}

			for (int i = 0; i < len; i++) {
				if (nums[i] < 0) { result.push_back(i + 1); }
			}
			return result;
		}
		void Main() {
			vector<int> test = { 2, 1, 1};
			print(findDisappearedNumbers(test));
		}
	}
}

