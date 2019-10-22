#include "stdafx.h"
//Find the kth largest element in an unsorted array. Note that it is the
//kth largest element in the sorted order, not the kth distinct element.
//
//Example 1:
//
//Input: [3,2,1,5,6,4] and k = 2
//Output: 5
//Example 2:
//
//Input: [3,2,3,1,2,4,5,5,6] and k = 4
//Output: 4
//Note:
//You may assume k is always valid, 1 ≤ k ≤ array's length.

namespace Solution2019
{
	namespace KthLargestElementinanArray
	{
		int partition(vector<int>& nums, int start, int end, int pivot) {
			int pV = nums[start + pivot];
			swap(nums[start + pivot], nums[end]);

			int copy = start;
			for (int i = start; i <= end; i++) {
				if (nums[i] < pV) {
					swap(nums[copy], nums[i]);
					copy++;
				}
			}
			swap(nums[copy], nums[end]);

			if (copy - start == pivot) { return nums[copy]; }
			else if (copy - start < pivot) {
				return partition(nums, copy + 1, end, pivot - (copy - start + 1));
			}
			else {
				return partition(nums, start, copy - 1, pivot);
			}

		}

		int findKthLargest(vector<int>& nums, int k) {
			int len = nums.size();
			if (len < k) { return -1; }
			return partition(nums, 0, len - 1, len - k);
		}


		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}

